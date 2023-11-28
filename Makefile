NAME=fcal

.SUFFIXES:
.SUFFISEX: .c .o

CC=clang
CFLAGS=-Wall -Wextra -O3 -pedantic
SRC_DIR=src
OBJ_DIR=out
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
OBJDIR=out

all: fcal

fcal: $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -fr $(OBJ_DIR)
	rm -f  $(NAME)
