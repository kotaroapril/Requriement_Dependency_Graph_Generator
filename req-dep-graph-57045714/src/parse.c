#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/parse.h"
#include "../include/queue.h"
#include "../include/seen_set.h"
#include "../include/map_dependency.h"

void parse_file (const char *filename) {
    // Create a queue to hold files to be processed
    Queue *queue = create_queue();

    // Create a seen set to keep track of processed files
    SeenSet *seen_set = create_seen_set();

    // Create a map to hold file dependencies   
    MapDependency *map = create_map_dependency();
    
    // Add the initial file to the queue and seen set
    enqueue(queue, filename);
    add_to_seen_set(seen_set, filename);

    /* While the queue is not empty:
        Dequeue a file from the queue
        Open the file and read its contents
        For each line in the file:
            If the line contains a #include directive:
                Extract the filename from the directive
                Add the dependency to the map
                If the dependency is not in the seen set:
                    Enqueue the dependency and add it to the seen set
    Clean up:
        Free the queue, seen set, and map    
    */

}
