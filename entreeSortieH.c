#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieH.h"
#include "biblioH.h"

BiblioH* charger_n_entrees_H(char* nomfic, int n){
  	char buffer[256]; int i=0;
	char auteur[256];
	char titre[256]; int num;
	BiblioH* biblio=creer_biblio_H(n);
	FILE* fichier=fopen(nomfic,"r");
	while ((fgets(buffer,256,fichier)!=NULL) && (i<n)){
		i++;
		sscanf(buffer," %d %s %s\n",&num,titre,auteur);
		inserer(biblio,num,titre,auteur);
		}
	fclose(fichier);
	return biblio;
}


void enregistrer_biblioH(BiblioH *b, char* nomfic){
	FILE *fichier = fopen(nomfic, "w");
  for (int i=0;i<b->m;i++){
	   LivreH *prc = b->T[i];
	    while(prc){
		       fprintf(fichier, "%d %s %s\n", prc->num, prc->titre, prc->auteur);
		       prc=prc->suiv;
	    }
  }
	fclose(fichier);
}
