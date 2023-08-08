CC=gcc
CFLAGS=-Wall -ansi -pedantic
LDFLAGS=-lX11 -L/usr/include/X11
EXEC=ex4
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

ex4: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

graphlib.o: graphlib.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
