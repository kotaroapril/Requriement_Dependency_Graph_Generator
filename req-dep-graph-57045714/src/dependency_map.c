#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../include/dependency_map.h"

/*
    We use linked lists and nodes for the requirement dependency map because we do not know how many requirements or dependencies there will be.
    Linked lists let us add new requirements and their relationships as we find them, without needing to set a fixed size or resize anything. 
    Each requirement is a node in the list, and each node has its own lists for parents and children. 
    This makes it easy to add, find, and remove requirements and their connections.
    Linked lists are also simple to use and work well for the kind of adding and searching we need to do in this project.
*/


// Initialize an empty map dependency
MapDependency* create_map_dependency() {
    /*
        Allocate memory for the map dependency
        Set head to NULL
        Return the map dependency
    */
    MapDependency *map = (MapDependency *)malloc(sizeof(MapDependency));
    if (map == NULL) {
        printf("create_map_dependency: Memory allocation failed\n");
        return NULL;
    }
    map->head = NULL; // Initialize the head to NULL
    return map;
}

// Find a req_ID in the map dependency
FileNode* find_reqID(MapDependency *map, const char *req_ID) {
    FileNode *current = map->head;
    while (current != NULL) {
        if (strcmp(current->req_ID, req_ID) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Find a parent_ID in the list of parents for a given req_ID
ParentNode* find_parentID(FileNode *req_ID, const char *parent_ID) {
    ParentNode *current = req_ID->parents;
    while (current != NULL) {
        if (strcmp(current->parent_ID, parent_ID) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Find a child_ID in the list of children for a given req_ID
ChildrenNode* find_childID(FileNode *req_ID, const char *child_ID) {
    ChildrenNode *current = req_ID->children;
    while (current != NULL) {
        if (strcmp(current->child_ID, child_ID) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Check if the map dependency is empty
int is_map_dependency_empty(MapDependency *map) {
    /*
        Head is NULL?
        Return 1 if yes, 0 otherwise
    */
    if (map == NULL || map->head == NULL) {
        return 1; // Map is empty
    }
    else {
        return 0; // Map is not empty
    }
}

// Check if the req_ID is already in the map
int is_reqID_in_map(MapDependency *map, const char *req_ID) {
    return find_reqID(map, req_ID) != NULL; 
    // Returns 1 if found, 0 if not found
}

// Check if the child_ID is already in the list of children
int is_childID_added(FileNode *req_ID, const char *child_ID) {
    return find_childID(req_ID, child_ID) != NULL;
}

// Check if the parent_ID is already in the list of parents
int is_parentID_added(FileNode *req_ID, const char *parent_ID) {
    return find_parentID(req_ID, parent_ID) != NULL;
}

int add_reqID(MapDependency *map, const char *reqID, int reqID_line_number) {
    /*
        Add a reqID to the map
        If the map is NULL or reqID is NULL, return 0
        If the reqID already exists in the map, return 0
        Create a new FileNode for the reqID and add it to the map
        Return 1 if successfully added, 0 otherwise
    */
    if (!map || !reqID) {
        printf("add_reqID: Invalid map or reqID\n");
        return 0; // Invalid input
    }

    // Check if the reqID is already in the map
    if (is_reqID_in_map(map, reqID)) {
        printf("add_reqID: req_ID %s already exists in the map\n", reqID);
        return 0; // Already exists
    }
    
    // If the reqID does not exist, create a new FileNode
    FileNode *new_reqID = (FileNode *)malloc(sizeof(FileNode)); // Allocate memory for the new FileNode
    
    if (new_reqID == NULL) {
        printf("add_reqID: Memory allocation failed for req_ID %s\n", reqID);
        return 0; // Memory allocation failed
    }
    new_reqID->req_ID = strdup(reqID); // Duplicate the reqID string
    new_reqID->reqID_line_number = reqID_line_number; // Set the line number for the reqID
    new_reqID->children = NULL; // Initialize children to NULL
    new_reqID->parents = NULL; // Initialize parents to NULL
    new_reqID->next = NULL; // Initialize next to NULL

    // Add the new FileNode to the map
    if (is_map_dependency_empty(map)) {
        map->head = new_reqID; // If the map is empty, set head to new_reqID
    } else {
        FileNode *current = map->head;
        while (current->next != NULL) {
            current = current->next; // Traverse to the end of the list
        }
        current->next = new_reqID; // Add new_reqID at the end of the list
    }

    return 1; // Successfully added
}

// Add a parent to the list of parents for a req_ID
int add_parent(MapDependency *map, const char *req_ID, const char *parent_ID, int parent_line_number) {
    
    if (!map || !parent_ID || !req_ID) {
        printf("add_parent: Invalid map, req_ID, or parent_ID\n");
        return 0;
    }

    // Check if the req_ID exists in the map
    FileNode *current_reqID = find_reqID(map, req_ID);
    if (!current_reqID) {
        printf("add_parent: req_ID %s not found in map\n", req_ID);
        return 0;
    }

    // Check if the parent_ID is already in the list of parents for this req_ID
    if (is_parentID_added(current_reqID, parent_ID)) {
        printf("add_parent: parent_ID %s already exists for req_ID %s\n", parent_ID, current_reqID->req_ID);
        return 0;
    }

    // If the parent_ID does not exist, create a new ParentNode
    ParentNode *new_parent = (ParentNode *)malloc(sizeof(ParentNode));
    if (new_parent == NULL) {
        printf("add_parent: Memory allocation failed for parent_ID %s\n", parent_ID);
        return 0;
    }

    new_parent->parent_ID = strdup(parent_ID);
    new_parent->parent_line_number = parent_line_number;
    new_parent->next = NULL;

    // Add the new ParentNode to the list of parents for the req_ID
    if (current_reqID->parents == NULL) {
        current_reqID->parents = new_parent; // If parents list is empty, set it to new_parent
    } else {
        ParentNode *current_parent = current_reqID->parents;
        while (current_parent->next != NULL) {
            current_parent = current_parent->next; // Traverse to the end of the parents list
        }
        current_parent->next = new_parent; // Add new_parent at the end of the list
    }
    return 1;
}

int add_child(MapDependency *map, const char *req_ID, const char *child_ID, int child_line_number) {
    /*
        If the map is NULL or req_ID or child_ID is NULL, return 0
        If the req_ID does not exist in the map, return 0
        If the child_ID already exists in the list of children for this req_ID, return 0
        Create a new ChildrenNode for the child_ID and add it to the list of children for the req_ID
        Return 1 if successfully added, 0 otherwise
    */
    if (!map || !child_ID || !req_ID) {
        printf("add_child: Invalid map, req_ID, or parent_ID\n");
        return 0;
    }

    // Check if the req_ID exists in the map
    FileNode *current_reqID = find_reqID(map, req_ID);
    if (!current_reqID) {
        printf("add_child: req_ID %s not found in map\n", req_ID);
        return 0;
    }

    // Check if the child_ID is already in the list of children for this req_ID
    if (is_childID_added(current_reqID, child_ID)) {
        printf("add_child: child_ID %s already exists for req_ID %s\n", child_ID, current_reqID->req_ID);
        return 0;
    }

    // If the child_ID does not exist, create a new ChildrenNode
    ChildrenNode *new_child = (ChildrenNode *)malloc(sizeof(ChildrenNode));
    if (new_child == NULL) {
        printf("add_child: Memory allocation failed for parent_ID %s\n", child_ID);
        return 0;
    }

    new_child->child_ID = strdup(child_ID);
    new_child->child_line_number = child_line_number;
    new_child->next = NULL;

    // Add the new ChildrenNode to the list of children for the req_ID
    if (current_reqID->children == NULL) {
        current_reqID->children = new_child; // If children list is empty, set it to new_child
    } else {
        ChildrenNode *current_child = current_reqID->children;
        while (current_child->next != NULL) {
            current_child = current_child->next; // Traverse to the end of the children list
        }
        current_child->next = new_child; // Add new_child at the end of the list
    }
    return 1;

}

// Free the map dependency
void free_map_dependency(MapDependency *map) {
    if (!map) return;
    FileNode *file = map->head;
    while (file) {
        FileNode *next_file = file->next;
        free(file->req_ID);
        ParentNode *parent = file->parents;
        while (parent) {
            ParentNode *next_parent = parent->next;
            free(parent->parent_ID);
            free(parent);
            parent = next_parent;
        }
        ChildrenNode *child = file->children;
        while (child) {
            ChildrenNode *next_child = child->next;
            free(child->child_ID);
            free(child);
            child = next_child;
        }
        free(file);
        file = next_file;
    }
    free(map);
}

// Print the contents of the map dependency for debugging purposes
void print_map_dependency(MapDependency *map) {
    
    printf("This is what is in the map\n");
    if (!map) {
        printf("Map is NULL\n");
        return;
    }
    FileNode *current = map->head;
    while (current) {
        printf("reqID: %s (line %d)\n", current->req_ID, current->reqID_line_number);

        // Print parents
        printf("  Parents: ");
        ParentNode *parent = current->parents;
        if (!parent) {
            printf("--");
        } else {
            while (parent) {
                printf("%s (line %d), ", parent->parent_ID, parent->parent_line_number);
                parent = parent->next;
            }
        }
        printf("\n");

        // Print children
        printf("  Children: ");
        ChildrenNode *child = current->children;
        if (!child) {
            printf("--");
        } else {
            while (child) {
                printf("%s (line %d), ", child->child_ID, child->child_line_number);
                child = child->next;
            }
        }
        printf("\n\n");

        current = current->next;
    }
}