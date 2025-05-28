#ifndef DEPENDENCY_MAP_H
#define DEPENDENCY_MAP_H

typedef struct ParentNode {
    char *parent_ID;          // ID of the parent
    int parent_line_number;   // line number in the file where the parent_ID was found
    struct ParentNode *next;
} ParentNode;

typedef struct ChildrenNode {
    char *child_ID;
    int child_line_number;  // line number in the file where the child_ID was found
    struct ChildrenNode *next;
} ChildrenNode;

typedef struct FileNode {
    char *req_ID;        
    int reqID_line_number;;                  
    ChildrenNode *children;   // linked list of children
    ParentNode *parents;    // linked list of parents
    struct FileNode *next;
} FileNode;

typedef struct MapDependency {
    FileNode *head;                  // head of the linked list of files
} MapDependency;


MapDependency* create_map_dependency();
FileNode* find_reqID(MapDependency *map, const char *req_ID);
ParentNode* find_parentID(FileNode *req_ID, const char *parent_ID);
ChildrenNode* find_childID(FileNode *req_ID, const char *child_ID);
int is_map_dependency_empty(MapDependency *map);
int is_reqID_in_map(MapDependency *map, const char *parent_ID);
int is_parentID_added(FileNode *req_ID, const char *parent_ID);
int is_childID_added(FileNode *req_ID, const char *child_ID);
int add_reqID(MapDependency *map, const char *req_ID, int reqID_line_number);
int add_parent(MapDependency *map, const char *req_ID, const char *parent_ID, int parent_line_number);  
int add_child(MapDependency *map, const char *req_ID, const char *child_ID, int child_line_number);
void free_map_dependency(MapDependency *map);
void print_map_dependency(MapDependency *map);

#endif