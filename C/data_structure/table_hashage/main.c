/** \file main.c
 * \brief Programme de test du gestionnaire de magasin
 * 
*/

#define __STORE_H__
#include "store.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/** \fn void input()
 * \brief Fonction d'attente d'un input utilisateur
 * \return void
*/
void input(){
	while(1){
		printf("Continuer ? (y/n)\n");
		char c;
		c = getchar();
		if(c == 'n'){
			exit(0);
		} else if (c == 'y'){
			// On vide le buffer
			c = getchar();
			return;
		}
	}
}

/** \fn void testFunctionnalities()
 * \brief Fonction de test des fonctionnalités du gestionnaire de magasin
 * \return void
 * Cette fonction appelle les différentes fonctions de store.c, et se met en pause entre chaque test pour laisser l'utilisateur vérifier le résultat.
*/
void testFunctionnalities(){
	printf("########## TEST insert item ##########\n");
	// Ajouter un element
	printf("__REMPLISSAGE DE LA TABLE__ \n\n");
	for(int i = 0; i < TABLE_SIZE; i++){
		insertItem(i,"NONAME",i*1.0);
	}

	// Afficher le contenu de la table
	printf("Contenu de la table : \n\n");
	dumpItems();

	input();
	// Supprimer un element sur deux
	printf("__SUPPRESSION DE LA TABLE__\n\n");
	for(int i = 0; i < TABLE_SIZE; i+=1){
		suppressItem(i);
	}

	// Afficher le contenu de la table
	printf("Contenu de la table : \n\n");
	dumpItems();

	input();
	// Ajouter tous les elements multiples de 10
	printf("__REMPLISSAGE DE LA TABLE AVEC LES ELEMENTS MULTIPLES DE 5__\n\n");
	for(int i = 0; i < TABLE_SIZE; i+=5){
		insertItem(i,"NONAME",i*1.0);
	}

	// Afficher le contenu de la table
	printf("Contenu de la table : \n\n");
	dumpItems();

	input();
	// Ajouter un element
	printf("### TEST OVERFLOW DE LA TABLE ###\n\n");
	for(int i = 0; i < TABLE_SIZE + 5; i++){
		if(insertItem(i,"NONAME",i*1.0) == TABLE_FULL){
			printf("Insertion de l'element de code %d impossible, table pleine !\n",i);
		} else {
			printf("Insertion de l'element de code %d reussie !\n",i);
		}
	}

	printf("__NETTOYAGE DE LA TABLE__\n\n");
	// Supprimer tous les elements
	for(int i = 0; i < TABLE_SIZE; i++){
		suppressItem(i);
	}

	input();
	printf("\n### REBUILD DE LA TABLE ###\n\n");
	printf("__REMPLISSAGE DES 5 PREMIERES CASES__\n\n");
	for(int i = 0; i < TABLE_SIZE - 5; i++){insertItem(i,"NONAME",i*1.0);}

	// On insère 10 et 11 (hashkey(10,0) = 0 et hashkey(11,0) = 1)
	printf("__INSERTION DE 10 ET 11__\n\n");
	insertItem(10,"Element 10",14);
	insertItem(11,"Element 11",20);

	// Test updateItem
	printf("__UPDATE DE 3__\n\n");
	updateItem(3, "Patate", 0.5);
	dumpItems();

	printf("__SUPPRESSION DE 1__\n\n");
	suppressItem(1);
	dumpItems();

	input();
	printf("__REBUILD DE LA TABLE__\n\n");
	rebuildTable();

	// Afficher le contenu de la table
	printf("Contenu de la table : \n\n");
	dumpItems();

	input();


	printf("########## TEST find item with index ##########\n");

	Result* recherche = findItemWithIndex("NONAME");
	printf("__SEARCHING FOR NONAME__\n");
	input();
	while (recherche!=NULL)
	{
		printf("Elem found at : %p\n",recherche->item);
		recherche=recherche->next;
	}
	printf("########## TEST find item ##########\n");

	Result* recherche2 = findItem("NONAME");
	printf("__SEARCHING FOR NONAME__\n");
	input();
	while (recherche2!=NULL)
	{
		printf("Elem found at : %p\n",recherche2->item);
		recherche2=recherche2->next;
	}
}

/** \fn void testTime()
 * \brief Fonction de test du temps d'exécution du gestionnaire de magasin
 * \return void
*/

void testTime(){
	// Remplissage de la table
	printf("__REMPLISSAGE DE LA TABLE AVEC %d ELEMENTS__\n", TABLE_SIZE);
	clock_t t = clock();

	for(int i = 0; i < TABLE_SIZE; i++){
		insertItem(i,"NONAME",i*1.0);
	}

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; 
	printf("Temps d'execution : %f secondes\n", time_taken);

	// Recherche de l'élément d'index 1500000
	int index = TABLE_SIZE*0.75;
	printf("__RECHERCHE DE L'ELEMENT D'INDEX %d__\n", index);
	t = clock();
	Item *item = getItem(1500000);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; 
	printf("Temps d'execution pour trouver l'item de nom %s : %f secondes\n", item->name, time_taken);

}

int main(int argc, char *argv[])
{
	if (argc != 1) {
		printf("## Usage ##\nTo test execution time : %s -t\nTo test functionnalities : %s -f\n", argv[0], argv[0]);
	}
    printf("****** Gestionnaire de magasin ******\n");
    init();

	if (argc == 2 && argv[1][1] == 't') {
		printf("## Execution time test ##\n");
		testTime();
	} else if (argc == 2 && argv[1][1] == 'f') {
		printf("## Functionnalities test ##\n");
		testFunctionnalities();
	}   

    printf("=======Gestionnaire de magasin ======\n");

    return 0;
}

