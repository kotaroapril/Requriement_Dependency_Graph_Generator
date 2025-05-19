#ifndef SEEN_SET_H
#define SEEN_SET_H

typedef struct SeenSetNode {
    char *req_ID;
    struct SeenSetNode *next;
} SeenSetNode;

typedef struct SeenSet {
    SeenSetNode *head;
} SeenSet;

SeenSet* create_seen_set();
int is_seen_set_empty(SeenSet *seen_set);
int add_to_seen_set(SeenSet *seen_set, const char *req_ID);
int is_in_seen_set(SeenSet *seen_set, const char *req_ID);
void free_seen_set(SeenSet *seen_set);

#endif