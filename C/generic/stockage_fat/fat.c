#ifndef FATH
#define FATH
#include "fat.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

void fonction_test()
{
    struct objet* recherche = NULL;
    int i = 0;
    unsigned short auteur = 1;
    char tab[200000];

    for (i = 0; i < 200000; i++)
    {
        tab[i] = 'A';
    }

    initialise_fat();
    printf("\nOn veut creer l'objet test1 de taille 200 000 : \n");
    creer_objet("test1", auteur, 200000, tab);
    printf("On veut creer l'objet test2 de taille 200 000 : \n");
    creer_objet("test2", auteur, 200000, tab);
    printf("On veut creer l'objet test3 de taille 200 000 : \n");
    creer_objet("test3", auteur, 200000, tab);

    printf("\nOn recherche l'objet test2 : \n");
    recherche = rechercher_objet("test2");
    if (recherche == NULL)
    {
        printf("L'objet n'existe pas\n");
    }
    else
    {
        printf("L'objet existe\n");
    }

    printf("On recherche l'objet test3 : \n");
    recherche = rechercher_objet("test3");
    if (recherche == NULL)
    {
        printf("L'objet n'existe pas\n");
    }
    else
    {
        printf("L'objet existe\n");
    }

    printf("\nOn veut supprimer tous les objets de la liste : \n");
    supprimer_tout();

    printf("\nOn recherche l'objet test2 : \n");
    recherche = rechercher_objet("test2");
    if (recherche == NULL)
    {
        printf("L'objet n'existe pas\n");
    }
    else
    {
        printf("L'objet existe\n");
    }


    printf("\n\nOn veut creer l'objet test4 de taille 200 000 : \n");
    creer_objet("test4", auteur, 200000, tab);
    printf("On veut creer l'objet test5 de taille 200 000 : \n");
    creer_objet("test5", auteur, 200000, tab);

    printf("\nOn veut supprimer l'objet test1 de la liste : \n");
    supprimer_objet("test1");
    printf("On veut supprimer l'objet test4 de la liste : \n");
    supprimer_objet("test4");

    printf("\nOn recherche l'objet test4 : \n");
    recherche = rechercher_objet("test4");
    if (recherche == NULL)
    {
        printf("L'objet n'existe pas\n");
    }
    else
    {
        printf("L'objet existe\n");
    }
    printf("On recherche l'objet test5 : \n");
    recherche = rechercher_objet("test5");
    if (recherche == NULL)
    {
        printf("L'objet n'existe pas\n");
    }
    else
    {
        printf("L'objet existe\n");
    }

    printf("\nOn veut supprimer tous les objets de la liste : \n");
    supprimer_tout();
    printf("On veut supprimer tous les objets de la liste : \n");
    supprimer_tout();
}



void initialise_fat()
{
    int i;
    for (i = 0; i < BLOCNUM; i++)
    {
        //On indique que tous les blocs sont libres
        FAT[i] = 0xFFFF;
    }
    //On indique qu'il y autant de blocs libre que de blocs existant
    freeblocks = BLOCNUM;
    //On reinitialise le pointeur vers la liste chainee
    obj = NULL;
}



struct objet* rechercher_objet(char* nom)
{

    struct objet* curseur = obj;

    //Tant qu'on n'est pas a la fin de la liste chainee et que le nom a rechercher n'es^t pas celui du maillon courant
    while (curseur != NULL && strcmp(nom, curseur->nom) != 0)
    {
        //On passe au maillon suivant dans la liste chainee
        curseur = curseur->next;
    }
    //On renvoi le pointeur vers le bon maillon
    return curseur;
}



struct objet* creer_objet(char* nom, unsigned short auteur, unsigned int taille, char* data)
{

    unsigned short bloc_need = 0, i = 0, j=0, memoire_index = 0, indice_data=0;
    unsigned short index_premier_bloc = BLOCNUM; /*On l'initialise � BLOCNUM pour pouvoir le changer plus loin dans le programme, car 1024 ne peut pas etre un indice de FAT */
    struct objet* objet_new = NULL;
    unsigned int taille_restante = taille;
    char copied_data[BLOCSIZE];

    //On s'assure de ne pas creer un objet du meme nom qu'un objet existant
    if (rechercher_objet(nom) == NULL)
    {
        //Si la taille de l'objet n'est pas un multiple de 512 octets, on aura un bloc partiellement vide
        if (taille % BLOCSIZE != 0) /* On determine le nombre de blocks necessaires pour stocker les donnees */
        {
            bloc_need = taille / BLOCSIZE + 1;
        }
        //Sinon, on a pile le bon nombre de blocs
        else
        {
            bloc_need = taille / BLOCSIZE;
        }
        //On continue si le nombre de blocs libres est superieur aux besoins du nouvel objet
        if (freeblocks - bloc_need > 0)
        {
            //On alloue un emplacemet memoire de la taille de la structure generique au nouvel objet et on verifie que l'allocation a fonctionne
            objet_new = malloc(sizeof(struct objet));
            if (objet_new == NULL)
            {
                printf("Erreur malloc\n");
                return NULL;
            }
            //On decremente freeblocks du nombre de blocs qu'on vient d'utiliser
            freeblocks -= bloc_need;

            //On rempli tous nos blocs reserves
            while (bloc_need != 0)
            {
                //Seulement si ils sont libres
                if (FAT[i] == 0xFFFF)
                {
                    //Si on est en train de reserver le premier bloc de l'objet, on retient son index en memoire
                    if (index_premier_bloc == BLOCNUM)
                    {
                        index_premier_bloc = i;
                    }
                    //Sinon, on peut passer a FAT l'indince du prochain bloc de donnee
                    else
                    {
                        FAT[memoire_index] = i;
                    }

                    memoire_index = i;
                    bloc_need--;
                    //Si on est au dernier bloc de l'objet, on lui passe la valeur 0xFFFE
                    if (bloc_need == 0)
                    {
                        FAT[i] = 0xFFFE;
                    }
                    //Si la taille des donnees qu'il reste a stocker est superieure a la taille d'un bloc
                    if (taille_restante / BLOCSIZE >= 1)
                    {
                        //On rempli notre tableau temporaire avec les donnees a mettre dans le bloc
                        for (j = 0; j < BLOCSIZE; j++)
                        {
                            copied_data[j] = data[j + indice_data];
                        }
                        //On copie les donnees dans le volume
                        memcpy(&volume[BLOCSIZE * i], copied_data, BLOCSIZE);
                        indice_data += BLOCSIZE;
                        taille_restante -= BLOCSIZE;
                    }
                    else
                    {
                        //On rempli notre tableau temporaire avec les donnees restantes
                        while (j<(sizeof(data)/sizeof(char)))
                        {
                            copied_data[j] = data[j + indice_data];
                            j++;
                        }
                        //On copie les donnees restantes dans le volume
                        memcpy(&volume[BLOCSIZE * i], data, taille % BLOCSIZE);
                    }

                }
                i++;
            }
            //On copie dans le maillon les informations de l'objet
            strcpy(objet_new->nom, nom);
            objet_new->auteur = auteur;
            objet_new->taille = taille;
            objet_new->index = index_premier_bloc;
            objet_new->next = obj; /* On ajoute le nouvel objet en tete de liste */

            obj = objet_new; /* On ajoute le nouvel objet en tete de liste */

            printf("Nouvel objet cree\n");
        }
        else
        {
            printf("Il n'y a pas assez d'espace memoire disponible pour creer le nouvel objet\n");
        }

    }
    else
    {
        printf("L'objet que vous voulez creer existe deja\n");
    }
    return objet_new;

}



int supprimer_objet(char* nom)
{
    struct objet* obj_sup, * obj_prec;
    unsigned short i = 0, index_bloc_suivant = 0, bloc_free = 0;

    obj_sup = rechercher_objet(nom);

    //Si l'objet a supprimer exist
    if (obj_sup != NULL)
    {
        //On recupere l'indice de l'objet a supprimer
        i = obj_sup->index;

        //Tant qu'on n'est pas a la fin de la suite de blocs
        while (FAT[i] != 0xFFFE)
        {
            //On recupere l'indice du bloc suivant stock� dans le tableau FAT
            index_bloc_suivant = FAT[i];
            //On definit le bloc courant comme libre en ecriture
            FAT[i] = 0xFFFF;
            //On passe au bloc suivant
            i = index_bloc_suivant;
            bloc_free++;
        }
        bloc_free++;
        FAT[i] = 0xFFFF;
        freeblocks += bloc_free;
        //Si l'objet a supprimer est en tete de liste
        if (obj_sup == obj)
        {
            obj = obj_sup->next;
        }
        //Si l'objet a supprimer est ailleurs dans la liste
        else
        {
            obj_prec = obj;
            while (obj_prec->next != obj_sup)
            {
                //On regarde l'objet suivant
                obj_prec = obj_prec->next;
            }
            obj_prec->next = obj_sup->next;
        }
        //On libere l'emplacement memoire alloue pour l'objet a supprimer
        free(obj_sup);
        printf("L'objet a ete supprime\n");
    }
    else
    {
        printf("L'objet que vous voulez supprimer n'existe pas\n");
        return -1;
    }
    return 0;
}



void supprimer_tout()
{
    struct objet* obj_sup = NULL;

    //On verifie qu'il y a bien des objets dans la liste
    if (obj == NULL)
    {
        printf("La liste d'objets est d�j� vide\n");
    }
    else
    {
        //Tant que le pointeur de fin de liste chainee n'est pas nul
        while (obj != NULL)
        {
            //On supprime l'objet courant et on se deplace sur le suivant
            obj_sup = obj;
            obj = obj->next;
            free(obj_sup);
        }
        //On initialise la liste chainee
        initialise_fat();
        printf("Tous les objets ont ete supprimes\n");
    }
}
