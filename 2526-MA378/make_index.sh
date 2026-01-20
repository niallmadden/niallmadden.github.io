#!/bin/bash
# Generate thumbnails + index.html using PDF metadata titles
# Sections:
#   - Slides: [0-9]*.pdf  (only files that end exactly in .pdf, not .pdf.pdf)
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

# Make globs expand to empty list when no matches
shopt -s nullglob

# === Generate thumbnails ===
for f in *.pdf; do
    # skip if no .pdf files at all (nullglob makes pattern disappear)
    [ -e "$f" ] || continue
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
        pdf_title=$(pdfinfo "$f" 2>/dev/null | grep '^Title:' | sed 's/^Title:[[:space:]]*//' | sed 's/ - .*//')
        if [ -z "$pdf_title" ]; then
            pdf_title="$f"
        fi
        # Escape angle brackets in title to avoid breaking HTML
        pdf_title=$(printf '%s' "$pdf_title" | sed 's/[<>]/\\&/g')
        echo "    <div class=\"item\"><a href=\"$f\"><img src=\"thumbs/$base.png\" alt=\"$f\"><div class=\"label\">$pdf_title</div></a></div>" >> index.html
    done

    echo "  </div>" >> index.html
}

# === Collect file lists: filtered to avoid .pdf.pdf in slides ===
slides=()
for f in [0-9]*.pdf; do
    [ -e "$f" ] || continue
    # skip files that actually end in .pdf.pdf
    if [[ "$f" == *.pdf.pdf ]]; then
        continue
    fi
    slides+=("$f")
done

annotations=()
for f in [0-9]*.pdf.pdf; do
    [ -e "$f" ] || continue
    annotations+=("$f")
done

tutorials=()
for f in MA385-*.pdf; do
    [ -e "$f" ] || continue
    tutorials+=("$f")
done

# === Add sections ===
add_section "Slides" "slides" "${slides[@]}"
add_section "Annotations" "annotations" "${annotations[@]}"
add_section "Tutorials and Assignments" "sheets" "${tutorials[@]}"

# === Footer ===
cat >> index.html <<'EOF'
</body>
</html>
EOF

echo "✅ index.html generated. Open it in your browser!"
