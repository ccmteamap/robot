#include<stdlib.h>
#include"queue.h"

QueueType dequeue(Queue* this){
  if(!this || !this->head){
    return NULL;
  }

  QueueNode* tempNode = this->head;
  QueueType tempVal = tempNode->value;

  this->head = tempNode->next ? tempNode->next : NULL;
  --(this->size);
  
  return tempVal;
}

//returns 0 if succesful, 1 if not
int enqueue(Queue* this, QueueType value){
  if(!this || size >= this->MAXSIZE){
    return 1;
  }
      
  QueueNode* new = (QueueNode*) malloc(sizeof QueueNode);
  if(!new){
    return 1;
  }  
  new->value = value;
  new->next = NULL;

  if(this->tail){
    this->tail->next = new;
  }
  else{
    this->head = new;
  }

  this->tail = new;

  ++(this->size);
  
  return 0;
}

Queue newQueue(int maxSize){
  Queue e = { 0, maxSize, NULL, NULL };

  return e;
}

void freeQueue(Queue* q){
  while(q->head){
    QueueNode* temp = q->head;
    q->head = q->head->next;
    free(temp);
  }

  q->size = 0;

  return;
}
