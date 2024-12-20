(TeX-add-style-hook
 "Stokes2017Ranking"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "a4paper" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("geometry" "margin=1in")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "amsmath"
    "graphicx"
    "epstopdf"
    "relsize"
    "bigints"
    "setspace"
    "titlesec"
    "geometry"
    "subcaption"
    "multirow"))
 :latex)

