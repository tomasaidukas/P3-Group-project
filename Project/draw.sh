set term postscript
set output "image.eps"
set pm3d map
set palette defined (0 "black", 0.06 "red", 0.1 "yellow")
splot "Potential_Values.txt" matrix
