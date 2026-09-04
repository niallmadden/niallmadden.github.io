#!/bin/bash
# Generate thumbnails + index.html using PDF metadata titles
# Sections:
#   - Slides: [0-9]*.pdf
#   - Annotations: [0-9]*.pdf.pdf
#   - Tutorials and Labs: MA385-Tutorial-*.pdf / MA385-Lab-*.pdf
# Uses index_head.html for the HTML <head> and beginning of <body>

command -v pdftoppm >/dev/null 2>&1 || { 
  echo "Error: pdftoppm (poppler-utils) not installed. Run: sudo apt-get install poppler-utils"
  exit 1
}
command -v pdfinfo >/dev/null 2>&1 || { 
  echo "Error: pdfinfo (poppler-utils) not installed. Run: sudo apt-get install poppler-utils"
  exit 1
}

mkdir -p thumbs

# === Generate thumbnails ===
for f in *.pdf; do
    base="${f%.pdf}"
    if [ ! -f "thumbs/$base.png" ]; then
        echo "Creating thumbnail for $f..."
        pdftoppm -png -scale-to 200 -f 1 -singlefile "$f" "thumbs/$base"
    fi
done

# === Start HTML with custom head ===
if [ ! -f index_head.html ]; then
  echo "Error: index_head.html not found!"
  exit 1
fi
cat index_head.html > index.html

# === Helper function: add section ===
add_section () {
    local title="$1"
    local id="$2"
    shift 2
    local files=("$@")

    echo "  <h1 id=\"$id\">$title</h1>" >> index.html
    echo "  <div class=\"grid\">" >> index.html

    for f in "${files[@]}"; do
        [ -e "$f" ] || continue
        base="${f%.pdf}"
        # Extract Title metadata, strip subtitle after " - "
        pdf_title=$(pdfinfo "$f" | grep '^Title:' | sed 's/^Title:[[:space:]]*//' | sed 's/ - .*//')
        if [ -z "$pdf_title" ]; then
            pdf_title="$f"
        fi
        echo "    <div class=\"item\"><a href=\"$f\"><img src=\"thumbs/$base.png\" alt=\"$f\"><div class=\"label\">$pdf_title</div></a></div>" >> index.html
    done

    echo "  </div>" >> index.html
}

# === Collect file lists ===
slides=( [0-9]*.pdf )
annotations=( [0-9]*.pdf.pdf )
tutorials=( MA385-Tutorial-*.pdf MA385-Lab-*.pdf )

# === Add sections ===
add_section "Slides" "slides" "${slides[@]}"
add_section "Annotations" "annotations" "${annotations[@]}"
add_section "Tutorials and Labs" "sheets" "${tutorials[@]}"

# === Footer ===
cat >> index.html <<'EOF'
</body>
</html>
EOF

echo "✅ index.html generated. Open it in your browser!"
