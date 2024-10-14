all: questao23.o lse.o
	gcc questao23.o lse.o main.c -o main

questao23.o: questao23.h questao23.c 
	gcc -c questao23.c

lse.o: lse.h lse.c 
	gcc -c lse.c

clean:
	rm -f questao23.o lse.o main