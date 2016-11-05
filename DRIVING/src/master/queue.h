#ifndef QUEUE_H
#define QUEUE_H

typedef float QueueType;

typedef struct QueueNode{
  QueueType value;
  QueueNode* next;
};

typedef struct Queue{
  QueueNode* head;
  QueueNode* tail;
  QueueType (*dequeueptr)(Queue*);
  void (*enqueueptr)(Queue*, QueueType);
};

QueueType dequeue(Queue*);
void enqueue(Queue*, QueueType);
Queue initQueue();

#endif
