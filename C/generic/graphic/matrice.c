#include <stdio.h>

float afficherMatrice(float matrice[4][4], int colonnes, int lignes){
  for (int i = 0; i < colonnes; i++) {
    for (int j = 0; j < lignes; j++) {
      printf("%.2f ", matrice[i][j]);
    }
    printf("\n");
  }
  return 0;
}


float additionnerMatrices(float matrice1[4][4], float matrice2[4][4], int colonnes, int lignes){
  float matriceFinale[4][4];
  for (int i = 0; i < colonnes; i++) {
    for (int j = 0; j < lignes; j++) {
      matriceFinale[i][j] = matrice1[i][j] + matrice2[i][j];
    }
  }
  afficherMatrice(matriceFinale, colonnes, lignes);
  return 0;
}


float transposee(float matrice[4][4], int colonnes, int lignes){
  float matriceTemp[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matriceTemp[i][j] = matrice[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrice[i][j] = matriceTemp[j][i];
    }
  }
  afficherMatrice(matrice, colonnes, lignes);
  return 0;
}


float produitMatriciel(float matrice1[4][4], float matrice2[4][4], int colonnes, int lignes){
  float matriceFinale[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matriceFinale[i][j]=0;
      for (int k = 0; k < 4; k++) {
          matriceFinale[i][j] += matrice1[i][k]*matrice2[k][j];
      }
    }
  }
  return 0;
}
//ne marche pas


int main(int argc, char const *argv[]) {
  float matrice1[4][4] = {{1, 0, 4}, {-1, 2, -5}};
  float matrice2[4][4] = {{2, -3, 1}, {5, 8, 2}};
  transposee(matrice1, 3, 2);
  return 0;
}
