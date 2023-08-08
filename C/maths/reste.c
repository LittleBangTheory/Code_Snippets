#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int reste(int a, int b) {

  int q, reste, c;


  q = quotient(a, b);
  if (q!=-1) {
    c = q*b;
    reste = a-c;

    return reste;
  } else {return -1;}
}
