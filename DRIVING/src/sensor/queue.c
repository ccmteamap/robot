#include<stdlib.h>
#include"queue.h"

struct Queue_s {
  int size;
  int MAXSIZE;
  int head;
  int tail;
  QueueType* elements;
};

int Next(Queue q, int current){
  return (current + 1) % q->MAXSIZE;
}

//1: niet gelukt, 0:gelukt.
int dequeue(Queue q, QueueType *returnValue){
  if(q->size == 0 || !q){
    return 1;
  }

  *returnValue = peekQ(q);
  if(q->size != 1){
    q->head = Next(q, q->head);
  }
  q->size--;
  
  return 0;
}

//1: niet gelukt, 0: gelukt.
int enqueue(Queue q, QueueType value){
  if(q->size >= q->MAXSIZE){
    return 1;
  }

  if(q->size == 0){
    q->elements[q->tail] = value;
  }
  else{
    q->tail = Next(q, q->tail);
    q->elements[q->tail] = value;
  }
  q->size++;
  
  return 0;
}

Queue newQ(int maxSize){
  Queue q = (Queue) malloc(sizeof(struct Queue_s));
  q->size = 0;
  q->MAXSIZE = maxSize;
  q->head = 0;
  q->head = 0;
  q->elements = (QueueType*) malloc(sizeof(QueueType) * maxSize);

  return q;
}

void freeQ(Queue q){
  free(q->elements);
  free(q);
  
  return;
}

QueueType peekQ(Queue q){
  return q->elements[q->head];
}

int sizeQ(Queue q){
  return q->size;
}

QueueType avrgQ(Queue q){
  
}
