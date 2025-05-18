#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/seen_set.h"


// Create a new seen set
SeenSet* create_seen_set() {

}

// Check if the seen set is empty
int is_seen_set_empty(SeenSet *seen_set) {
   // Check if the seen set is empty
    return seen_set->head == NULL;
}
// Add a file to the seen set
int add_to_seen_set(SeenSet *seen_set, const char *filename) {
    
}

// Check if a file is in the seen set
int is_in_seen_set(SeenSet *seen_set, const char *filename) {

}

// Free the seen set
void free_seen_set(SeenSet *seen_set) {

}
