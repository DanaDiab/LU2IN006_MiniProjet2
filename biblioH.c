#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

LivreH *creer_livre_H(int num, char* titre, char* auteur)
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
	new_livreH->suiv =NULL;
	return new_livreH;
}

/*______________________CREER_BIBLIO_H_______________*/

BiblioH* creer_biblio_H(int taille)
{
	BiblioH *biblioh = (BiblioH*)malloc(sizeof(BiblioH));
	biblioh->nE=0;
	biblioh->m=taille;
	biblioh->T=(LivreH**)(malloc(sizeof(LivreH*)*taille));
	for (int i=0;i<biblioh->m;i++) biblioh->T[i]=NULL;
	return biblioh;
}

/*_____________________LIBERER_LIVRE_H_________________*/

void liberer_livre_H(LivreH* l)
{
	free(l->titre);
	free(l->auteur);
	free(l);
}

/*________________________LIBERER_BIBlIO_H_____________*/
void liberer_biblio_H(BiblioH* b){
	for (int i=0;i<b->m;i++){
		LivreH* ptr=b->T[i];
		while (ptr){
			ptr=b->T[i]->suiv;
			liberer_livre_H(b->T[i]);
			b->T[i]=ptr;
		}
	}
	free(b->T);
	free(b);
}

/*_______________________FONCTION_HACHAGE______________*/
int fonctionHachage(int cle, int m){
	double a=((sqrt(5)-1.0)/(double)2.0);
	int inf_ka=floor(cle*a);
	double ka=cle*a;
	double res=m*(ka-inf_ka);
	return floor(res);
}

/*________________________INSERER_______________________*/
void inserer(BiblioH* b , int num, char* titre,char* auteur){
	LivreH* l=creer_livre_H(num,titre,auteur);
	int pos=fonctionHachage(l->clef,b->m);
	l->suiv=(b->T)[pos];
	(b->T)[pos]=l;
	b->nE++;
}

/*_______________________AFFICHAGE_LIVRE_H_____________*/

void afficher_livre_H(LivreH *l)
{

	if (l!=NULL)
	{
		printf("Clef : %d, Numero : %d , Titre: %s , Auteur: %s\n",l->clef, l->num,l->titre, l->auteur);
	}
}

/*_______________________AFFICHAGE_BIBLIO_____________*/
void afficher_biblio_H(BiblioH * b){
	for (int i=0;i<b->m;i++){
			LivreH* ptr=b->T[i];
			while (ptr){
				afficher_livre_H(ptr);
				ptr=ptr->suiv;
			}
	}
}

/*______________________RECHERCHE_PAR_NUM_H___________*/
LivreH* recherche_par_num_H(BiblioH* b, int num){
	LivreH* ptr=NULL;
	for (int i=0;i<b->m;i++){
			ptr=b->T[i];
			while (ptr!=NULL){
				if (ptr->num==num){
					return ptr;
				}
				ptr=ptr->suiv;
			}
	}
	return ptr;
}

/*_____________________RECHERCHE_PAR_TITRE_H__________*/
LivreH* recherche_par_titre_H(BiblioH* b, char* titre){
	LivreH* ptr=NULL;
	for (int i=0;i<b->m;i++){
			ptr=b->T[i];
			while (ptr!=NULL){
				if (strcmp(ptr->titre,titre)==0){
					return ptr;}
				ptr=ptr->suiv;
			}
	}
	return ptr;
}

/*______________________RECHERCHE_PAR_AUTEUR___________*/
BiblioH* recherche_par_auteur_H(BiblioH* b, char* auteur){
	BiblioH* res=creer_biblio_H(b->m);
	int c=fonctionClef(auteur);
	int pos=fonctionHachage(c,b->m);
	LivreH* ptr=b->T[pos];
	while (ptr!=NULL){
		if (strcmp(ptr->auteur,auteur)==0){
			inserer(res,ptr->num,ptr->titre,ptr->auteur);
		}
		ptr=ptr->suiv;
	}
	return res;
}
/*______________________SUPPRESSION_OUVRAGE_H__________*/
BiblioH *suppression_ouvrage_H(BiblioH *b, int num, char* auteur, char * titre)
{
	int c=fonctionClef(auteur);
	int pos=fonctionHachage(c,b->m);
	LivreH *ptr=b->T[pos];
	LivreH* pred=NULL;

	while ((ptr!=NULL) && ((ptr->num != num) || (strcmp(ptr->auteur, auteur)!=0) || (strcmp(ptr->titre, titre)!=0))){
		pred=ptr;
		ptr=ptr->suiv;
	}

	if (ptr!=NULL){
		if (pred!=NULL){
			pred->suiv=ptr->suiv;
		}else{
			pred=ptr->suiv;
			b->T[pos]=pred;
			return b;
		}
		b->nE=(b->nE)-1;
		liberer_livre_H(ptr);
	
	}
	return b;
}

/*_______________________FUSION_H_______________________*/
BiblioH* fusion_H(BiblioH* b1, BiblioH* b2){
	for (int i=0;i<b2->m;i++){
			LivreH* ptr=b2->T[i];
			while (ptr!=NULL){
				inserer(b1,ptr->num,ptr->titre,ptr->auteur);
				ptr=ptr->suiv;
			}
	}
	liberer_biblio_H(b2);
	return b1;
}

/*____________________PLUSIEURS_EXEMPLAIRES_H___________*//*
BiblioH* plusieurs_exmplaires_H(BiblioH* b)
