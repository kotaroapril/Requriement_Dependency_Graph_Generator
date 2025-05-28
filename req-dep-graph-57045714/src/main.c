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
    
    FILE *report = create_report_file("rdgg-report-57045714.md");

    draw_diagram(map, filename, report);
    print_map_dependency(map); //For debugging purposes
    free_map_dependency(map);
    fclose(report);

    return 0;
}