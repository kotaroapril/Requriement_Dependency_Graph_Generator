#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../include/dependency_map.h"


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
        Head is NULL?6a
        Return 1 if yes, 0 otherwise
    */
   printf("is_map_dependency_empty\n");
    return 0;
}

// Add a dependency to the map
int add_dependency(MapDependency *map, const char *parent_ID, const char *child_ID) {
    /* 
        Call is_map_dependency_empty to check if the map for the parent_ID is empty
        If retrurns 1, create a new file node and set child_ID as the first dependency/head

        Call is_file_in_map to check if the child_ID is already in the parent_ID's dependencies
        If it is, return 0

        If it is not, create a FileNode for the child_ID and add it to the list of dependencies
        Return 1 if the dependency was added successfully, 0 otherwise
    */
    printf("add_dependency\n");
    return 0;
}

// Check if the req_ID is already in the map
int is_in_map(MapDependency *map, const char *child_ID) {
    /*
        Traverse the map to check if the child_ID is already in the map
        Return 1 if file is already in map, 0 otherwise
    */
    printf("is_file_in_map\n");
    return 0;
}

//Get the dependencies of a file
char** get_dependencies(MapDependency *map, const char *parent_ID, int *count) {
    /*
        Return the dependencies as an array of strings
        Set the count to the number of dependencies
    */
    printf("get_dependencies\n");
    return NULL;

}

// Free the map dependency
void free_map_dependency(MapDependency *map) {
    /*
        Free all nodes and dependencies in the map
        Free the map itself  
    */

}