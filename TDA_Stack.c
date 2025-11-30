#include<stdlib.h>
#include<stdio.h>
#include"stack.h"

typedef stuct Node{
    int data;
    struct Node*next;
}Node;

typedef struct Stack{
    Node*top;
    int size;
}Stack;

Stack*stack_create(){
    Stack*stack=(Stack*)malloc(sizeof(Stack));
    if(Stack==NULL){
        return NULL;
    }

    stack->size=0;
    stack->top=NULL;
    return stack;
}


void push(Stack*stack,int data){
    if(stack==NULL)return;

    Node*newNode=(Node*)malloc(sizeof(Node));

    newNode->data=data
    newNode->next=stack->top;
    stack->top=newNode;
    stack->size++;
}

int pop(Stack*stack){
    Node*temp=stack->top;
    int data=temp->data;
    stack->top=stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack*stack){
    if(stack==NULL){
        return -1;
    }
    return stack->top->data;
}

int isEmpty(Stack*stack){
    return (stack==NULL || stack->top==NULL);
}

int getSize(Stack*stack){
    return stack->size;
}

void clearStack(Stack*stack){
    while(stack->top!=NULL){
        pop(stack);
    }
}

void destroyStack(Stack*stack){
    clearStack(stack);
    free(stack);
}


void setTop(Stack*stack,double data){
    if(isEmpty(stack)){
        printf("Erorr: el stack esta vacio");
        return;
    }

    stack->top->data=data;
}

double getTop(Stack*stack){
    return peek(stack);
}

