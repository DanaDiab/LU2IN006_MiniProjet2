#ifndef BIBLIO_H_H
#define BIBLIO_H_H

typedef struct livreh
{
	int clef;
	int num;
	char *titre;
	char *auteur;
	struct livreh *suiv;
}LivreH;

typedef struct table 
{
	int nE ;		/*nombre d’elements contenus dans la table de hachage */
	int m ; 		/*taille de la table de hachage */
	LivreH ** T;	/*table de hachage avec resolution des collisions par chainage */
} BiblioH ;

//PROTOTYPES

int fonctionClef(char* auteur);
LivreH *creer_livre(int num, char* titre, char* auteur);
void liberer_livre(LivreH* lh);
void afficher_livre(LivreH *l);
BiblioH* creer_biblio(int taille);


#endif
