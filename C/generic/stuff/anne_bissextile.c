#include <stdio.h>

int main(int argc, char const *argv[]) {
  int annee;
  printf("Rentrer une année : ");
  scanf("%d", &annee);
  if ( (annee % 4 == 0) && ((annee % 100 == 0 && annee % 400 == 0) || (annee % 100 != 0)) ) {
    printf("l'annee %d est bissextile\n", annee);
  } else if ( (annee % 4 != 0) || ((annee % 4 == 0) && (annee % 100 == 0) && (annee % 400 != 0))) {
    printf("l'annee %d n'est pas bissextile\n", annee);
  }
  return 0;
}

/*
années bissextiles : 2016, 2020
années non-bissextiles : 2017, 2022
*/
