#ifndef PARSE_H
#define PARSE_H

#include "../include/map_dependency.h"
#include "../include/seen_set.h"

void parse_file (const char *filename, MapDependency *map, SeenSet *seen_set);

#endif