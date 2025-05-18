#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/parse.h"
#include "../include/seen_set.h"
#include "../include/map_dependency.h"
#include "../include/sort_dependency.h"
#include "../include/draw_diagram.h"

int main() {

    char filename[256];
    MapDependency *map = create_map_dependency();
    SeenSet *seen_set = create_seen_set();
    
    /*  Ask the user for a filename
        If the user enters an empty string, loop back to ask for a filename

        Remove the newline character from the filename

        Check if the file exists
        If it does not exist, print an error message and loop back to ask for a filename
        
        If it exists, break the loop
    */ 

    // Parse the file to extract dependencies
    parse_file(filename, map, seen_set);

    // Sort the dependencies
    sort_dependencies(map);

    // Draw the dependency tree diagram
    draw_diagram(map);

    // Free memory
    free_map_dependency(map);
    free_seen_set(seen_set);

    return 0;
}