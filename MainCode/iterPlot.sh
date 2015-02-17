#!/usr/bin/gnuplot

set terminal png
set output "Analyze/iterations.png"
set title "Iterations vs Mesh size (square)"
set xlabel "Mesh size (square dim)"
set ylabel "Iteration number"
plot "Analyze/VcompIterations.txt" with lines


set terminal png
set output "Analyze/time.png"
set title "Time vs Mesh size (square)"
set xlabel "Mesh size (square dim)"
set ylabel "Time"
plot "Analyze/VcompTime.txt" with lines