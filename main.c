#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"

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
	printf(" - 7 : recherche ouvrages à plusieurs exemplaires\n");
}

int main(int argc, char* argv[] )
{
	Biblio *b_lc = charger_n_entrees(argv[1], atoi(argv[2]));
	BiblioH *b_h = charger_n_entrees_H(argv[1], atoi(argv[2]));
	int stop = 1;
	char buffer[256];
	char nom_livre[256];
	char nom_auteur[256];
	int num;
	int type;
	double t_num_lc=0,t_titre_lc=0,t_auteur_lc=0;
	double t_auteur_lc_init,t_auteur_lc_fin,t_num_lc_init,t_num_lc_fin, t_titre_lc_init,t_titre_lc_fin;
	double t_num_h=0,t_titre_h=0,t_auteur_h=0;
	double t_auteur_h_init,t_auteur_h_fin,t_num_h_init,t_num_h_fin, t_titre_h_init,t_titre_h_fin;
	while(stop)
	{
		printf("Choisir le type :\n - 1 Liste chainée\n 2 - Table de hachage\n");
		fgets(buffer, sizeof(int), stdin);
		type=atoi(buffer);
		switch(type){
			case 1:
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
					afficher_biblio(b_lc);
					break;
				case 2:
					printf("Entrez un nom de livre, un nom d'auteur et un numéro\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%s %s %d",nom_livre,nom_auteur,&num);
					inserer_en_tete(b_lc,num,nom_livre,nom_auteur);
					printf("Ajout fait\n");
					break;
				case 3:
					printf("Entrez un nom de livre, un nom d'auteur et un numéro\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%s %s %d",nom_livre,nom_auteur,&num);
					supr_ouvrage(b_lc,num,nom_auteur,nom_livre);
					printf("Suppression terminée\n");
					break;
				case 4:
					printf("Entrez un nom de livre\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%s",nom_livre);
					printf("Les livres sont:\n");
					t_titre_lc_init=clock();
					afficher_livre(recherche_par_titre(b_lc,nom_livre));
					t_titre_lc_fin=clock();
					break;
				case 5:
					printf("Entrez un numero de livre\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%d",&num);
					printf("Les livres sont:\n");
					t_num_lc_init=clock();
					afficher_livre(recherche_par_num(b_lc,num));
					t_num_lc_fin=clock();
					break;
				case 6:
					printf("Entrez un nom d'auteur\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%s",nom_auteur);
					printf("Les livres sont:\n");
					t_auteur_lc_init=clock();
			Biblio* blc_auteur=recherche_par_meme_auteur(b_lc,nom_auteur);
					t_auteur_lc_fin=clock();
					afficher_biblio(blc_auteur);
					liberer_biblio(blc_auteur);
					break;
				case 7:
					afficher_biblio(plusieurs_exemplaires(b_lc));
				}
				break;

			case 2:
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
					afficher_biblio_H(b_h);
					break;
				case 2:
					printf("Entrez un nom de livre, un nom d'auteur et un numéro\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%s %s %d",nom_livre,nom_auteur,&num);
					inserer(b_h,num,nom_livre,nom_auteur);
					printf("Ajout fait\n");
					break;
				case 3:
					printf("Entrez un nom de livre, un nom d'auteur et un numéro\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%s %s %d",nom_livre,nom_auteur,&num);
					suppression_ouvrage_H(b_h,num,nom_auteur,nom_livre);
					printf("Suppression terminée\n");
					break;
				case 4:
					printf("Entrez un nom de livre\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%s",nom_livre);
					printf("Les livres sont:\n");
					t_titre_h_init=clock();
					afficher_livre_H(recherche_par_titre_H(b_h,nom_livre));
					t_titre_h_fin=clock();
					break;
				case 5:
					printf("Entrez un numero de livre\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%d",&num);
					printf("Les livres sont:\n");
					t_num_h_init=clock();
					afficher_livre_H(recherche_par_num_H(b_h,num));
					t_num_h_fin=clock();
					break;
				case 6:
					printf("Entrez un nom d'auteur\n");
					fgets(buffer, 256, stdin);
					sscanf(buffer,"%s",nom_auteur);
					printf("Les livres sont:\n");
					t_auteur_h_init=clock();
					BiblioH* bh_auteur=recherche_par_auteur_H(b_h,nom_auteur);
					t_auteur_h_fin=clock();
					afficher_biblio_H(bh_auteur);
					liberer_biblio_H(bh_auteur);
					break;
				}
			break;
		}
	}
	
	
	t_titre_lc=((double)(t_titre_lc_fin-t_titre_lc_init))/CLOCKS_PER_SEC;
	t_titre_h=((double)(t_titre_h_fin-t_titre_h_init))/CLOCKS_PER_SEC;
	t_num_lc=((double)(t_num_lc_fin-t_num_lc_init))/CLOCKS_PER_SEC;
	t_num_h=((double)(t_num_h_fin-t_num_h_init))/CLOCKS_PER_SEC;
	t_auteur_lc=((double)(t_auteur_lc_fin-t_auteur_lc_init))/CLOCKS_PER_SEC;
	t_auteur_h=((double)(t_auteur_h_fin-t_auteur_h_init))/CLOCKS_PER_SEC;
	printf("TEMPS pour ListeChainée:\n Recherche par titre : %.6f \n Recherche par numero : %.6f \n Recherche par auteur : %.6f \n",t_titre_lc,t_num_lc,t_auteur_lc);
	printf("TEMPS pour TableDeHachage:\n Recherche par titre : %.6f \n Recherche par numero : %.6f \n Recherche par auteur : %.6f",t_titre_h,t_num_h,t_auteur_h);
	
	/* POUR UNE VALEUR PRESENTE: 
	TEMPS pour ListeChainée:
		Recherche par titre : 0.002221 
		Recherche par numero : 0.001350 
		Recherche par auteur : 0.002147 
	TEMPS pour TableDeHachage: (TAILLE 100)
 		Recherche par titre : 0.002275 
 		Recherche par numero : 0.002061 
 		Recherche par auteur : 0.003240
 	POUR UNE VALEUR ABSENTE:
 	TEMPS pour ListeChainée:
 		Recherche par titre : 0.004257 
		 Recherche par numero : 0.000974 
		 Recherche par auteur : 0.000822 
	TEMPS pour TableDeHachage:
		 Recherche par titre : 0.001289 
		 Recherche par numero : 0.000918 
		 Recherche par auteur : 0.001092
 	

 POUR DES VALEURS PRESENTES:
 
 Taille de la table de Hachage: 100
 Recherche par titre : 0.019030 
 Recherche par numero : 0.002003 
 Recherche par auteur : 0.003317
  
 Taille de la table de Hachage: 150
 Recherche par titre : 0.014656 
 Recherche par numero : 0.002054 
 Recherche par auteur : 0.003306
 
 Taille :200
 Recherche par titre : 0.003813 
 Recherche par numero : 0.018269 
 Recherche par auteur : 0.001420
 
 Taille :500
 Recherche par titre : 0.003774  
 Recherche par numero : 0.002159 
 Recherche par auteur : 0.001603
 	*/
	
	
	liberer_biblio(b_lc);
	liberer_biblio_H(b_h);

	return 0;
}
