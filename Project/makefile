#compiler to use
CC=g++	

#object files
obj=main.o mesh.o algorithm.o shape.o

#header files
headers=main.h mesh.h algorithm.h shape.h

main : $(obj)
	$(CC) -o $@ $^ -lm

%.o : %.c $(headers)
	$(CC) -c -g $<

.PHONY : clean

clean :
	rm $(obj)