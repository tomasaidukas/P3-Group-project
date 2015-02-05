#compiler to use
CC=g++	

#object files
obj=main.o mesh.o algorithm.o

#header files
headers=main.h mesh.h algorithm.h CImg.h
#libraries
lib=-L/opt/X11/lib -lX11 -pthread -lm

main : $(obj)
	$(CC) -o $@ $^ -g $(lib)

%.o : %.c $(headers)
	$(CC) -c -g $<

.PHONY : clean

clean :
	rm $(obj)
