#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int puissance(int x, int n) {
  int resultat;

  if (x<0 || n<0) {
    printf("Les nombres doivent être positifs\n");
    return -1;
  }

  if (n==0) {
    resultat = 1;
  } else if (n==1) {
    resultat = x;
  } else if (n%2==0) {
    resultat = puissance((x*x),(n/2));
  } else {
    resultat = x*puissance((x*x),((n-1)/2));
  }

  return resultat;
}
