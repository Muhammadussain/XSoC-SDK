CC=gcc
CFLAGS=-Iinclude -Wall
SRC=src/babykyber.c src/babykyber_hal.c
OBJ=$(SRC:.c=.o)
TARGET=babykyber_demo

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
