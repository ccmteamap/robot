#include<stdlib.h>
#include"queue.h"

QueueType dequeue(Queue* this){
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
int enqueue(Queue* this, QueueType value){
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
