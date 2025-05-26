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
    MapDependency *map = (MapDependency *)malloc(sizeof(MapDependency));
    if (map == NULL) {
        fprintf(stderr, "Memory allocation failed for MapDependency\n");
        return NULL;
    }
    map->head = NULL; // Initialize the head to NULL
    return map;
}

// Check if the map dependency is empty
int is_map_dependency_empty(MapDependency *map) {
    /*
        Head is NULL?6a
        Return 1 if yes, 0 otherwise
    */
    if (map == NULL || map->head == NULL) {
        printf("is_map_dependency_empty: Map is empty\n");
        return 1; // Map is empty
    }
    else {
        printf("is_map_dependency_empty: Map is not empty\n");
        return 0; // Map is not empty
    }
}

// Check if the parent_ID is already in the map
int is_parent_in_map(MapDependency *map, const char *parent_ID) {
    FileNode *current = map->head;
    while (current != NULL) {
        if (strcmp(current->parent_ID, parent_ID) == 0) {
            return 1; // Parent exists
        }
        current = current->next;
    }
    return 0; // Not found
}

// Check if the child_ID is already in the map
int is_child_in_parent(FileNode *parent, const char *child_ID) {
    DependencyNode *dep = parent->children;
    while (dep != NULL) {
        if (strcmp(dep->child_ID, child_ID) == 0) {
            return 1; // Child exists
        }
        dep = dep->next;
    }
    return 0; // Not found
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
    if (!map || !parent_ID || !child_ID) return 0;

    // Find or create the parent node
    FileNode *parent = map->head;
    FileNode *prev = NULL;
    while (parent && strcmp(parent->parent_ID, parent_ID) != 0) {
        prev = parent;
        parent = parent->next;
    }
    if (!parent) {
        parent = (FileNode *)malloc(sizeof(FileNode));
        parent->parent_ID = strdup(parent_ID);
        parent->children = NULL;
        parent->next = NULL;
        if (prev) prev->next = parent;
        else map->head = parent;
    }

    // Check if child_ID already exists in parent's children
    if (is_child_in_parent(parent, child_ID)) {
        return 0; // Already a dependency
    }

    // Add new dependency
    DependencyNode *new_dep = (DependencyNode *)malloc(sizeof(DependencyNode));
    new_dep->child_ID = strdup(child_ID);
    new_dep->next = parent->children;
    parent->children = new_dep;
    return 1;  
}

//Get the dependencies of a file
char** get_dependencies(MapDependency *map, const char *parent_ID, int *count) {
    /*
        Return the dependencies as an array of strings
        Set the count to the number of dependencies
    */
    *count = 0;
    FileNode *parent = map->head;
    while (parent && strcmp(parent->parent_ID, parent_ID) != 0) {
        parent = parent->next;
    }
    if (!parent) return NULL;

    // Count dependencies
    DependencyNode *dep = parent->children;
    while (dep) {
        (*count)++;
        dep = dep->next;
    }
    if (*count == 0) return NULL;

    // Collect dependencies
    char **deps = (char **)malloc((*count) * sizeof(char *));
    dep = parent->children;
    int i = 0;
    while (dep) {
        deps[i++] = dep->child_ID;
        dep = dep->next;
    }
    return deps;

}

// Free the map dependency
void free_map_dependency(MapDependency *map) {
    /*
        Free all nodes and dependencies in the map
        Free the map itself  
    */
    if (!map) return;
    FileNode *file = map->head;
    while (file) {
        FileNode *next_file = file->next;
        free(file->parent_ID);
        DependencyNode *dep = file->children;
        while (dep) {
            DependencyNode *next_dep = dep->next;
            free(dep->child_ID);
            free(dep);
            dep = next_dep;
        }
        free(file);
        file = next_file;
    }
    free(map);
}