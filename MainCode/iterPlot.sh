#!/usr/bin/gnuplot

#set terminal png
#set output "Analyze/iterations.png"
#set title "Iterations vs Mesh size (square)"
#set xlabel "Mesh size (square dim)"
#set ylabel "Iteration number"
#plot "Analyze/VcompIterations.txt" with lines


#set terminal png
#set output "Analyze/time.png"
#set title "Time vs Mesh size (square)"
#set xlabel "Mesh size (square dim)"
#set ylabel "Time (s)"
#plot "Analyze/VcompTime.txt" with lines


set terminal png
set output "Analyze/tolIter.png"
set title "Tolerance vs Iterations"
set xlabel "Tolerance"
set ylabel "Iterations"
plot "Analyze/VcompTolerance.txt" with lines


set terminal png
set output "Analyze/tolError.png"
set title "Tolerance vs Average Potential Difference %"
set ylabel "Average Potential Difference %"
set xlabel "Tolerance"
plot "Analyze/VcompError.txt" with lines

set terminal png
set output "Analyze/tolTime.png"
set title "Tolerance vs Time %"
set ylabel "Time (s)"
set xlabel "Tolerance"
plot "Analyze/VcompTolTime.txt" with lines
