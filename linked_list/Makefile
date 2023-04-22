CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJECTS = linkedlist.o main.o

all: program

program: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o program

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c -o linkedlist.o

main.o: main.c linkedlist.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f $(OBJECTS) program
