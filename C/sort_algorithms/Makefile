
methodes_tri: fonctions.o main.o
	gcc -o methodes_tri fonctions.o main.o -g -fsanitize=address

fonctions.o: fonctions.c
	gcc -o fonctions.o -c fonctions.c -W -Wall -pedantic -g -fsanitize=address

main.o: main.c fonctions.h
	gcc -o main.o -c main.c -W -Wall -pedantic -g -fsanitize=address
