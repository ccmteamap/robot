#ifndef QUEUE_H
#define QUEUE_H

typedef unsigned long QueueType;
typedef struct Queue_s *Queue;

int dequeue(Queue, QueueType*);
int enqueue(Queue, QueueType);
Queue newQ(int);
void freeQ(Queue);
int sizeQ(Queue);
QueueType peekQ(Queue); //returns head of queue without dequeue'ing
QueueType avrgQ(Queue); //returns average of values in queue

#endif
