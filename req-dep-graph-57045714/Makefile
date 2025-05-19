# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source and output
SRC_DIR = src
BUILD_DIR = build
OUT = $(BUILD_DIR)/depedenecy_tree

# All C source files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(subst $(SRC_DIR)/,,$(SRC)))

# Include directories
INCLUDES = -I$(SRC_DIR) -Iinclude

# Default target
all: $(OUT)

# Link object files into final binary
$(OUT): $(OBJ)
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)

.PHONY: all clean run