#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"

int main(int argc, char* argv[]){
	
	double temps_lc=0,temps_h=0;
	double t_lc_init,t_lc_fin;
	double t_h_init,t_h_fin;

	FILE * fichier=fopen("sortie_vitesse.txt","w");
	if (fichier==NULL){
		printf("Erreur lors de l'ouverture du fichier \n");
		return -1;
	}

	for (int n=1000; n<30000; n++){
		Biblio* blc = charger_n_entrees(argv[1], n);
		BiblioH* bh = charger_n_entrees_H(argv[1], n);
		temps_lc=0;
		temps_h=0;
		t_lc_init=clock();
		plusieurs_exemplaires(blc);
		t_lc_fin=clock();
		t_h_init=clock();
		plusieurs_exemplaires_H(bh);
		t_h_fin=clock();
		temps_lc=((double)(t_lc_fin-t_lc_init))/CLOCKS_PER_SEC;
		temps_h=((double)(t_h_fin-t_h_init))/CLOCKS_PER_SEC;
		fprintf(fichier,"%d %lf %lf\n",n,temps_lc, temps_h);
		liberer_biblio(blc);
		liberer_biblio_H(bh);
	}
	
	fclose(fichier);

	return 0;
}
	
	
