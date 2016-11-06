#ifndef QUEUE_H
#define QUEUE_H

typedef unsigned long QueueType;

typedef struct _QueueNode {
  QueueType value;
  struct _QueueNode* next;
} QueueNode;

typedef struct _Queue {
  int size;
  int MAXSIZE;
  QueueNode* head;
  QueueNode* tail;
} Queue;

QueueType dequeue(Queue*);
int enqueue(Queue*, QueueType);
Queue newQueue(int);
void freeQueue(Queue*);

#endif
