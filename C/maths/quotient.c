#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int quotient(int a, int b) {
  if (a<0 || b<0) {
    printf("Erreur : les nombres doivent être positifs\n");
    return -1;
  } else if (b == 0) {
    printf("Erreur : divison par 0\n");
    return -1;
  } else {
    int r, q=0;
    if (a<b) {
      q = 0;
    } else {
      do {
        r = a-b;
        a = r;
        q++;
      } while (r>=b);
    }

    return q;
  }

}
