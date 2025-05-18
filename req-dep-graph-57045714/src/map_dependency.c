#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/map_dependency.h"


// Initialize an empty map dependency
MapDependency* create_map_dependency() {
    /*
        Allocate memory for the map dependency
        Set head to NULL
        Return the map dependency
    */
}

// Check if the map dependency is empty
int is_map_dependency_empty(MapDependency *map) {
    /*
        Return 1 if empty, 0 otherwise
    */
}

// Add a dependency to the map
int add_dependency(MapDependency *map, const char *filename, const char *dependency) {
    /* 
        Is the file already in the map?
        If it is, add the dependency to the file
        If it is not, create a new file node and add it to the map
        Add the dependency to the file node
        Return 1 if the dependency was added successfully, 0 otherwise
    */

}

// Check if the file is already in the map
int is_file_in_map(MapDependency *map, const char *filename) {
    /*
        Return 1 if file is already in map, 0 otherwise
    */
    return 0;
}

//Get the dependencies of a file
char** get_dependencies(MapDependency *map, const char *filename, int *count) {
    /*
        Return the dependencies as an array of strings
        Set the count to the number of dependencies
    */
    return NULL;

}

// Free the map dependency
void free_map_dependency(MapDependency *map) {
    /*
        Free all nodes and dependencies in the map
        Free the map itself  
    */

}