#!/usr/bin/gnuplot

set terminal png
set output "Analyze/iterations.png"
set title "Iterations vs Mesh size"
set xlabel "X"
set ylabel "Y"
plot "Analyze/VcompIterations.txt" with lines