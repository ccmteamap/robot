#include<stdlib.h>
#include"queue.h"

QueueType dequeue(Queue* this){
  QueueNode* temp = this->head;
  QueueType headValue = temp->value;

  if(this && temp){
    this->head = temp->next;
  }
  else {
    return NULL;
  }

  free(temp);
  return headValue;
}

void enqueue(Queue* this, QueueType value){
  QueueNode* newTail = (QueueNode*) malloc(sizeof QueueNode);
  newTail->value = value;
  newTail->next = NULL;

  this->tail = newTail;

  if(!this->head){
    this->head = this->tail;
  }
  
  return;
}

Queue newQueue(){
  Queue queue = (Queue*) malloc(sizeof Queue);
  queue.dequeueptr = &dequeue;
  queue.enqueueptr = &enqueue;
  
  return queue;
}


