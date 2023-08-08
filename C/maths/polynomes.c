#include <stdio.h>

//Code by Noé

#define NBMAX 100

typedef struct 
{
    float coeff; /* Coefficient du terme */
    int degre; /* Degré du terme */
}Terme;

typedef Terme Polynome[NBMAX]; /* Polynome est un tableau de Terme (degré décroissant), dernier terme suivi d'un terme de degré -1 */

void addPolynomes(Polynome p1, Polynome p2, Polynome res)
{
    int k = 0, l = 0, m = 0, finito = 0;

    while(!finito)
    {
        if(p1[l].degre == p2[m].degre)
        {
            res[k].coeff = p1[l].coeff + p2[m].coeff;
            res[k].degre = p1[l].degre;
            l++;
            m++;
        }
        else if(p1[l].degre > p2[m].degre)
        {
            res[k].coeff = p1[l].coeff;
            res[k].degre = p1[l].degre;
            l++;
        }
        else if(p1[l].degre < p2[m].degre)
        {
            res[k].coeff = p2[m].coeff;
            res[k].degre = p2[m].degre;
            m++;
        }

        if(res[k].degre == -1)
            finito = 1;

        k++;
    }

}