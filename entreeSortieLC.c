
#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieLC.h"
#include "biblioLC.h"

Biblio* charger_n_entrees(char* nomfic, int n){
	char buffer[256]; int i=0;
	char auteur[256], titre[256]; int num;
	Biblio* biblio=creer_biblio();
	FILE* fichier=fopen(nomfic,"r");
	while (i<n && (fgets(buffer,256,fichier)!=NULL)){
		i++;
		sscanf(buffer,"%d %s %s\n",&num,titre,auteur);
		inserer_en_tete(biblio,num,titre,auteur);
		}
	fclose(fichier);
	return biblio;
	}
	
void enregistrer_biblio(Biblio *b, char* nomfic)
{
	if(b->L ==NULL)return;
	
	FILE *fichier = fopen(nomfic, "w");
	Livre *prc = b->L;
	while(prc)
	{
		fprintf(fichier, "%d %s %s\n", prc->num, prc->titre, prc->auteur);
		prc=prc->suiv;
	}
	fclose(fichier);
}
