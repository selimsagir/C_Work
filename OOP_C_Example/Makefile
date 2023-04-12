CC = gcc
CFLAGS = -Wall -Werror

all: main

main: main.o shape.o rect.o
	$(CC) $(CFLAGS) main.o shape.o rect.o -o main

main.o: main.c shape.h rect.h
	$(CC) $(CFLAGS) -c main.c

shape.o: shape.c shape.h
	$(CC) $(CFLAGS) -c shape.c

rect.o: rect.c rect.h shape.h
	$(CC) $(CFLAGS) -c rect.c

clean:
	rm -f *.o main

run: main
	./main