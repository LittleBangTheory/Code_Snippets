# README

## Fonctionnement

* Le processus père écrit un message dans un segment de mémoire partagée.
* Il crée un processus fils qui affiche le contenu du segment (attaché en lecture)
* Le processus père attend la fin du fils 
* Il détache le segment et le détruit