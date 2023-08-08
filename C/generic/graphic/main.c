#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dessine.h"
#include "graphlib.h"

int main() {
  /*le main est actuellement calibé pour tester la fonction dessineMosaiqueAvecSouris()
  Les variables x et y sont donc inutilisées pour cette fonction, et le scanf qui leur attribue une valeur est passé en commentaire*/
  int x, y, taille;
  int largeur, hauteur;
  gr_inits_w(800,600,"Exercice 4");
  /*printf("Rentrer les coordonnées de la pointe du rectangle en format x y : \n");
  scanf("%d %d", &x, &y);*/
  printf("Rentrer la taille du carré en pixels : ");
  scanf("%d", &taille);
  printf("Rentrer la hauteur et la largeur : ");
  scanf("%d %d", &hauteur, &largeur);

  dessineMosaiqueAvecSouris(taille, hauteur, largeur);
  /*Autres fonctions :
  dessineCarre(x, y, taille);
  dessineCarreDiagonale(x, y, taille);
  dessineMosaique(x, y, taille, hauteur, largeur);
  */
  cliquer();
  return 0;
}

/*
Tentative non-fonctionnelle de créer un menu, mais plusieurs segmentation fault que nous n'avons pas réussi à resoudre :

printf("Entrer la version du programme voulue (1 = dessineCarre(), 2 = dessineCarreDiagonale(), 3 = dessineMosaique(), 4 = dessineMosaiqueAvecSouris()) : ");
scanf("%d", &version);
printf("Rentrer la taille du carré en pixels : ");
scanf("%d", &taille);
printf("balise_1\n");
if (version == 1 || version == 2) {
  printf("Rentrer les coordonnées de la pointe du rectangle en format x y : \n");
  scanf("%d %d", &x, &y);
  if (version == 1) {
    dessineCarre(x, y, taille);
  } else {
    dessineCarreDiagonale(x, y, taille);
  }
} else if (version == 3){
  printf("Rentrer la hauteur et la largeur : ");
  scanf("%d %d", &hauteur, &largeur);
  dessineMosaique(x, y, taille, hauteur, largeur);
} else if (version == 4){
  dessineMosaiqueAvecSouris(taille, hauteur, largeur);
} else {
  printf("Vous n'avez pas entré un entier compris entre 1 et 4, arrêt du programme\n");
*/
