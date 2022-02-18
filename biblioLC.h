#ifndef _BIBLIO_LC_H_
#define _BIBLIO_LC_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct livre
{
	int num;
	char *titre;
	char *auteur;
	struct livre *suiv;
}Livre;

typedef struct
{
	Livre *L;
}
Biblio;

//PROTOTYPES FONCTIONS 
Livre *creer_livre(int num, char* titre, char* auteur);
void liberer_livre(Livre *l);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio *b, int num, char* titre, char* auteur);
Biblio *supr_ouvrage(Biblio *b, int num, char* auteur, char * titre);
Livre* recherche_par_titre(Biblio *b, char *titre);
Livre* recherche_par_num(Biblio *b, int num);
void afficher_biblio(Biblio *b);
void afficher_livre(Livre *l);
Biblio* recherche_par_meme_auteur(Biblio *b , char *auteur);
Biblio *fusion(Biblio *b1, Biblio *b2);
#endif
