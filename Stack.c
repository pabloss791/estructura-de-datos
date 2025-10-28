#include <stdio.h>
#include<stdlib.h>

typedef struct stack_node
{
    int info;
    struct stack_node*prev;
}stack_node;


/*STACK GLOBAL*/
stack_node*stack_top=NULL;
int count=0;

void push(int data){
   stack_node*nuevo= malloc(sizeof(stack_node));
   nuevo->info=data;
   nuevo->prev=NULL;
   if (count==0){stack_top=nuevo;}
    else{
        nuevo->prev=stack_top;
        stack_top=nuevo;
    }
    count++;
}

int pop(){
    if(stack_top==NULL){
        return -1;
    }
   stack_node*tmp= stack_top;
    int dato=tmp->info;
    stack_top=stack_top->prev;
    free(tmp);
    count--;
    return dato;
    
}