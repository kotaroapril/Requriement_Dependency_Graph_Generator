#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/parse.h"
#include "../include/dependency_map.h"

// Helper: check if a substring matches the requirement tag format: REQ-XX-YYYY-DDDD
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


void parse_file(const char *filename, MapDependency *map) {
    FILE *input_file = fopen(filename, "r");
    if (!input_file) {
        printf("Could not open file: %s\n", filename);
        return;
    }

    char line[1024];
    int in_yaml = 0;
    int line_num = 0;
    char req_ID[128] = "";

    while (fgets(line, sizeof(line), input_file)) {
        line_num++;
        // Detect start/end of YAML block
        if (strstr(line, "```yaml")) { 
            in_yaml = 1;
            continue; 
        }
        if (in_yaml && strstr(line, "```")) { 
            in_yaml = 0;
            strcpy(req_ID, "");
            continue; 
        }
        if (in_yaml) {
            // Check for ID
            char *reqID_ptr = strstr(line, "ID:");
            if (reqID_ptr) {
                sscanf(reqID_ptr, "ID: %127s", req_ID);
                if (is_req_tag(req_ID)) {
                    add_reqID(map, req_ID, line_num);
                    printf(" %04d: %s\n", line_num, req_ID);
                }
            }

            // Check for Parents (parent relationship)
            char *parents_ptr = strstr(line, "Parents:");
            if (parents_ptr && is_req_tag(req_ID)) {
                char *parents = strchr(parents_ptr, ':');
                if (parents) {
                    parents++;
                    char *token = strtok(parents, ",");
                    while (token) {
                        while (*token == ' ' || *token == '\t') token++;
                        char parent_ID[128];
                        sscanf(token, "%127s", parent_ID);
                        if (strlen(parent_ID) > 0 && strcmp(parent_ID, "--") != 0 && is_req_tag(parent_ID)) {
                            add_parent(map, req_ID, parent_ID, line_num);
                            printf(" %04d: %s -> %s\n", line_num, parent_ID, req_ID);
                        }
                        token = strtok(NULL, ",");
                    }
                }
            }

            // Check for Children (child relationship)
            char *children_ptr = strstr(line, "Children:");
            if (children_ptr && is_req_tag(req_ID)) {
                char *children = strchr(children_ptr, ':');
                if (children) {
                    children++;
                    char *token = strtok(children, ",");
                    while (token) {
                        while (*token == ' ' || *token == '\t') token++;
                        char child_ID[128];
                        sscanf(token, "%127s", child_ID);
                        if (strlen(child_ID) > 0 && strcmp(child_ID, "--") != 0 && is_req_tag(child_ID)) {
                            add_child(map, req_ID, child_ID, line_num);
                            printf(" %04d: %s -> %s\n", line_num, req_ID, child_ID);
                        }
                        token = strtok(NULL, ",");
                    }
                }
            }
        }
    }
    printf("\n");
    fclose(input_file);
}
