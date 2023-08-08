#include <stdio.h>

int v1(int nbr, int result, int i, int error) {
  while (i < 10 && error == 0) {
    ++i;
    printf("%d x %d = ", nbr, i);
    scanf("%d", &result);
    if (result != i*nbr) {
      error = 1;
      printf("Erreur, le bon résultat était %d\n", i*nbr);
    }
  }
  if (i == 10) {
    printf("Félicitations, vous avez réussi !\n");
  }
  return 0;
}

int v2(int nbr, int result, int i, int error){
  for (i=1; i <= 10; i++) {
    printf("%d x %d = ", nbr, i);
    scanf("%d", &result);
    if (result != i*nbr) {
      error += 1;
    }
  }
  if (error == 0) {
    printf("Félicitations, vous avez réussi !\n");
  } else {
    printf("Vous avez fait %d erreurs, pensez à vous entrainer !\n", error);
  }
  return 0;
}

int main() {
  int nbr;
  int i=0;
  int result = 0;
  int error = 0;
  printf("Entrer un nombre entre 1 et 9 : ");
  scanf("%d",&nbr);
  v1(nbr, result, i, error);
}

/*
Pour tester, on a entré plusieurs tables justes en entier, puis plusieurs tables avec des element faux.
*/
