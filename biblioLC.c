#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioLC.h"

Livre *creer_livre(int num, char* titre, char* auteur)
	{
	Livre * new_livre = (Livre*)malloc(sizeof(Livre));
	if (new_livre==NULL){
		return NULL;
	}
	new_livre->num=num;
	new_livre->titre = strdup(titre);
	new_livre->auteur = strdup(auteur);
	return new_livre;
	}
	
void liberer_livre(Livre* l){
	Livre *tmp=l;
	while (tmp){
		tmp=tmp->suiv;
		free(l->titre);
		free(l->auteur);
		free(l);
		l=tmp;
	}
}
	
Biblio* creer_biblio(){
	Biblio* biblio=(Biblio*)malloc(sizeof(Biblio));
	biblio->L=NULL;
	return biblio;
	}
	
void liberer_biblio(Biblio* b){
	liberer_livre(b->L);
	free(b);
	}
	
void inserer_en_tete(Biblio* b, int num, char* titre,char* auteur){
	Livre * l=creer_livre(num,titre,auteur);
	l->suiv=b->L;
	b->L=l;
	}
	
void afficher_livre(Livre *l){
	if (l!=NULL){
		printf("Numero : %d , Titre: %s , Auteur: %s\n", l->num,l->titre, l->auteur);
		}
	}
	
void afficher_biblio(Biblio *b){
	Livre* prc = b->L;
	while (prc){
		afficher_livre(prc);
		prc=prc->suiv;
	}
	}
	
Livre* recherche_par_num(Biblio *b, int num){
	while ((b->L) && (b->L->num!=num)){
		b->L=b->L->suiv;
	}
	return b->L;
	}
	
Livre* recherche_par_titre(Biblio *b, char *titre){
	while ((b->L) && (strcmp(b->L->titre,titre)!=0)){
		b->L=b->L->suiv;
	}
	return b->L;
	}
	
Biblio* recherche_par_meme_auteur(Biblio *b , char *auteur){
	Biblio *new_b=creer_biblio();
	while (b->L){
		if (strcmp(b->L->auteur,auteur)==0){
			inserer_en_tete(new_b,b->L->num,b->L->titre,b->L->auteur);
		}
		b->L=b->L->suiv;
	}
	return new_b;
	}
	
Biblio *supr_ouvrage(Biblio *b, int num, char* auteur, char * titre)
{	

	Livre *ptr=b->L;
	Livre* pred=NULL;
	
	while ((ptr!=NULL) && ((ptr->num != num) || (strcmp(ptr->auteur, auteur)!=0) || (strcmp(ptr->titre, titre)!=0))){
		pred=ptr;
		ptr=ptr->suiv;
	}
	
	if (ptr!=NULL){
		if (pred!=NULL){
			pred->suiv=ptr->suiv;
		}else{
			pred=ptr->suiv;
			b->L=pred;
			return b;
		}
		free(ptr);
	}
	return b;
}

Biblio *fusion(Biblio *b1, Biblio *b2)
{
	Biblio *tete_b2=b2;
	while(b2->L)
	{
		inserer_en_tete(b1, b2->L->num, b2->L->titre, b2->L->auteur);
		b2->L=b2->L->suiv;
	}
	liberer_biblio(tete_b2);
	return b1;
}

/*Biblio* plusieurs_exemplaires(biblio* b){*/
		
