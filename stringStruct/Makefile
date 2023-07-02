CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.o myString.o
	$(CC) $(CFLAGS) main.o myString.o -o main

main.o: main.c myString.h
	$(CC) $(CFLAGS) -c main.c

myString.o: myString.c myString.h
	$(CC) $(CFLAGS) -c myString.c

run: main
	./main

clean:
	rm -f main *.o
