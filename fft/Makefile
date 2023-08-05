CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lm

SRC = fft.c
EXECUTABLE = fft

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(EXECUTABLE)
