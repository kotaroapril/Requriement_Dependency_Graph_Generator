#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/draw_diagram.h"
#include "../include/dependency_map.h"

// Draw a diagram of the dependencies in the map
void draw_diagram(MapDependency *map, const char *filename,  FILE *output_file) {
    
    if (!map || !output_file) {
        fprintf(stderr, "Invalid map or output file.\n");
        return;
    }

    // Open input file and print the first 3 lines of the input file to the output file
    FILE *input_file = fopen(filename, "r");

    char line[1024];
    int line_num = 0;

   while (line_num < 3 && fgets(line, sizeof(line), input_file)) {
        line_num++;
        fprintf(output_file, line);
    }

    fprintf(output_file, "\n");


    FileNode *current = map->head;
    while (current) {
        int has_parents = (current->parents != NULL);
        int has_children = (current->children != NULL);

        // Print the req_ID and its line number
        fprintf(output_file, "Line %d: %s --\n", current->reqID_line_number, current->req_ID);

        // Print parent relationships
        ParentNode *parent = current->parents;
        if (has_parents) {
            while (parent) {
                fprintf(output_file, "Line %d: %s -> %s\n", parent->parent_line_number, parent->parent_ID, current->req_ID);
                parent = parent->next;
            }
        }

        // Print child relationships
        ChildrenNode *child = current->children;
        if (has_children) {
            while (child) {
                fprintf(output_file, "Line %d: %s -> %s\n", child->child_line_number, current->req_ID, child->child_ID);
                child = child->next;
            }
        }

        current = current->next;
    }
}