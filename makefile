all:main

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h
	gcc -Wall -c entreeSortieLC.c -o entreeSortieLC.o

biblioLC.o : biblioLC.c biblioLC.h
	gcc -Wall -c biblioLC.c -o biblioLC.o

entreeSortieH.o : entreeSortieH.c entreeSortieH.h
	gcc -Wall -c entreeSortieH.c -o entreeSortieH.o

biblioH.o : biblioH.c biblioH.h
	gcc -Wall -c biblioH.c -o biblioH.o -lm

main.o: main.c entreeSortieLC.h biblioLC.h entreeSortieH.h biblioH.h
	gcc -Wall -c main.c -o main.o

main: main.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o
	gcc -Wall -o main main.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o -lm


	

