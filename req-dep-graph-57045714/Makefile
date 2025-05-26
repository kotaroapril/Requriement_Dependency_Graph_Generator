# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source and output
SRC_DIR = src
BUILD_DIR = build
OUT = $(BUILD_DIR)/dependency_tree

# All C source files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SRC)))

# Include directories
INCLUDES = -I$(SRC_DIR) -Iinclude

# Default target
all: $(OUT)

# Link object files into final binary
$(OUT): $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	 rm -rf $(BUILD_DIR)

.PHONY: all clean run