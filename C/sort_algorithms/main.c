#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


int main() {
	//Definition des 4 tableaux
	int ref[] = { 3,6,6,7,8,10,14,15,17,19,20,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,81,84,86,89,92,93,97,99 };
	int tab1[] = { 14,15,92,65,35,89,79,32,38,46,26,43,38,32,79,50,28,84,19,71,69,39,93,75,10,58,20,97,49,44,59,23,07,81,64,06,28,62,8,99,86,28,03,48,25,34,21,17,06,79 };
	int tab2[] = { 99,97,93,92,89,86,84,81,79,79,79,75,71,69,65,64,62,59,58,50,49,48,46,44,43,39,38,38,35,34,32,32,28,28,28,26,25,23,21,20,19,17,15,14,10,8,7,6,6,3 };
	int tab3[] = { 3,6,6,7,8,10,14,15,17,19,81,21,23,25,26,28,28,28,32,32,34,35,38,38,39,43,44,46,48,49,50,58,59,62,64,65,69,71,75,79,79,79,20,84,86,89,92,93,97,99 };

	//taille_tableau donne la taille du tableau
	int taille_tableau = sizeof(ref) / sizeof(int);
	//Valant entre 0 et 2, choix_methode sert a demander la methode de trie
	int choix_methode = 0;
	//Cette variable sert a recuperer le nombre de comparaisons
	int nbr_comparaisons=0;
	int* ptr_comparaisons = &nbr_comparaisons;

	//Pointeurs de la fonction bonus
	int (*asc_ptr)(int, int);
	asc_ptr = &asc;

	int (*desc_ptr)(int, int);
	desc_ptr = &desc;


	//On demande la methode de tri
	printf("Quel methode de tri utiliser ?\n1 = BubbleSort\n2 = InsertionSort\n3 = MergeSort\n4 = BubbleSort bonus croissant ou decroissant\n");
	scanf("%d", &choix_methode);
	switch (choix_methode) {
	case 1:
		//On trie ref, qui est deja trie
		printf("Tableau de reference :\n\n");
		nbr_comparaisons = BubbleSort(ref, taille_tableau);
		affiche(ref, taille_tableau, nbr_comparaisons);
		//On trie tab1
		printf("Tableau 1 :\n\n");
		nbr_comparaisons=BubbleSort(tab1, taille_tableau);
		affiche(tab1, taille_tableau, nbr_comparaisons);
		//On trie tab2
		printf("Tableau 2 :\n\n");
		nbr_comparaisons = BubbleSort(tab2, taille_tableau);
		affiche(tab2, taille_tableau, nbr_comparaisons);
		//On trie tab3
		printf("Tableau 3 :\n\n");
		nbr_comparaisons = BubbleSort(tab3, taille_tableau);
		affiche(tab3, taille_tableau, nbr_comparaisons);
		break;
	case 2:
		//On trie ref, qui est deja trie
		printf("Tableau de reference :\n\n");
		nbr_comparaisons = InsertionSort(ref, taille_tableau);
		affiche(ref, taille_tableau, nbr_comparaisons);
		//On trie tab1
		printf("Tableau 1 :\n\n");
		nbr_comparaisons = InsertionSort(tab1, taille_tableau);
		affiche(tab1, taille_tableau, nbr_comparaisons);
		//On trie tab2
		printf("Tableau 2 :\n\n");
		nbr_comparaisons = InsertionSort(tab2, taille_tableau);
		affiche(tab2, taille_tableau, nbr_comparaisons);
		//On trie tab3
		printf("Tableau 3 :\n\n");
		nbr_comparaisons = InsertionSort(tab3, taille_tableau);
		affiche(tab3, taille_tableau, nbr_comparaisons);
		break;
	case 3:
		//On trie ref, qui est deja trie
		printf("Tableau de reference :\n\n");
		MergeSort(0, taille_tableau - 1, ref, ptr_comparaisons);
		affiche(ref, taille_tableau, nbr_comparaisons);
		//On trie tab1
		printf("Tableau 1 :\n\n");
		MergeSort(0, taille_tableau - 1, tab1, ptr_comparaisons);
		affiche(tab1, taille_tableau, nbr_comparaisons);
		//On trie tab2
		printf("Tableau 2 :\n\n");
		MergeSort(0, taille_tableau - 1, tab2, ptr_comparaisons);
		affiche(tab2, taille_tableau, nbr_comparaisons);
		//On trie tab3
		printf("Tableau 3 :\n\n");
		MergeSort(0, taille_tableau - 1, tab3, ptr_comparaisons);
		affiche(tab3, taille_tableau, nbr_comparaisons);
		break;
	case 4:
		//On trie ref, qui est deja trie
		printf("Tableau de reference (ordre croissant):\n\n");
		nbr_comparaisons = bubbleSortBonus(ref, taille_tableau, (*asc_ptr));
		affiche(ref, taille_tableau, nbr_comparaisons);
		//On trie tab1
		printf("Tableau 1 (ordre decroissant):\n\n");
		nbr_comparaisons = bubbleSortBonus(tab1, taille_tableau, (*desc_ptr));
		affiche(tab1, taille_tableau, nbr_comparaisons);
		//On trie tab2
		printf("Tableau 2 (ordre croissant):\n\n");
		nbr_comparaisons = bubbleSortBonus(tab2, taille_tableau, (*asc_ptr));
		affiche(tab2, taille_tableau, nbr_comparaisons);
		//On trie tab3
		printf("Tableau 3 (ordre decroissant) :\n\n");
		nbr_comparaisons = bubbleSortBonus(tab3, taille_tableau, (*desc_ptr));
		affiche(tab3, taille_tableau, nbr_comparaisons);
		break;
	//L'utilisateur s'est plante sur la valeur rentree
	default:
		printf("Vous avez rentre une mauvaise valeur lors de votre choix, fin du programme.");
	}
	return 0;
}
