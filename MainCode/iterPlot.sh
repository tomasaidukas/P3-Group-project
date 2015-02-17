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


set terminal png
set output "Analyze/tolerance.png"
set title "Tolerance vs Iterations"
set xlabel "Tolerance"
set ylabel "Iterations"
plot "Analyze/VcompTolerance.txt" with lines


set terminal png
set output "Analyze/error.png"
set title "Tolerance vs Error (Max difference)"
set ylabel "Error (Max difference)"
set xlabel "Tolerance"
plot "Analyze/VcompError.txt" with lines