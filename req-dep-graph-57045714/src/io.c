#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/io.h"

// Function to read user input for the filename and validate it
void user_input(char *filename, size_t size) {
    
    while (1) {
        printf("Enter the full path to the file: ");
        if (!fgets(filename, (int)size, stdin)) {
            printf("Error reading input.\n");
            continue;
        }
        filename[strcspn(filename, "\n")] = 0; // Remove newline
        if (strlen(filename) == 0) {
            printf("Path cannot be empty.\n");
            continue;
        }

        FILE *input_file = fopen(filename, "r");

        if (!input_file) {
            fprintf(stderr, "Error: File '%s' does not exist.\n", filename);
            continue;
        }

        printf("IO: Test if the file exists and print the first 3 lines.\n");

        // Print the first 3 lines of the file
        char line[1024];
        int line_num = 0;

        while (line_num < 3 && fgets(line, sizeof(line), input_file)) {
            line_num++;
            printf(line);
        }

        printf("\n");
        fclose(input_file);
        break;
    }
}

// Create and opens an output file for writing.
FILE* create_output_file(const char *output_filename) {
    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Could not open output file for writing.\n");
        return NULL;
    }
    return output_file;
}