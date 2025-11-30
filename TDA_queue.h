#ifndef TDA_QUEUE_H
#define TDA_QUEUE_H

typedef struct Queue Queue;

Queue*createQueue();

void destroyQueue(Queue*queue);

void enqueue(Queue*queue,double data);

double dequeue(Queue*queue);

double peek(Queue*queue);

void isEmpty(Queue*queue);

void clearQueue(Queue*queue);

void printQueue(Queue*queue);

void setFront( Queue*queue,double data);


double getFront(Queue*queue);


void setRear(Queue*queue,double data);


double getRear(Queue*queue);


int getSize(Queue*queue);

#endif