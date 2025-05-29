#ifndef IO_H
#define IO_H

#include <stdio.h>

void user_input(char *filename, size_t size);
FILE* create_output_file(const char *report_filename);

#endif // IO_H