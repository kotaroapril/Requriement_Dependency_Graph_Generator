# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source and output
SRC_DIR = src
INCLUDE_DIR = include
OUT = rdgg-57045714.exe

# All C source files
SRC = $(wildcard $(SRC_DIR)/*.c)

# Include directories
INCLUDES = -I$(INCLUDE_DIR)

# Default target
all: $(OUT)

# Link object files into final binary
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

# Clean build artifacts
clean:
	del /Q *.exe 2>nul

.PHONY: all clean