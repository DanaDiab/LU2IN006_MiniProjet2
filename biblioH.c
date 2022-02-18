#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"

/*________________________ASSOCIATION_DE_CLEF________________*/
int fonctionClef(char* auteur)
{
	int i = 0;
	int res = 0;
	if(auteur!=NULL)
	{
		while(auteur[i]!='\0')
		{
			res += auteur[i]; //On ajoute la valeur de auteur[i] au resultat
			i = i+1;
		}
		return res;
	}
	return -1; //retourne -1 en cas de pointeur null
	
}

/*________________________CREE_LIVRE_H_______________*/

LivreH *creer_livre(int num, char* titre, char* auteur)
{
	LivreH * new_livreH = (LivreH*)malloc(sizeof(LivreH));
	if (new_livreH==NULL)
	{
		return NULL;
	}
	new_livreH->clef=fonctionClef(auteur);
	new_livreH->num=num;
	new_livreH->titre = strdup(titre);
	new_livreH->auteur = strdup(auteur);
	return new_livreH;
}

/*______________________CREER_BIBLIO_H_______________*/

BiblioH* creer_biblio(int taille)
{
	BiblioH *biblioh = (BiblioH*)malloc(sizeof(BiblioH));
	biblioh->nE=0;
	biblioh->m=taille;
	biblioh->T=(LivreH**)(malloc(sizeof(LivreH*)*taille);
	return biblioh;
}

/*_____________________LIBERE_LIVRE_H_________________*/

void liberer_livre(LivreH* lh)
{
		free(lh->titre);
		free(lh->auteur);
		free(lh);
}

/*_______________________AFFICHAGE_LIVRE_H_____________*/

void afficher_livre(LivreH *l)
{
	if (l!=NULL)
	{
		printf("Clef : %d, Numero : %d , Titre: %s , Auteur: %s\n",l->clef, l->num,l->titre, l->auteur);
	}
}

/*________________________LIBERER_BIBlIO_H_______________*/
void liberer_blbio(BiblioH* b){
	for (int i=0;i<b->m;i++){
		liberer_livre(b->T[i]);
	}
	free(b->T);
	free(b);
}



