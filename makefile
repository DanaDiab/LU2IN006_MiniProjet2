all:main

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h
	gcc -Wall -c entreeSortieLC.c -o entreeSortieLC.o

biblioLC.o : biblioLC.c biblioLC.h
	gcc -Wall -c biblioLC.c -o biblioLC.o

main.o: main.c entreeSortieLC.h biblioLC.h
	gcc -Wall -c main.c -o main.o

main: main.o entreeSortieLC.o biblioLC.o
	gcc -Wall -o main main.o entreeSortieLC.o biblioLC.o

test_mainH.o: test_mainH.c biblioH.h
	gcc -Wall -c test_mainH.c  -o test_mainH.o
	
biblioH.o: biblioH.c biblioH.h
	gcc -Wall -c biblioH.c -o biblioH.o
	
test_mainH: test_mainH.o biblioH.o
	gcc -Wall -o test_mainH test_mainH.o biblioH.o
	

	

