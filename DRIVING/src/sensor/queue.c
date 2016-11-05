#include<stdlib.h>
#include"queue.h"

QueueType dequeue(Queue* this){
  if(!this || !this->head){ //checken of zowel de pointer naar de queue en de pointer naar het eerste element valide zijn.
    return NULL;
  }

  QueueNode* tempNode = this->head;
  QueueType tempVal = tempNode->value;

  this->head = tempNode->next; //head van queue verplaatsten naar volgende element.
  if(!tempNode->next){ //als er geen volgende element is dan is de queue leeg en moeten we de tail wegdoen.
    this->tail = NULL;
  }

  --(this->size);
  free(tempNode); //verwijderen van voormalige head.
  return tempVal;
}

//1: niet gelukt, 0: gelukt.
int enqueue(Queue* this, QueueType value){
  if(!this || size >= this->MAXSIZE){ //checken of pointer naar queue valide is en of de queue al niet vol is.
    return 1;
  }

  QueueNode* new = (QueueNode*) malloc(sizeof QueueNode);
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
