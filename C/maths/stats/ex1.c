#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex1.h"

int main() {
  float valeurRecherchee = 8.5;
  float notes[] = {12, 13.5, 8.5, 14.7, 6};
  int taille = sizeof(notes)/sizeof(float);

  printf("Liste des notes :\n");
  afficherNotes(notes, taille);
  printf("------------------\n");
  printf("Minimum = %.2f\n", minimumNote(notes, taille));
  printf("Maximum %.2f\n", maximumNote(notes, taille));
  printf("Moyenne = %.2f\n", calculMoyenne(notes, taille));
  printf("Variance = %.2f\n", calculVariance(notes, taille));
  printf("Ecart type = %.2f\n", calculEcartType(notes, taille));
  printf("La valeur %.2f est à la position %d\n", valeurRecherchee, rechercherValeur(notes, taille, valeurRecherchee));


  return 0;
}


void afficherNotes(float notes[], int taille) {
  for (int i=0; i<taille; i++) {
    printf("%.2f\n", notes[i]);
  }
}


float minimumNote(float notes[], int taille) {
  float min=20;
  for (int i=0; i<taille; i++) {
    if (notes[i]<=min) {
      min = notes[i];
    }
  }

  return min;
}

float maximumNote(float notes[], int taille) {
  float max=0;
  for (int i=0; i<taille; i++) {
    if (notes[i]>=max) {
      max = notes[i];
    }
  }

  return max;
}

float calculMoyenne(float notes[], int taille) {
  float somme=0, moyenne;

  for (int i=0; i<taille; i++) {
    somme+=notes[i];
  }

  moyenne = somme/taille;

  return moyenne;

}

float calculVariance(float notes[], int taille) {
  float variance=0, moyenne;

  moyenne = calculMoyenne(notes, taille);

  for (int i=0; i<taille; i++) {
    variance+=(notes[i]-moyenne)*(notes[i]-moyenne);
  }
  variance = variance/taille;

  return variance;

}

float calculEcartType(float notes[], int taille) {
  float ecartType = sqrtf(calculVariance(notes, taille));
  return ecartType;
}

int rechercherValeur(float notes[], int taille, float valeur) {
  int pos=-1;
  for (int i=0; i<taille; i++) {
    if (notes[i]==valeur) {
      pos = i;
    }
  }

  return pos;
}
