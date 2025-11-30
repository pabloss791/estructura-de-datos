#ifndef TDA_STACK.H
#define TDA_STACK.H


typedef struct Stack Stack;

Stack* createStack();
void destroyStack(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(Stack* stack);
int isEmpty(Stack* stack);
int getSize(Stack* stack);
void clearStack(Stack* stack);
void setTop(Stack* stack, double data);  
double getTop(Stack* stack); 
#endif

