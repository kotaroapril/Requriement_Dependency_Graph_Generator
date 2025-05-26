#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/parse.h"
#include "../include/dependency_map.h"

int main(int argc, char *argv[]) {

    printf("Requirement Dependency Graph Generator\n");
    

    char filename[256];
    
    if (argc > 1) {
        // If a filename is provided as a command line argument, use it
        strncpy(filename, argv[1], sizeof(filename) - 1);
        filename[sizeof(filename) - 1] = '\0'; // Ensure null termination
    } else {
        // Otherwise, prompt the user for a filename
        while (1) {
            printf("Enter the full path to the .txt or .md file: ");
            if (!fgets(filename, sizeof(filename), stdin)) {
                printf("Error reading input.\n");
                continue;
            }
            filename[strcspn(filename, "\n")] = 0; // Remove newline
            if (strlen(filename) == 0) {
                printf("Filename cannot be empty.\n");
                continue;
            }
            break;
        }
    }
    
    // Check if the file exists
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: File '%s' does not exist.\n", filename);
        return 1;
    }

    //Print the specified filename and the first three lines of the file
    printf("Processing file: %s\n", filename);
    
    FILE *report = fopen("rdgg-report-57045714.md", "w");
    if (!report) {
        fprintf(stderr, "Could not open report file for writing.\n");
        return 1;
    }
    
    fclose(file); // Close the file after reading the first three lines

    // Create the map dependency
    MapDependency *map = create_map_dependency();

    // Parse the file to extract dependencies
    parse_file(filename, map, report);
    fclose(report);

    // Free memory
    free_map_dependency(map);

    return 0;
}