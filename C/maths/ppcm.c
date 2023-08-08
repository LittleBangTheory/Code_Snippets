#include <stdio.h>
#include <stdlib.h>
#include "headers.h"


int ppcm(int a, int b) {
  return (valeurAbsolue(a*b)/pgcd(a,b));
}


int pgcd(int nbr_1, int nbr_2) {
  int a, b, r;
  a = nbr_1;
  b = nbr_2;
  do {
    r = a % b;
    a = b;
    b = r;
  } while(b != 0);

  return a;
}
