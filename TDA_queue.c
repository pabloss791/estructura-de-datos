#include<stdio.h>
#include<stdlib.h>
#include"TDA_queue.h"

typedef struct Node{
    double data;
    struct Node*next;

}Node;

typedef struct Queue{
    Node*front;
    Node*rear;
    int size;
}Queue;

Queue*createQueue(){
    Queue*queue=(Queue*)malloc(sizeof(Queue));

    if(queue==NULL){
        printf("la queue no pudo ser creada");
        return NULL;
    }

    queue->front=NULL;
    queue->rear=NULL;
    queue->size=0;
    return queue;

}

void destroyQueue(Queue*queue){
    if(queue==NULL){
        return;
    }
    clearQueue(queue);
    free(queue);
}

void enqueue(Queue*queue,double data){
    if(queue==NULL){
        return;
    }

    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL,
    if(isEmpty(queue)){
       queue->front=newNode;
       queue->rear=newNode;
    }else{
        queue->rear->next=newNode;
        queue->rear=newNode;
    }

    queue->size++;

}

double dequeue(Queue*queue){
    if(isEmpty(queue)){
        printf("error la queue esta vacia");
        return 1;
    }
    Node*temp=queue->front;
    double data= temp->data;

    queue->front=queue->front->next;
    free(temp);
    queue->size--;
    return data;
}

double peek(Queue*queue){
    if(isEmpty(queue)){
        printf("La queue esta vacia");
        return -1;
    }

    return queue->front->data;
}

void isEmpty(Queue*queue){
    return(queue==NULL|| queue->front==NULL   );
}

void clearQueue(Queue*queue){
    if(queue==NULL)return;

    while(!isEmpty(queue)){
        dequeue(queue);
    }
}

void printQueue(Queue*queue){
    if(isEmpty(queue)){
        printf("Error la queue esta vacia");
        return -1;
    }

    Node*current=queue->front;
    while(current!=NULL){
        print(".2%f",current->data);
        current=current->next;
    }
    printf("\n");
}

void setFront( Queue*queue,double data){
    queue->front->data=data;
}

double getFront(Queue*queue){
    return queue->front->data;
}

void setRear(Queue*queue,double data){
    queue->rear->data=data;
}

double getRear(Queue*queue){
    return queue->rear->data
}

int getSize(Queue*queue){
    return queue->size;
}

