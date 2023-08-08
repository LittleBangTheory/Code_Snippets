#include <stdio.h>
#include <stdlib.h>
#include "graphlib.h"
#include "dessine.h"

void dessineCarre(int x, int y, int taille) {
  line(x, y, x+taille/2, y-taille/2);
  line(x+taille/2, y-taille/2, x, y-taille);
  line(x, y-taille, x-taille/2, y-taille/2);
  line(x-taille/2, y-taille/2, x, y);
}

void dessineCarreDiagonale(int x, int y, int taille) {
  /*carré*/
  line(x, y, x+taille/2, y-taille/2);
  line(x+taille/2, y-taille/2, x, y-taille);
  line(x, y-taille, x-taille/2, y-taille/2);
  line(x-taille/2, y-taille/2, x, y);
  /*diagonales*/
  line(x+taille/2, y-taille/2, x-taille/2, y-taille/2);
  line(x, y, x, y-taille);
}

void dessineMosaique(int x, int y, int taille, int hauteur, int largeur) {
  int i = 0, j = 0;
  int x_def = x;
  for (i = 0; i < hauteur; i++) {
    for (j = 0; j < largeur; j++) {
      line(x, y, x+taille/2, y-taille/2);
      line(x+taille/2, y-taille/2, x, y-taille);
      line(x, y-taille, x-taille/2, y-taille/2);
      line(x-taille/2, y-taille/2, x, y);
      x=x+taille;
    }
    y=y+taille;
    x = x_def;
  }
}

void dessineMosaiqueAvecSouris(int taille, int hauteur, int largeur){
  int x,y;
  printf("Cliquer à l'endroit où vous voulez positionner le carré\n");
  cliquer_xy(&x, &y);
  dessineMosaique(x, y, taille, hauteur, largeur);
}
