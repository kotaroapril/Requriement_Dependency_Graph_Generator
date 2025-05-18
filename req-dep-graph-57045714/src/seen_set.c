#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/seen_set.h"

// Create a new seen set
SeenSet* create_seen_set() {
    /*
        Allocate memory for the seen set
        Set head to NULL
        Return the seen set
    */
}

// Check if the seen set is empty
int is_seen_set_empty(SeenSet *seen_set) {
   // Return 1 if empty, 0 otherwise
   return 0;
    
}
// Add a file to the seen set
int add_to_seen_set(SeenSet *seen_set, const char *filename) {
    /*
        If the seen set is empty, create a new node and set it as the head
        Call is_in_seen_set to check if the file is already in the seen set
        If it is, return 0
        If it is not, create a new node and add it to the end of the list
        Return 1 if the file was added successfully, 0 otherwise
    */
    return 0;
}

// Check if a file is in the seen set
int is_in_seen_set(SeenSet *seen_set, const char *filename) {
    /*
        Call is_seen_set_empty, if returns 1, return 0
        
        Traverse the seen set to check if the file is already in the seen set
        Return 1 if it is, 0 otherwise
    */
    return 0;
}

// Free the seen set
void free_seen_set(SeenSet *seen_set) {
    /*
        Free all nodes in the seen set
        Free the seen set itself
    */
}
