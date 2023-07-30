CC = gcc
CFLAGS = -Wall -Wextra

all: main

main: main.o 
	$(CC) $(CFLAGS) main.o   -o main

main.o:  
	$(CC) $(CFLAGS) -c main.c

 

run: main
	./main

clean:
	rm -f main *.o
