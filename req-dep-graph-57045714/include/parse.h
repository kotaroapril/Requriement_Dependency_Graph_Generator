#ifndef PARSE_H
#define PARSE_H

#include "../include/dependency_map.h"

int is_req_tag(const char *substring);
void print_req_tags(const char *filename);
void parse_file (const char *filename, MapDependency *map, FILE *output);

#endif