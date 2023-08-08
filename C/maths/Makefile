CC=gcc
CFLAGS=-Wall -ansi -pedantic
EXEC=ex3
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

ex3: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf *.o
