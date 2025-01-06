#ifndef _QUEUE_
#define _QUEUE_

typedef struct Queue Queue;

struct Queue {
  int *values;
  int *first;
  int length;
};

Queue *createQueue();

int isEmptyQueue(Queue *queue);

int lengthQueue(Queue *queue);

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

void printQueue(Queue *queue);

void populateQueue(Queue *queue);

void clearQueue(Queue *queue);

#endif
