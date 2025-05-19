#ifndef DEPENDENCY_MAP_H
#define DEPENDENCY_MAP_H


typedef struct DependencyNode {
    char *child_ID;
    struct DependencyNode *next;
} DependencyNode;

typedef struct FileNode {
    char *parent_ID;                   
    DependencyNode *children;    // linked list of dependencies
    struct FileNode *next;
} FileNode;

typedef struct MapDependency {
    FileNode *head;                  // head of the linked list of files
} MapDependency;


MapDependency* create_map_dependency();
int is_map_dependency_empty(MapDependency *map);
int add_dependency(MapDependency *map, const char *parent_ID, const char *child_ID);
int is_in_map(MapDependency *map, const char *child_ID);   
char** get_dependencies(MapDependency *map, const char *parent_ID, int *count);
void free_map_dependency(MapDependency *map);

#endif