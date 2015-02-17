#!/usr/bin/gnuplot
#
# Plots Electric Field graphs from the output of the Numerical Solution
#

#-------------------------#
#   ELECTRIC FIELD        #
#-------------------------#

set terminal png
set output "ElectricField/Enumfield.png"
set size square
plot "ElectricField/Enumerical.txt" with vectors

set terminal png
set output "ElectricField/Eanalfield.png"
set size square
plot "ElectricField/EnumCircle.txt" with vectors

exit