#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/io.h"

void user_input(char *filename, size_t size) {
    
    while (1) {
        printf("Enter the full path to the .txt or .md file: ");
        if (!fgets(filename, (int)size, stdin)) {
            printf("Error reading input.\n");
            continue;
        }
        filename[strcspn(filename, "\n")] = 0; // Remove newline
        if (strlen(filename) == 0) {
            printf("Filename cannot be empty.\n");
            continue;
        }
        FILE *file = fopen(filename, "r");
        if (!file) {
            fprintf(stderr, "Error: File '%s' does not exist.\n", filename);
            continue;
        }
        fclose(file);
        break;
    }

    printf("Processing file: %s\n", filename);
    return; // Return the filename to the caller
}

FILE* create_report_file(const char *report_filename) {
    FILE *report = fopen(report_filename, "w");
    if (!report) {
        fprintf(stderr, "Could not open report file for writing.\n");
        return NULL;
    }
    return report;
    fclose(report);
}