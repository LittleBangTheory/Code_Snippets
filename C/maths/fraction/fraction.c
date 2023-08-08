#include <stdlib.h>
#include <stdio.h>
#include "fraction.h"

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

void addFraction(Fraction f1, Fraction f2) {
  int num, den, numS, denS;

  den = (f1.den/pgcd(f1.den, f2.den)) * f2.den;
  num = f1.num * den/f1.den + f2.num * den/f2.den;

  //Réduire la fraction
  numS = num/pgcd(num, den);
  denS = den/pgcd(num, den);

  printf("%d / %d\n", numS, denS);
}

void subFraction(Fraction f1, Fraction f2) {
  int num, den, numS, denS;

  den = (f1.den/pgcd(f1.den, f2.den)) * f2.den;
  num = f1.num * den/f1.den - f2.num * den/f2.den;

  //Réduire la fraction
  numS = num/pgcd(num, den);
  denS = den/pgcd(num, den);

  printf("%d / %d\n", numS, denS);
}

void mulFraction(Fraction f1, Fraction f2) {
  int num, den, numS, denS;
  num = f1.num * f2.num;
  den = f1.den * f2.den;
  numS = num/pgcd(num, den);
  denS = den/pgcd(num, den);

  printf("%d / %d\n", numS, denS);
}

void divFraction(Fraction f1, Fraction f2) {
  int tmp;
  tmp = f2.num;
  f2.num = f2.den;
  f2.den = tmp;

  mulFraction(f1, f2);
}
