/******************************************************************************
 * Fichier d'entete du module gestion de stock d'un magasin
 * avec une table de hachage
 ******************************************************************************/

#include <stdbool.h>
#include <stdint.h>


/*----------------------------------------------------------------------------
 * Parametres globaux
 *----------------------------------------------------------------------------*/
#define TABLE_SIZE			  10
#define NULL_ITEM             4
#define DELETED_ITEM          2
#define USED_ITEM             1
#define DIRTY_ITEM            1
#define CLEAN_ITEM            0
#define ITEM_NAME_SIZE        32

/*----------------------------------------------------------------------------
 * Definition des constantes pour les retours des fonctions
 *----------------------------------------------------------------------------*/
#define SUCCESS                 0
#define INSERT_ALREADY_EXIST   -1
#define TABLE_FULL             -2
#define SELECT_NO_ROW          -3
#define DELETE_NO_ROW          -4
#define UPDATE_NO_ROW          -5


/*----------------------------------------------------------------------------
 * Definition de la structure d'un produit
 * Chaque produit est identifié par 3 champs :
 *     - son code sur 5 chiffres
 *     - son libellé
 *     - son prix en euros
 *
 *----------------------------------------------------------------------------*/
typedef struct structItem
{
	uint8_t status;  
	uint32_t code;
	char name[ITEM_NAME_SIZE];
	float price;
	uint8_t dirty; 
} Item;

/*----------------------------------------------------------------------------
 * Definition de la structure resultat (Liste chainée)
 * Chaque resultat est identifié par 2 champs :
 *     - un item (pointeur)
 *     - un pointeur vers un autre résultat
 *----------------------------------------------------------------------------*/
typedef struct structResult
{
	Item* item;
	struct structResult* next;
} Result;

/*----------------------------------------------------------------------------
 * Cette fonction initialise un tableau hash_table
 *----------------------------------------------------------------------------*/
void init();


/*----------------------------------------------------------------------------
 * Cette fonction calcule la valeur de hachage pour le produit itemCode
 *----------------------------------------------------------------------------*/
uint32_t hashkey(uint32_t itemCode, uint32_t nbTry); 

/*----------------------------------------------------------------------------
 * Cette fonction insère le produit indiqué dans la table de hachage.
 * Si le produit est inséré avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit existe déjà dans la table, alors la fonction retourne INSERT_ALREADY_EXIST (-1),
 * et la table de hachage n'est pas modifiée
 * Si la table est pleine, alors la fonction retourne TABLE_FULL (-2).
 *----------------------------------------------------------------------------*/
int insertItem(uint32_t  itemCode, char* itemName, float itemPrice);

/*----------------------------------------------------------------------------
 * fonction de suppression d'un produit du magasin
 * Si le produit est supprimé avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne DELETE_NO_ROW (-4)
 *----------------------------------------------------------------------------*/
int suppressItem(unsigned int itemCode);

/*----------------------------------------------------------------------------
 * Pour chaque produit, cette fonction affiche sur une ligne
 * le code du produit
 * son libellé
 * son prix
 * son index dans la table de hashage
 * sa valeur de hash
 *----------------------------------------------------------------------------*/
void dumpItems();


/*----------------------------------------------------------------------------
 * Cette fonction trouve le produit dont le code est itemCode.
 * Cette fonction retourne NULL si le produit n'existe pas.
 * Cette fonction retourne un pointeur vers le produit si le produit existe.
 *----------------------------------------------------------------------------*/
Item *getItem(unsigned int itemCode);

/*----------------------------------------------------------------------------
 *  fonction de mise à jour d'un produit :
 * Si le produit est mis à jour avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne UPDATE_NO_ROW (-5)
 *----------------------------------------------------------------------------*/
int updateItem(unsigned int itemCode, char *itemName, float itemPrice);


/*----------------------------------------------------------------------------
 * la fonction de réorganisation in situ:
 *----------------------------------------------------------------------------*/
void rebuildTable();

/*----------------------------------------------------------------------------
 * la fonction de recherche d'un prix d'un produit:
 *----------------------------------------------------------------------------*/
float getPrice(int itemCode);

/*----------------------------------------------------------------------------
 * Recherche les items et les mets dans une liste chainee de Result
 *----------------------------------------------------------------------------*/
Result* findItem(char* itemName);

/*----------------------------------------------------------------------------
 * Recherche les items et les mets dans une liste chainee de Result d'une autre manière
 *----------------------------------------------------------------------------*/
Result *findItemWithIndex(char* itemName);