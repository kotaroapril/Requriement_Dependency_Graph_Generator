#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    char *filename;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *head;
    QueueNode *tail;
} Queue;

Queue* create_queue();
int is_queue_empty(Queue *queue);
void enqueue(Queue *queue, const char *filename);
char* dequeue(Queue *queue);
void free_queue(Queue *queue);

#endif