#include <stdio.h>

void pgcd(int, int);

int main() {
  int nbr_1, nbr_2;
  printf("Entrer un premier nombre : ");
  scanf("%d", &nbr_1);
  printf("Entrer un deuxième nombre : ");
  scanf("%d", &nbr_2);
  pgcd(nbr_1, nbr_2);
}

void pgcd(int nbr_1, int nbr_2) {
  int a, b, r;
  a = nbr_1;
  b = nbr_2;
  do {
    r = a % b;
    a = b;
    #ifdef MISEAUPOINT
    printf("Valeur de b = %d\n", b);
    #endif
    b = r;
  } while(b != 0);
  printf("Le PGCD de %d et %d est %d\n", nbr_1, nbr_2, a);
}
