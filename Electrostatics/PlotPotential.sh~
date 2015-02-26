#!/usr/bin/gnuplot
#
# Plots the Potential graphs from the output of the Numerical Solution
#
#-------------------------#
# POTENTIAL #
#-------------------------#
set output "Plots/Vnumerical.png"
set terminal png
set pm3d map
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black")
splot "PotentialField/Vnumerical.txt" matrix
set output "Plots/Vanalytical.png"
set terminal png
set pm3d map
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black", 1 "orange", 5 "sandybrown", 10 "red")
splot "PotentialField/Vanalytical.txt" matrix
set output "Plots/VnumCircle.png"
set terminal png
set pm3d map
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black", 1 "orange", 5 "sandybrown", 10 "red")
splot "PotentialField/VnumCircle.txt" matrix
set output "Plots/Vdifference.png"
set terminal png
set pm3d map
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black", 1 "orange", 5 "sandybrown", 10 "red")
splot "PotentialField/Vdifference.txt" matrix


exit
