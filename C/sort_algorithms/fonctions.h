#include <stdio.h>


void swap(int* a, int* b);
int compare(int* a, int *b, int n);
void affiche(int* a, int n, int nbr_comparaisons);
void merge (int* tab, int* tmp, int left, int mid, int right, int* cnt);
int BubbleSort(int* tab, int taille_tableau);
int InsertionSort(int* tab, int taille_tableau);
void swap(int* a, int* b);
void MergeSort(int i, int j, int* tab, int* nbr_comparaisons);
int asc(int a, int b);
int desc(int a, int b);
int bubbleSortBonus (int *tab, int taille, int (*f_ptr)(int, int));
