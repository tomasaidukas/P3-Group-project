#!/usr/bin/gnuplot
#
# Plots the Potential graphs from the output of the Numerical Solution
#
#-------------------------#
# POTENTIAL #
#-------------------------#
set output "Plots/Vnumerical.png"
set terminal png
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black")
plot "PotentialField/Vnumerical.txt" with image
set output "Plots/Vanalytical.png"
set terminal png
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black", 1 "orange", 5 "sandybrown", 10 "red")
plot "PotentialField/Vanalytical.txt" with image
set output "Plots/VnumCircle.png"
set terminal png
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black", 1 "orange", 5 "sandybrown", 10 "red")
plot "PotentialField/VnumCircle.txt" with image
set output "Plots/Vdifference.png"
set terminal png
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black", 1 "orange", 5 "sandybrown", 10 "red")
plot "PotentialField/Vdifference.txt" with image
set output "Plots/Vratio.png"
set terminal png
set palette defined (0 "black", 0.01 "white", 0.1 "blue")
plot "PotentialField/Vratio.txt" with image

set isosample 250,250
set table "Plots/Potential.dat"
splot "PotentialField/VnumCircle.txt"
unset table
set contour base
set cntrparam level incremental -50, 5, 50 #these depend on the problem voltage dimensions
unset surface
set table "Plots/Lines.dat"
splot "PotentialField/VnumCircle.txt"
unset table
reset
unset key
set terminal png
set output "Plots/Vequipotential.png"
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black", 1 "orange", 5 "sandybrown", 10 "red")
plot "Plots/Potential.dat" with image, "Plots/Lines.dat" with l lt -1 lw 0.5


set isosample 250,250
set table "Plots/Potential.dat"
splot "PotentialField/Vnumerical.txt"
unset table
set contour base
set cntrparam level incremental -10, 0.3, 10 #these depend on the problem voltage dimensions
unset surface
set table "Plots/Lines.dat"
splot "PotentialField/Vnumerical.txt"
unset table
reset
unset key
set terminal png
set output "Plots/VequipotentialB.png"
set palette defined (-10 "blue", -5 "cyan", -1 "turquoise", 0 "black")
plot "Plots/Potential.dat" with image, "Plots/Lines.dat" with l lt -1 lw 0.5

exit
