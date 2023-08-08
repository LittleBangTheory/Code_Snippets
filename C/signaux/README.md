# README

## Count
`count.c` creates two processes, one parent and it's child. The two processes are synchronized via signals, in order for the father to print only the odd numbers, and the child to print only the even numbers, between 1 and 100. 

The output looks like this : 
```
Je suis le processus pere de pid 8765
1
2
3
...
98
99
100
end of parent process
```	

## Clock
`clock.c` creates a clock with communicating processes. For experimental reasons, 1 minutes lasts 5 seconds and 1 hour lasts 5 minutes. These values can be modified at line 23 and 36 for minutes and hours respectively.
There is one function for each process in order to sychronize the processes.

## Russian roulette
`roulette.c` creates a parent process and 6 children, each identified by a number between 1 and 6, and paused after creation. The parent creates a file named `barillet.txt` and writes a number between 1 and 6 in it, then wakes up each child in turn. If the number in the file equals the child's id, it kills itslelf and informs the father, otherwise it goes back to sleep.

The output looks like this :
```
Je suis le processus pere de pid 8803

La valeur du barillet est 5

On fait jouer le processus 1 de pid 8804 
On fait jouer le processus 2 de pid 8805 
On fait jouer le processus 3 de pid 8806 
On fait jouer le processus 4 de pid 8807 
On fait jouer le processus 5 de pid 8808 

Le processus 5 est mort

On met fin au jeu pour le processus 6 de pid 8809 
```