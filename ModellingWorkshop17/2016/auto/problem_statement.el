(TeX-add-style-hook
 "problem_statement"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "a4paper" "11pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("geometry" "margin={2.5cm, 2.5cm, 2.5cm, 2.5cm}")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art11"
    "color"
    "eurosym"
    "graphicx"
    "subfigure"
    "geometry"
    "float")
   (TeX-add-symbols
    "beq"
    "eeq"
    "bef"
    "enf"
    "p"
    "f"
    "ig")
   (LaTeX-add-bibliographies))
 :latex)

