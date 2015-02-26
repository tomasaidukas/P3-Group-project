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

exit
