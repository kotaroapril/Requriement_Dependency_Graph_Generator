#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/parse.h"
#include "../include/seen_set.h"
#include "../include/dependency_map.h"

void parse_file (const char *filename, MapDependency *map, SeenSet *seen_set) {
    
    /*      
        For each line in the current_file:
            - Ignore empty lines and comments 
            - Is there a dependency in the line?
                - if yes, extract the dependency_req_ID from the line
                - Add the dependency_req_ID to the map (add_dependency(map, parent_ID, child_ID))
                - Recursively call parse_file with argument dependency_req_ID (parse_file(child_ID, map, seen_set))
            - If no, continue to the next line
    */

    printf("Parsing file: %s\n", filename);
}
