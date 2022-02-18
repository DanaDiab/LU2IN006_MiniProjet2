#include <stdio.h>
#include <stdlib.h>
#include "biblioH.h"
#include <assert.h>

int main(int argc, char *argv[])
{
	char *test="Ben"; //66+101+110=277
	assert(fonctionClef(test)==277);
	
	//test de creation, affichage et libération d'un livre, a executer avec valgrind :
	
	LivreH *lh=creer_livre(1234, "La Dame Aux Camelias", "Alexandre Dumas fils");
	
	afficher_livre(lh);
	
	liberer_livre(lh);
	return 0;
}
