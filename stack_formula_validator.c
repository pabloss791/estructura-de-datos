#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Error, el Stack esta lleno");
        return;
    }
    s->top++;
    *(s->items + s->top) = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("El stack ya esta vacio");
        return '\0';
    }
    char value = *(s->items + s->top);
    s->top--;
    return value;
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        printf("El stack esta vacio");
        return '\0';
    }
    return *(s->items + s->top);
}

void isvalidformula(char *f) {
    char *original = f;
    Stack s;
    init(&s);
    int valid = 1;

    while (*f != '\0') {
        if (*f == '(') {
            push(&s, *f);
        } else if (*f == ')') {
            if (isEmpty(&s)) {
                valid = 0;
                break;
            } else {
                pop(&s);
            }
        }
        f++;
    }
    
    if (!isEmpty(&s)) {
        valid = 0;
    }
    
    if (valid) {
        printf("La formula %s es valida\n", original);
    } else {
        printf("La formula %s NO es valida\n", original);
    }
}

int main() {
    char formula1[30] = "aa()bb((c))(ddd((rr((a)a)))";
    char formula2[30] = "((a+b)-(z*d))";

    isvalidformula(formula1);
    isvalidformula(formula2);
    return 0;
}