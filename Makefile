CC = gcc
CFLAGS = -Wall -g
SRC = src/main.c
OBJ = build/main.o
TARGET = bin/my_program
PROJECT = charCounter

# Default target to build the program
all : $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build/%.o: src/%.c
	$(CC) -c $< -o $@

install:
	sudo cp $(TARGET) /usr/local/bin/$(PROJECT)
	sudo chmod +x /usr/local/bin/$(PROJECT)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
