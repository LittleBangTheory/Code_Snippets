#include <stdlib.h>
#include <stdio.h>
#include "fraction.h"

int main() {
  Fraction fa, fb;
  char op;
  printf("Entrer deux fractions :") ;
  scanf("%d/%d %d/%d", &fa.num, &fa.den, &fb.num, &fb.den) ;
  printf("Entrez une operation (+,-,*,/) :");
  scanf(" %c", &op);

  switch (op) {
    case '+': addFraction(fa,fb); break;
    case '-': subFraction(fa,fb); break;
    case '*': mulFraction(fa,fb); break;
    case '/': divFraction(fa,fb); break;
  }

  return 0;
}
