#!/usr/bin/gnuplot


set terminal png
set output "Plots/CPU.png"
set title "CPU usage"
set xlabel "Time (ms)"
set ylabel "CPU (%)"
plot "cputime.txt" with lines
