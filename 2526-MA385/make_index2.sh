#!/bin/bash
# Generate thumbnails + index.html using PDF metadata titles
# - Normal PDFs (*.pdf but not *.pdf.pdf)
# - Annotated slides (*.pdf.pdf)

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

# === HTML header ===
cat > index.html <<'EOF'
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <link rel="icon" type="image/x-icon" href="favicon.ico">

  <title>MA385 Index with Thumbnails</title>
  <style>
    body { font-family: sans-serif; max-width: 900px; margin: 40px auto; line-height: 1.6; }
    h1, h2 { text-align: center; }
    .grid {
      display: grid;
      grid-template-columns: repeat(auto-fill, minmax(150px, 1fr));
      gap: 20px;
      margin-bottom: 40px;
    }
    .item { text-align: center; }
    img {
      max-width: 100%;
      height: auto;
      border: 1px solid #ccc;
      border-radius: 6px;
      box-shadow: 2px 2px 5px rgba(0,0,0,0.1);
    }
    a { text-decoration: none; color: #0066cc; }
    a:hover { text-decoration: underline; }
    .label { margin-top: 6px; font-size: 0.9em; }
  </style>
</head>
<body>
  <h1>MA385 Files</h1>
EOF

# === Normal PDFs ===
echo "  <h2>Slides</h2>" >> index.html
echo "  <div class=\"grid\">" >> index.html

for f in *.pdf; do
    # Skip annotated slides (*.pdf.pdf)
    if [[ "$f" == *.pdf.pdf ]]; then continue; fi
    base="${f%.pdf}"
    title=$(pdfinfo "$f" | grep '^Title:' | sed 's/^Title:[[:space:]]*//' )
    if [ -z "$title" ]; then
        title="$f"
    fi
    echo "    <div class=\"item\"><a href=\"$f\"><img src=\"thumbs/$base.png\" alt=\"$f\"><div class=\"label\">$title</div></a></div>" >> index.html
done

echo "  </div>" >> index.html

# === Annotated PDFs ===
echo "  <h2>Annotated Slides</h2>" >> index.html
echo "  <div class=\"grid\">" >> index.html

for f in *.pdf.pdf; do
    base="${f%.pdf}"
    title=$(pdfinfo "$f" | grep '^Title:' | sed 's/^Title:[[:space:]]*//' )
    if [ -z "$title" ]; then
        title="$f"
    fi
    echo "    <div class=\"item\"><a href=\"$f\"><img src=\"thumbs/$base.png\" alt=\"$f\"><div class=\"label\">$title</div></a></div>" >> index.html
done

echo "  </div>" >> index.html

# === HTML footer ===
cat >> index.html <<'EOF'
</body>
</html>
EOF

echo "✅ index.html generated. Open it in your browser!"
