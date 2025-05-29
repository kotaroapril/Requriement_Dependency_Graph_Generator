#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/parse.h"
#include "../include/dependency_map.h"
#include "../include/io.h"
#include "../include/draw_diagram.h"

int main(void) {

    char filename[256];

    MapDependency *map = create_map_dependency();

    user_input(filename, sizeof(filename));    
    parse_file(filename, map);
    
    FILE *output_file = create_output_file("rdgg-report-57045714.md");

    draw_diagram(map, filename, output_file);
    print_map_dependency(map); //Double check the map contents

    free_map_dependency(map);
    fclose(output_file);
    
    printf("Report generated successfully. Press Enter to exit.\n");
    getchar(); // Wait for user input before exiting

    return 0;
}