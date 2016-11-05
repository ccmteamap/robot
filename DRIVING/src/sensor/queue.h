#ifndef QUEUE_H
#define QUEUE_H

typedef float QueueType;

typedef struct QueueNode{
  QueueType value;
  QueueNode* next;
};

typedef struct Queue{
  int size;
  int MAXSIZE;
  QueueNode* head;
  QueueNode* tail;
};

QueueType dequeue(Queue*);
void enqueue(Queue*, QueueType);
Queue newQueue();
void freeQueue(Queue*);

#endif
