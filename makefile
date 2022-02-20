all:main

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h
	gcc -Wall -c entreeSortieLC.c -o entreeSortieLC.o
	
entreeSortieH.o: entreeSortieH.c entreeSortieH.h
	gcc -Wall -c entreeSortieH.c -o entreeSortieH.o

biblioLC.o : biblioLC.c biblioLC.h
	gcc -Wall -c biblioLC.c -o biblioLC.o

main.o: main.c entreeSortieLC.h biblioLC.h
	gcc -ggdb -Wall -c main.c -o main.o

main: main.o entreeSortieLC.o biblioLC.o
	gcc -ggdb -Wall -o main main.o entreeSortieLC.o biblioLC.o
	
test_mainLC.o: test_mainLC.c entreeSortieLC.h biblioLC.h
	gcc -ggdb -Wall -c test_mainLC.c -o test_mainLC.o

test_mainLC: test_mainLC.o entreeSortieLC.o biblioLC.o
	gcc -ggdb -Wall -o test_mainLC test_mainLC.o entreeSortieLC.o biblioLC.o

test_mainH.o: test_mainH.c biblioH.h entreeSortieH.h
	gcc -Wall -c test_mainH.c  -o test_mainH.o
	
biblioH.o: biblioH.c biblioH.h
	gcc -Wall -c biblioH.c -o biblioH.o
	
test_mainH: test_mainH.o biblioH.o entreeSortieH.o
	gcc -Wall -o test_mainH test_mainH.o biblioH.o entreeSortieH.o -lm
	

	

	

