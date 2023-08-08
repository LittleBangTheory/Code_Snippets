#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ex2.h"


int main() {

  char* chaine_test = "toto";
  char *chaine_retournee, *chaine_maj, *chaine_min, *chaine_inv;
  char caractere = 'o';

  printf("La longueur %s est : %d\n", chaine_test, myStrlen(chaine_test));
  printf("\n");

  char chaine2[100];
  printf("La copie de %s est : %s\n", chaine_test, myStrcpy(chaine_test, chaine2));
  printf("\n");

  printf("La valeur hexadecimale de %s est : ", chaine_test);
  affichageHexa(chaine_test);
  printf("\n\n");

  printf("La valeur décimale de %s est : ", chaine_test);
  affichageDec(chaine_test);
  printf("\n\n");

  chaine_maj = mettreEnMaj(chaine_test);
  printf("La chaine %s en majuscules est : %s\n", chaine_test, chaine_maj);
  printf("\n");

  chaine_min = mettreEnMin(chaine_maj);
  printf("La chaine %s en minuscules est : %s\n", chaine_maj, chaine_min);
  printf("\n");

  chaine_inv = inverserMinMaj("TOto");
  printf("La chaine \"TOto\" en inversant la casse est : %s\n", chaine_inv);
  printf("\n");

  chaine_retournee = retournerMot(chaine_test);
  printf("Le mot %s retourné est : %s\n", chaine_test, chaine_retournee);
  printf("\n");

  printf("La premiere occurence en partant de la gauche du caractere '%c' est à la position %d du mot %s\n", caractere, rechercheCaractereG(chaine_test, caractere), chaine_test);
  printf("La premiere occurence en partant de la droite du caractere '%c' est à la position %d du mot %s\n", caractere, rechercheCaractereD(chaine_test, caractere), chaine_test);
  printf("La premiere occurence en partant de la gauche du caractere 'z' est à la position %d du mot %s\n", rechercheCaractereG(chaine_test, 'z'), chaine_test);
  printf("\n");

  printf("comparerChaine(\"toto\", \"toto\") = %d\n", comparerChaine("toto", "toto"));
  printf("comparerChaine(\"toto\", \"titi\") = %d\n", comparerChaine("toto", "titi"));
  printf("comparerChaine(\"titi\", \"toto\") = %d\n", comparerChaine("titi", "toto"));
  printf("\n");

  printf("eluparcettecrapule est un palindrome : %d\n", estPalindrome("eluparcettecrapule"));
  printf("eluparcettecrapules est un palindrome : %d\n", estPalindrome("eluparcettecrapules"));
  printf("\n");

  printf("%d\n", valeurDecimale("245"));

  char chaine[100];
  intVersChaine(421, chaine);
  printf("%s\n", chaine);

  free(chaine_retournee);
  free(chaine_maj);
  free(chaine_min);
  free(chaine_inv);

  return 0;
}


int myStrlen(char* chaine) {
  int i=0;
  while (chaine[i] != '\0') {
    i++;
  }

  return i;
}

char* myStrcpy(char* chaine1, char* chaine2) {
  int i=0;
  for (i=0; chaine1[i] != '\0'; i++) {
    chaine2[i] = chaine1[i];
  }
  chaine2[i] = chaine1[i];

  return chaine2;
}

void affichageHexa(char* chaine) {
  for (int i=0; i<myStrlen(chaine); i++) {
    printf("%x ", chaine[i]);
  }
}

void affichageDec(char* chaine) {
  for (int i=0; i<myStrlen(chaine); i++) {
    printf("%d ", chaine[i]);
  }
}

char* mettreEnMaj(char* chaine) {
  int i=0;
  char *chaine_maj;
  chaine_maj = malloc(myStrlen(chaine));

  for (i=0; chaine[i] != '\0'; i++) {
    chaine_maj[i] = toupper(chaine[i]);
  }
  chaine_maj[i] = '\0';

  return chaine_maj;

}

char* mettreEnMin(char* chaine) {
  int i=0;
  char *a;
  a = malloc(myStrlen(chaine));

  for (i=0; chaine[i] != '\0'; i++) {
    a[i] = tolower(chaine[i]);
  }
  a[i] = '\0';

  return a;

}

char* inverserMinMaj(char* chaine) {
  int i=0;
  char *chaine_final;
  chaine_final = malloc(myStrlen(chaine));

  for (i=0; chaine[i] != '\0'; i++) {
    if (chaine[i] >= 'a' && chaine[i] <= 'z') {
      chaine_final[i] = toupper(chaine[i]);
    } else {
      chaine_final[i] = tolower(chaine[i]);
    }
  }
  chaine_final[i] = '\0';

  return chaine_final;

}

char* retournerMot(char* chaine) {
  int i=0;
  int taille = myStrlen(chaine);
  char *chaine_final;
  chaine_final = malloc(taille);

  for (i=0; i<myStrlen(chaine); i++) {
    chaine_final[i] = chaine[taille-i-1];
  }
  chaine_final[i] = '\0';

  return chaine_final;

}

int rechercheCaractereG(char* chaine, char caractere) {
  for (int i=0; chaine[i] != '\0'; i++) {
    if (chaine[i] == caractere) {
      return i;
    }
  }

  return -1;

}

int rechercheCaractereD(char* chaine, char caractere) {
  for (int i=myStrlen(chaine); i >= 0; i--) {
    if (chaine[i] == caractere) {
      return i;
    }
  }

  return -1;

}

int estPalindrome(char* chaine) {
  int res;
  char* chaine2;
  chaine2 = retournerMot(chaine);
  if (!comparerChaine(chaine, chaine2)) {
    res = 1;
  } else {
    res = 0;
  }

  return res;
}

int comparerChaine(char* chaine1, char* chaine2) {
  //On vérifie que les deux chaines soient de meme taille
  if (myStrlen(chaine1) != myStrlen(chaine2)) {
    printf("Les deux chaines doivent etre de meme taille\n");
    return 0;
  }

  int res=0, somme1=0, somme2=0;
  for (int i=0; chaine1[i] != '\0'; i++) {
    somme1+=chaine1[i];
    somme2+=chaine2[i];
    if (chaine1[i] != chaine2[i]) {
      res = -1;
      break;
    }
  }

  if (res==-1 && somme1 > somme2) {
    res = 1;
  }


  return res;
}

int valeurDecimale(char* chaine) {
  return strtol(chaine, NULL, 10);
}

void intVersChaine(int nb, char* chaine) {
  sprintf(chaine, "%d", nb);
}
