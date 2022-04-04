#!/bin/bash
for f in *.tex;
do
   echo "Pandocing " "$f" 
   pandoc -f latex --mathjax --lua-filter=dollar-math.lua -t html "$f" -s -o "${f%.tex}.html";
done
