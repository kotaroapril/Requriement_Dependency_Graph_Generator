#ifndef MAP_DEPENDENCY_H
#define MAP_DEPENDENCY_H


typedef struct DependencyNode {
    char *filename;
    struct DependencyNode *next;
} DependencyNode;

typedef struct FileNode {
    char *filename;                   // the main file name
    DependencyNode *dependencies;    // linked list of dependencies
    struct FileNode *next;
} FileNode;

typedef struct MapDependency {
    FileNode *head;                  // head of the linked list of files
} MapDependency;


MapDependency* create_map_dependency();
int is_map_dependency_empty(MapDependency *map);
int add_dependency(MapDependency *map, const char *filename, const char *dependency);   
char** get_dependencies(MapDependency *map, const char *filename, int *count);
void free_map_dependency(MapDependency *map);

#endif