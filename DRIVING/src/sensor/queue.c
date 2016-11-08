#include<stdlib.h>
#include"queue.h"

typedef struct QueueNode_s {
  QueueType value;
  struct QueueNode_s* next;
} QueueNode;

struct Queue_s {
  int size;
  int MAXSIZE;
  QueueNode* head;
  QueueNode* tail;
};

QueueType dequeue(Queue this){
  QueueNode* tempNode = this->head;
  QueueType tempVal = tempNode->value;

  this->head = tempNode->next; 
  if(!tempNode->next){ //als er geen volgende element is dan is de queue leeg en moeten we de tail wegdoen.
    this->tail = NULL;
  }

  --(this->size);
  free(tempNode);
  return tempVal;
}

//1: niet gelukt, 0: gelukt.
int enqueue(Queue this, QueueType value){
  if(!this || this->size >= this->MAXSIZE){ 
    return 1;
  }

  QueueNode* new = (QueueNode*) malloc(sizeof(QueueNode));
  if(!new){
    return 1;
  }  
  new->value = value;
  new->next = NULL;

  if(this->tail){ //als er een tail is dan laten we deze wijzen naar de nieuwe tail
    this->tail->next = new;
  }
  else{
    this->head = new; //als er geen tail is dan is de queue leeg en maken we een head aan.
  }

  this->tail = new; 
  ++(this->size);  
  return 0;
}

Queue newQ(int maxSize){
  Queue q = (Queue)malloc(sizeof(struct Queue_s));
  q->size = 0;
  q->MAXSIZE = maxSize;
  q->head = NULL;
  q->tail = NULL;

  return q;
}

void freeQ(Queue q){
  while(q->head){
    QueueNode* temp = q->head;
    q->head = q->head->next;
    free(temp);
  }
  
  q->size = 0;
  return;
}

QueueType peekQ(Queue this){
  return this->head->value;
}

int sizeQ(Queue this){
  return this->size;
}

QueueType avrgQ(queue){
  
}
