# README

## Arbre binaire de recherche

* Chaque noeud de l'arbre est une instance de la structure `Client`
* L'identifiant de chaque noeud est le numéro de téléphone.

## Algorithmie

* itération sur les lignes de log
* pour chaque ligne de log
    * recherche pour savoir si le client est déjà présent dans l'arbre
    * si il est présent :
        * modification des champs de la structure pour incrémenter le prix et le nombre d'appel
    * si il n'est pas présent :
        * insertion du client dans l'arbre
* fin itération
* parcours infixe sur l'arbre, ce qui permettra d'obtenir la liste triée par numéro de
téléphone croissant, avec le coût pour chaque abonné