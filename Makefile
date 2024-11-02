CC = gcc
CFLAGS = -Wall -g -Werror -Ilib

SRC_DIR = src
EXEC = main

SRC_FILES = $(wildcard $(SRC_DIR)/*.c) main.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(EXEC)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXEC)

clean:
	rm -f $(SRC_DIR)/*.o $(EXEC) $(EXEC).log
