#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int sommeDesImpairs(int d, int f) {
  if (d%2==0 || f%2==0) {
    printf("Erreur : les nombres doivent être impairs\n");
    return -1;
  }
  if (d>f) {
    printf("Erreur : le 1er nombre doit être inférieur au 2eme\n");
    return -1;
  }

  int resultat = 0;
  for (int i=d; i<=f; i+=2){
    resultat += i;
  }

  return resultat;
}


int estUneDecompositionDe(int d, int f) {
  if (d%2==0 || f%2==0) {
    printf("Erreur : les nombres doivent être impairs\n");
    return -1;
  }
  if (d>f) {
    printf("Erreur : le 1er nombre doit être inférieur au 2eme\n");
    return -1;
  }

  int resultat = -1, i=0;
  while (resultat==-1 && i<f) {
    if (puissance(i,3) == sommeDesImpairs(d, f)) {
      resultat = i;
    } else {
      i++;
    }
  }

  return resultat;
}
