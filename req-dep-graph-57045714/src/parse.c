#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/parse.h"
#include "../include/seen_set.h"
#include "../include/dependency_map.h"

void parse_file (const char *filename, MapDependency *map, SeenSet *seen_set) {
    
    const char *current_file = filename;

    // Check is filename is in seen set already
    if (is_in_seen_set(seen_set, current_file)) {
        return; // File already seen, no need to parse again
    }
    
    // Add the initial file to the seen set
    add_to_seen_set(seen_set, current_file);

    /* 
        Open the current_file
        
        For each line in the current_file:
            - Ignore empty lines or comments
            - Does line has #include  
                - if yes, extract the dependency_filename from the line
                - Add the dependency_filename to the map (add_dependency(map, current_file, dependency_filename))
                - Recursively call parse_file on the dependency_filename
            - If no, continue to the next line
        Close the current_file
       
    */
    printf("Parsing file: %s\n", current_file);
}
