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
	The function setEdges() should remove the zeros from the edges by setting them equal to the neighbourh values. If this is not done, then the algorithm "sees" the edges as plates at 0 potential and plots weird results. The plots produced at the moment ar relatively OK (you can see some crap around the edges), but if the plates were plotted not at the top and bottom, but at the sides it would produce poor results. Therefore, someone could check that function and see how it can be fixed. You can also see blank edges in the plots and I believe the problems are due to that. 

	Another solution for the above problem could be solved just by taking away 2 or 3 pixels away from all the edges and not touching them when we calculate the potential.
	
Problem number 2:
	Ovidiu uploaded the code for equipotentials, which requires different format than what we are using now. It would be nice to decide on a standard format used for the output files.
	
