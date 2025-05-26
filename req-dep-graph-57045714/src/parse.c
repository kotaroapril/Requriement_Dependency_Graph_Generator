#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/parse.h"
#include "../include/dependency_map.h"

// Helper: check if a substring matches the requirement tag pattern
int is_req_tag(const char *substring) {
    // Check prefix
    if (strncmp(substring, "REQ-", 4) != 0) return 0;
    // Check XX (2 uppercase letters)
    if (!isupper(substring[4]) || !isupper(substring[5]) || substring[6] != '-') return 0;
    // Check YYYY (4 uppercase letters)
    for (int i = 0; i < 4; i++) if (!isupper(substring[7 + i])) return 0;
    if (substring[11] != '-') return 0;
    // Check DDDD (4 digits)
    for (int i = 0; i < 4; i++) if (!isdigit(substring[12 + i])) return 0;
    // End of tag or followed by non-alnum
    if (isalnum(substring[16])) return 0;
    return 1;
}

// Print all requirement tags in the file with line numbers
void print_req_tags(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Could not open file: %s\n", filename);
        return;
    }
    char line[1024];
    int line_num = 0;
    while (fgets(line, sizeof(line), fp)) {
        line_num++;
        int len = strlen(line);
        for (int i = 0; i <= len - 17; i++) {
            if (is_req_tag(&line[i])) {
                printf("%04d: %.17s\n", line_num, &line[i]);
            }
        }
    }
    fclose(fp);
}

void parse_file(const char *filename, MapDependency *map, FILE *output) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Could not open file: %s\n", filename);
        return;
    }

    char line[1024];
    int in_yaml = 0;
    int line_num = 0;
    char parent_ID[128] = "";

    while (fgets(line, sizeof(line), fp)) {
        line_num++;
        // Detect start/end of YAML block
        if (strstr(line, "```yaml")) { in_yaml = 1; continue; }
        if (in_yaml && strstr(line, "```")) { in_yaml = 0; strcpy(parent_ID, ""); continue; }
        if (in_yaml) {
            // Check for ID (record)
            char *id_ptr = strstr(line, "ID:");
            if (id_ptr) {
                sscanf(id_ptr, "ID: %127s", parent_ID);
                if (is_req_tag(parent_ID)) {
                    fprintf(output, "%04d: %s --\n", line_num, parent_ID);
                }
            }

            // Check for Parents (parent relationship)
            char *parents_ptr = strstr(line, "Parents:");
            if (parents_ptr && is_req_tag(parent_ID)) {
                char *parents = strchr(parents_ptr, ':');
                if (parents) {
                    parents++;
                    char *token = strtok(parents, ",");
                    while (token) {
                        while (*token == ' ' || *token == '\t') token++;
                        char parent_tag[128];
                        sscanf(token, "%127s", parent_tag);
                        if (strlen(parent_tag) > 0 && strcmp(parent_tag, "--") != 0 && is_req_tag(parent_tag)) {
                            fprintf(output, "%04d: %s -> %s\n", line_num, parent_tag, parent_ID);
                            add_dependency(map, parent_tag, parent_ID);
                        }
                        token = strtok(NULL, ",");
                    }
                }
            }
            // Check for Children (child relationship)
            char *children_ptr = strstr(line, "Children:");
            if (children_ptr && is_req_tag(parent_ID)) {
                char *children = strchr(children_ptr, ':');
                if (children) {
                    children++;
                    char *token = strtok(children, ",");
                    while (token) {
                        while (*token == ' ' || *token == '\t') token++;
                        char child_tag[128];
                        sscanf(token, "%127s", child_tag);
                        if (strlen(child_tag) > 0 && strcmp(child_tag, "--") != 0 && is_req_tag(child_tag)) {
                            fprintf(output, "%04d: %s -> %s\n", line_num, parent_ID, child_tag);
                            add_dependency(map, parent_ID, child_tag);
                        }
                        token = strtok(NULL, ",");
                    }
                }
            }
        }
    }
    fclose(fp);
}
