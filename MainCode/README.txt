This is the code structure so far:

Mesh class is completed and doesn't need any fixing.

Parent class is TopAlg. It holds most of the functions and variables required for other classes, which inherit from it.

Analytic and Algorithm are the ingeritance (?) classes. They only have functions which create boundary conditions on the meshes.

Most of the problems I raised here I fixed myself, since no one reads it anyway. Now the code works fine. Just need to create the comparinson tests.
