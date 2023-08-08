CC=gcc
CFLAGS=-Wall -Wextra -pedantic
LDFLAGS=
EXEC=fraction
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

fraction: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o
