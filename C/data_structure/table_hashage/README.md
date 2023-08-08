# README

## Fonctionnalités

* Afficher tous les produits gérés par le magasin
* Afficher le prix pour un produit donné
* Ajouter des produits
* Supprimer des produits
* Modifier le prix ou le libellé d'un produit existant
* Réorganiser la table de hachage
* Rechercher la liste des produits contenant une certaine chaîne de caractère

## Table de hachage

* Dans un tableau en mémoire initialisé au démarrage du programme et accessible par une variable globale
* Taille fixe de 1009 éléments, ne peut pas être modifiée. 
* Toutes les entrées du tableaux sont initialisés au démarrage du programme.
* Le magasin contient habituellement environ 500 produits. 
* Pour chaque entrée du tableau, trois cas seront possibles :
    * l'entrée du tableau est vide (NULL_ITEM)
    * l'entrée du tableau contient un élément supprimé (DELETED_ITEM)
    * l'entrée du tableau contient un élément standard (USED_ITEM)