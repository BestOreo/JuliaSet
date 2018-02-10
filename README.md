# JuliaSet
A Julia Set is a construction from complex math that can be used to generate a wide range of fractal patterns, with the chaotic property: very small changes in the initial conditions lead to dramatic changes in the generated shape. A standard Linux tool, gnuplot, is capable of plotting a Julia Set from a simple text script and we have provided you with the basis of this script as the attached file "shape_template.txt".<br/>
### Linux:
* sudo apt-get install gnuplot-x11
* gcc ./q1_julia_explorer.c -o q1_julia_explorer
* ./q1_julia_explorer shape_template.txt 35.999 63.9090 | gnuplot -p
