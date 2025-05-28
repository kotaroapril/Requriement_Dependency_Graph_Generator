#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include "dependency_map.h"

void parse_file(const char *filename, MapDependency *map);

#endif