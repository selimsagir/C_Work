CC = gcc
CFLAGS = -Wall -Werror

all: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm -f main

run: all
	./main
