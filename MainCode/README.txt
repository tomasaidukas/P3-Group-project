This is the code structure so far:

Mesh class is completed and doesn't need any fixing.

Parent class is TopAlg. It holds most of the functions and variables required for other classes, which inherit from it.

Analytic and Algorithm are the ingeritance (?) classes. They only have functions which apply certain algorithms on the meshes.

For example the Algorithm::runAlgorithm() and Algorithm::setBoundary() set the boundaries from an image and use the standard algorithm to find the potential.

The Analytical::setBoundary uses the boundaries from the used to define the parameters of the circle between the plates, the distance between the plates and the potential. Analytical::runAlgorithm() uses our derived expression for the potential to calculate it and put into an array.
Analytical::runNumerical() uses the numerical method to calculate the potential of a disk between the plates placed in the middle.

SO, in the main.cpp three classes are created each executing these three different algorithm and then plotting the difference between numerical and analytical. In the end we get 4 png files whose name starts with V. So you can check how they look after running the algorithm together with ./numPlot. 

However! There are some problems:

Problem number 1:
	The numerical solution for the circle in the middle is kind of working. However, at the bottom of the plot there are some mysterious zero potetial waves and spots. The algorithm used is copied from algorithm.cpp, which works properly. There must be something with the boundary conditions maybe, but they are also seem to be in place. If someone could find the source of that error it would be great. Check the analytical.cpp file.
