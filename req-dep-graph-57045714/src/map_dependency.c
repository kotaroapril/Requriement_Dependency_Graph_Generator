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
        Head is NULL?
        Return 1 if yes, 0 otherwise
    */
}

// Add a dependency to the map
int add_dependency(MapDependency *map, const char *filename, const char *dependency_filename) {
    /* 
        Call is_map_dependency_empty to check if the map for the filename is empty
        If retrurns 1, create a new file node and set dependency_filename as the first dependency/head

        Call is_file_in_map to check if the dependency_filename is already in the filename's dependencies
        If it is, return 0

        If it is not, create a FileNode for the dependency_filename and add it to the list of dependencies
        Return 1 if the dependency was added successfully, 0 otherwise
    */

}

// Check if the file is already in the map
int is_file_in_map(MapDependency *map, const char *filename) {
    /*
        Traverse the map to check if the file is already in the map
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