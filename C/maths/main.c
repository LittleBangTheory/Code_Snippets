#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main() {

  /*
  int a, b;
  printf("Entrez deux entiers positifs\n");
  scanf("%d %d", &a, &b);
  printf("%d\n", reste(a,b));
  */

  testBibliotheque();

  return 0;
}

void testBibliotheque() {
  //Test quotient
  printf("Test de la fonction quotient\n");
  printf("30 / 7 = %d\n", quotient(30,7)); //Cas général
  printf("30 / 0 = %d\n", quotient(30,0)); //Divison par 0
  printf("-30 / -5 = %d\n", quotient(-30,-5)); //Nombres négatifs
  printf("6 / 10 = %d\n", quotient(6,10)); //Divison par un nombre supérieur

  printf("\n");

  //Test reste
  printf("Test de la fonction reste\n");
  printf("30 %% 7 = %d\n", reste(30,7)); //Cas général
  printf("30 %% 0 = %d\n", reste(30,0)); //Divison par 0
  printf("-30 %% -5 = %d\n", reste(-30,-5)); //Nombres négatifs
  printf("6 %% 10 = %d\n", reste(6,10)); //Divison par un nombre supérieur

  printf("\n");

  //Test valeur absolue
  printf("Test de la fonction valeurAbsolue\n");
  printf("La valeur absolue de 5 est %d\n", valeurAbsolue(5)); //Nombre positif
  printf("La valeur absolue de -7 est %d\n", valeurAbsolue(-7)); //Nombre négatif
  printf("La valeur absolue de 0 est %d\n", valeurAbsolue(0)); //Zéro

  printf("\n");

  //Test ppcm
  printf("Test de la fonction ppcm\n");
  printf("Le ppcm de 10 et 8 est %d\n", ppcm(10,8)); //Cas général
  printf("Le ppcm de -5 et 6 est %d\n", ppcm(-5,6)); //Nombre négatif
  printf("Le ppcm de 0 et 16 est %d\n", ppcm(0,16)); //Zéro

  printf("\n");

  //Test puissance
  printf("Test de la fonction puissance\n");
  printf("5^3 = %d\n", puissance(5,3)); //Cas général
  printf("3^0 = %d\n", puissance(3,0)); //x puissance zéro
  printf("0^2 = %d\n", puissance(0,2)); //Zéro puissance x
  printf("-4^5 = %d\n", puissance(-4,5)); //Nombre négatif
  printf("3^-2 = %d\n", puissance(3,-2)); //Puissance négative

  printf("\n");

  //Test sommeDesImpairs
  printf("Test de la fonction sommeDesImpairs\n");
  printf("La somme des impairs de 3 à 27 est : %d\n", sommeDesImpairs(3, 27)); //Cas général
  printf("La somme des impairs de 2 à 27 est : %d\n", sommeDesImpairs(2, 27)); //Nombre pair
  printf("La somme des impairs de -5 à 19 est : %d\n", sommeDesImpairs(-5, 19)); //Nombre négatif
  printf("La somme des impairs de 13 à 3 est : %d\n", sommeDesImpairs(13, 3)); //1er nombre supérieur

  printf("\n");

  //Test estUneDecompositionDe
  printf("Test de la fonction estUneDecompositionDe\n");
  printf("La décomposition de 7 et 11 est %d\n", estUneDecompositionDe(7,11)); //Cas où la décomposition existe
  printf("La décomposition de 7 et 13 est %d\n", estUneDecompositionDe(7,13)); //Cas où la décomposition n'existe pas
  printf("La décomposition de 2 et 27 est : %d\n", estUneDecompositionDe(2, 27)); //Nombre pair
  printf("La décomposition de -5 et 19 est : %d\n", estUneDecompositionDe(-5, 19)); //Nombre négatif
  printf("La décomposition de 13 à 3 est : %d\n", estUneDecompositionDe(13, 3)); //1er nombre supérieur
}
