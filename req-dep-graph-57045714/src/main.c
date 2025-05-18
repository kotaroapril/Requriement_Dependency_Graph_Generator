#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/parse.h"
#include "../include/draw_diagram.h"
#include "../include/sort_dependency.h"

int main() {

    char filename[256];

    /*  Ask the user for a file name
        Remove the newline character from the input
        Check if the file exists or empty
        If it does not exist or is empty, print an error message
            then loop back to ask for a file name
        If it exists, call the parse_file function
    */ 

    // Parse the file to extract dependencies
    parse_file(filename);

    // Sort the dependencies
    sort_dependencies();

    // Draw the dependency tree diagram
    draw_diagram();

    return EXIT_SUCCESS;
}