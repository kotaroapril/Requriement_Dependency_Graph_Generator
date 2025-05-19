#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/sort_dependencies.h"
#include "../include/dependency_map.h"

void sort_dependencies(MapDependency *map) {
    /* 
        Sort the dependencies in the map
        Use a topological sort algorithm to make sure that dependencies are resolved before their dependents
    */
    printf("Sorting dependencies...\n");
}