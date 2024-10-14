all: questao12.o questao22.o
	gcc questao12.o questao22.o main.c -o main

questao12.o: questao12.h questao12.c 
	gcc -c questao12.c

questao22.o: questao22.h questao22.c 
	gcc -c questao22.c

clean:
	rm -f questao12.o questao22.o main