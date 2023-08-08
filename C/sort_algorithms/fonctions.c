#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

void affiche(int* a, int n, int nbr_comparaisons){
	int i;
	printf("Le tableau trie est :\n[ ");
	for (i = 0 ; i < n ; i++){
		printf("%d ", a[i]);
	}
	printf("]\n\nIl a fallu faire %d comparaisons.\n\n", nbr_comparaisons);
}


int compare(int* a, int *b, int n){
	int i;
	for(i=0; i < n ; i++){
		if (a[i] != b[i]){
			printf("Comparison FAILED at index %d\n\n", i);
			return i;
		}
	}
	printf("Comparison OK\n\n");
	return -1;
}


int BubbleSort(int* tab, int taille_tableau) {
	//trie est un booleen qui indique si le tableau est trie
	int trie = 0;
	//nbr_comparaisons est incremente a chaque tour de boucle
	int nbr_comparaisons = 0;
	//position_tableau est notre variable de boucle et var_temp sert de stockage temporaire pour l'echange de valeur de deux variables
	int position_tableau;
	//On boucle tant que le tableau n'est pas trie (trie est initalise a 1 mais passe a 0 si on intervertit deux �l�ments)
	while (trie == 0) {
		trie = 1;
		//On parcourt tout le tableau
		for (position_tableau = 0; position_tableau < taille_tableau - 1; position_tableau++) {
			//Si la valeur de la position actuelle est superieure a celle de la position suivante, on les echange et on passe trie a 0
			if (tab[position_tableau] > tab[position_tableau + 1]) {
				swap(&tab[position_tableau], &tab[position_tableau + 1]);
				trie = 0;
			}
			nbr_comparaisons++;
		}
	}
	return nbr_comparaisons;
}

/* Questions BubbleSort :
1.5)
Il effectue  49 comparaisons pour le tableau ref déjà trié, 2303 comparaisons pour tab1, 2450 comparaisons pour tab2, et 1617 comparaisons pour tab3.
1.6)
Dans le meilleur des cas, on ne boucle pas dans le while de la fonction BubbleSort donc la complexité est de O(n).
Dans le pire des cas, on boucle dans le while et le for plusieurs fois, c’est du O(n²).
Donc c’est un algorithme adaptatif puisqu’il s’adapte au tableau, selon si celui-ci est déjà ou non partiellement trié.
1.7)
La quantité mémoire utilisée est constante au cours de l’exécution du programme, celui-ci est donc de complexité spatiale soit de O(1), donc l’algorithme est stable.*/


int bubbleSortBonus (int *tab, int taille, int (*f_ptr)(int, int)) {
        int nbComparaisons=0;
        int trie = 0;
        while (trie==0) {
                trie = 1;

                for (int i=0; i<taille-1; i++) {
                        if ((*f_ptr)(tab[i], tab[i+1]) == 1) {
                                swap(&tab[i], &tab[i+1]);
                                trie = 0;
                        }
                        nbComparaisons++;
                }
        }
        return nbComparaisons;
}

int asc(int a, int b) {
        int resultat;
        if (a<b) {
                resultat = 0;
        }
        else if (a>b) {
                resultat = 1;
        }
        else {
                resultat = 2;
        }
        return resultat;
}


int desc(int a, int b) {
        int resultat;
        if (a>b) {
                resultat = 0;
        }
        else if (a<b) {
                resultat = 1;
        }
        else {
                resultat = 2;
        }
        return resultat;
}


int InsertionSort(int* tab, int taille_tableau) {
	int position_tableau, i;
	//nbr_comparaisons est incremente a chaque tour de boucle
	int nbr_comparaisons = 0;
	//On parcourt le tableau
	for (position_tableau = 1; position_tableau < taille_tableau; position_tableau++) {
		nbr_comparaisons++;
		//On recupere la position de la variable dans le tableau
		i = position_tableau;
		//Tant que la valeur qu'on trie est inferieure a la valeur
		while (tab[i] < tab[i - 1] && i>0) {
			swap(&tab[i - 1], &tab[i]);
			i--;
			nbr_comparaisons++;
		}
	}
	return nbr_comparaisons;
}


void swap(int* a, int* b) {
	int var_temp;
	var_temp = *a;
	*a = *b;
	*b = var_temp;
}

/*Questions InsertionSort :
2.2)
Pour le tableau ref déjà trié il a fallu faire 49 comparaisons, 731 pour tab1, 1265 pour tab2 et 112 pour tab3.
2.3)
Dans le meilleur des cas cet algorithme est d’une complexité de O(n) car on ne boucle pas dans le while de la fonction.
Dans le pire des cas cet algorithme est d’une complexité de O(n²) car on boucle plusieurs fois dans les boucles for et while. L’algorithme est donc adaptatif.
2.4)
Comme pour le Bubble Sort la complexité spatiale est de O(1) car l’utilisation de la mémoire n’évolue pas au cours de l’exécution du programme.*/

void MergeSort(int i, int j, int* tab, int* nbr_comparaisons) {
	//Si le tableau est vide ou compose d'un seul element, on quitte la fonction
	if (j <= i) { return; }
	//On trouve le milieu du tableau
	int m = (i + j) / 2;
	//printf("%d %d %d\n", i, m, j);
	//On tri la moitie gauche
	MergeSort(i, m, tab, nbr_comparaisons);
	//On tri la moitie droite
	MergeSort(m + 1, j, tab, nbr_comparaisons);
	//g est le compteur de gauche
	int g = i;
	//d est le compteur de droite
	int d = j;
	//On obtient la taille du tableau
	int taille_tableau = j - i + 1;
	//On cree un tableau temporaire de taille connue a l'execution grace a malloc
	int* tab_temp = NULL;
	tab_temp = malloc((taille_tableau) * sizeof(int));
	//On verifie que l'espace memoire a bien ete alloue
	if (tab_temp == NULL) {
		exit(0);
	}
	merge(tab, tab_temp, g, m, d, nbr_comparaisons);
	//On n'oublie pas de liberer la memoire
	free(tab_temp);
}

void merge (int* tab, int* tab_temp, int g, int m, int d, int* nbr_comparaisons){
	//On initialise les constantes de la boucle
	int g_init=g;
	int d_init=d;
	int m_init=m;
	int taille_tableau = d_init - g_init + 1;

	//printf("%d %d %d\n", g, m, d);
	// on boucle de g_init a d_init pour remplir chaque element du tableau final fusionne
	for (int c = g_init; c <= d_init; c++) {
		//le compteur gauche a parcouru tout son sous-tableau
		if (g == m_init) {
			tab_temp[c-g_init] = tab[m];
			m++;
		}
		//le compteur droit a parcouru tout son sous-tableau
		else if (m == d_init) {
			tab_temp[c-g_init] = tab[g];
			g++;
		}
		//la valeur pointee a gauche est inferieure a celle de droite
		else if (tab[g] < tab[d]) {
			tab_temp[c-g_init] = tab[g];
			g++;
		}
		//la valeur pointee a droite  est inferieure a celle de gauche
		else {
			tab_temp[c-g_init] = tab[d];
			d++;
		}
		affiche(tab_temp, taille_tableau, *nbr_comparaisons);
		*nbr_comparaisons += 1;
	}
	//On copie case par case tab_temp dans tab
	for (int c = g_init; c <= d_init; c++) {
		tab[c-g_init] = tab_temp[c-g_init];
	}
}

/*Questions MergeSort :
3.1)
- Lorsqu'on déclare " int* tmp = tab1 ; " : cette instruction crée un tableau tmp de la même taille que tab1 et place les valeurs de tab1 dans le tableau tmp. On peut le vérifier lorsqu'on affiche le tableau tmp.

-   Lorsqu'on déclare " int tmp[n]; " : cela crée un tableau de taille n remplie de 0. On peut le vérifier lorsqu'on affiche le tableau tmp.
3.2)
Pour la question 4, on veut créer un tableau qui stockera de manière temporaire les éléments du tableau (tab) à trier */
