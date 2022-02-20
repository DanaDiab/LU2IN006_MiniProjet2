all:main test_mainLC test_mainH main_temps_recherche vitesse_plusieurs_exemplaires

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h
	gcc -Wall -c entreeSortieLC.c -o entreeSortieLC.o
	
entreeSortieH.o: entreeSortieH.c entreeSortieH.h
	gcc -Wall -c entreeSortieH.c -o entreeSortieH.o

biblioLC.o : biblioLC.c biblioLC.h
	gcc -Wall -c biblioLC.c -o biblioLC.o

main.o: main.c entreeSortieLC.h biblioLC.h
	gcc -ggdb -Wall -c main.c -o main.o

main: main.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o
	gcc -ggdb -Wall -o main main.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o -lm
	
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
	
main_temps_recherhce.o: main_temps_recherche.c entreeSortieLC.h biblioLC.h entreeSortieH.h biblioH.h
	gcc -Wall -c main_temps_recherche.c -o main_temps_recherche.o -lm

main_temps_recherche: main_temps_recherche.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o
	gcc -Wall -o main_temps_recherche main_temps_recherche.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o -lm

vitesse_plusieurs_exemplaires.o: vitesse_plusieurs_exemplaires.c entreeSortieLC.h biblioLC.h entreeSortieH.h biblioH.h
	gcc -Wall -c vitesse_plusieurs_exemplaires.c -o vitesse_plusieurs_exemplaires.o -lm

vitesse_plusieurs_exemplaires: vitesse_plusieurs_exemplaires.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o
	gcc -Wall -o vitesse_plusieurs_exemplaires vitesse_plusieurs_exemplaires.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o -lm

	

	

