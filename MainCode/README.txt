Text files and images go to the corresponding folders to make less of a mess.

I wrote explanations for each functions and made the format more easily readable.

To run the code and get all the data simply use type "make", then ./main. It will plot the results
as well automatically and put them to the Plots folder.

ROOT is used for equipotentials and vectors, while GNUPLOT is used for the potential field.

Also, use tolerance = 0.001 and not 0.01. The latter produce good results for large voltages of the order of 1000V and higher, but for lowe voltages such as 10V the tolerance of 0.001 has to be used.





