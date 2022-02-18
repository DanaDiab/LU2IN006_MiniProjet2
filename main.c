#include<stdio.h>
#include<stdlib.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

void menu()
{
/*______________AFFICHAGE DU MENU____________________*/
	printf("Actions possibles sur la bibliothèque : \n");
	printf(" - 0 : Quitter le programme\n");
	printf(" - 1 : Affichage\n");
	printf(" - 2 : Insertion d'ouvrage\n");
	printf(" - 3 : suppression d'ouvrage\n");
	printf(" - 4 : recherche par titre\n");
	printf(" - 5 : recherche par numero\n");
	printf(" - 6 : recherche par auteur\n");



}
int main(int argc, char* argv[] )
{
	Biblio *b = charger_n_entrees(argv[1], atoi(argv[2]));
	int stop = 1;
	char buffer[256];
	char nom_livre[256];
	char nom_auteur[256];
	int num;
	while(stop)
	{
		menu();
		printf("saisir l'action a effectuer.\n");
		fgets(buffer, sizeof(int), stdin);
		stop=atoi(buffer);
		
		switch(stop) 
		{
		case 0:
			printf("Merci et au revoir\n");
			break;
		case 1:
			afficher_biblio(b);
			break;
		case 2:
			printf("Entrez un nom de livre, un nom d'auteur et un numéro\n");
			fgets(buffer, 256, stdin);
			sscanf(buffer,"%s %s %d",nom_livre,nom_auteur,&num);
			inserer_en_tete(b,num,nom_livre,nom_auteur);
			printf("Ajout fait\n");
			break;
		case 3:
			printf("Entrez un nom de livre, un nom d'auteur et un numéro\n");
			fgets(buffer, 256, stdin);
			sscanf(buffer,"%s %s %d",nom_livre,nom_auteur,&num);
			supr_ouvrage(b,num,nom_auteur,nom_livre);
			printf("Suppression terminée\n");
			break;
		case 4:
			printf("Entrez un nom de livre\n");
			fgets(buffer, 256, stdin);
			sscanf(buffer,"%s",nom_livre);
			printf("Les livres sont:\n");
			afficher_livre(recherche_par_titre(b,nom_livre));
			break;
		case 5:
			printf("Entrez un numero de livre\n");
			fgets(buffer, 256, stdin);
			sscanf(buffer,"%d",&num);
			printf("Les livres sont:\n");
			afficher_livre(recherche_par_num(b,num));
			break;
		case 6:
			printf("Entrez un nom d'auteur\n");
			fgets(buffer, 256, stdin);
			sscanf(buffer,"%s",nom_auteur);
			printf("Les livres sont:\n");
			afficher_biblio(recherche_par_meme_auteur(b,nom_auteur));
			break;
		}
	}
	liberer_biblio(b);
	
	return 0;
}
