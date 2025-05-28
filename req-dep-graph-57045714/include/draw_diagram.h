#ifndef DRAW_DIAGRAM_H
#define DRAW_DIAGRAM_H

#include "dependency_map.h"

void draw_diagram(MapDependency *map, const char *filename, FILE *output_file);

#endif // DRAW_DIAGRAM_H