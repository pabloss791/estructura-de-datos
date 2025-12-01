#include <stdio.h>
#include <stdlib.h>
#include "TDA_Set.h"

struct Set {
    int* elements;
    int size;
    int capacity;  
};

Set* createSet(int capacity) {
    Set* set = (Set*)malloc(sizeof(Set));
    set->elements = (int*)malloc(sizeof(int) * capacity);
    set->size = 0;
    set->capacity = capacity;
    return set;
}

void destroySet(Set* set) {
    if (set == NULL) {
        return;
    }
    free(set->elements);
    free(set);
}

int contains(Set* set, int value) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == value) {
            return 1;
        }
    }
    return 0;
}

void add(Set* set, int value) {
    if (contains(set, value)) {  
        return;
    }

    if (set->size >= set->capacity) {  
        printf("Error: Set lleno\n");
        return;
    }

    set->elements[set->size] = value;
    set->size++;
}

void removeElem(Set* set, int value) {
    int found_index = -1;
    
    
    for (int i = 0; i < set->size; i++) {  
        if (set->elements[i] == value) {
            found_index = i;  
            break;
        }
    }

    if (found_index == -1) {
        return;
    }

    
    for (int i = found_index; i < set->size - 1; i++) {  
        set->elements[i] = set->elements[i + 1];
    }
    set->size--;
}

Set* unionSet(Set* setA, Set* setB) {
    int new_capacity = setA->size + setB->size;
    Set* result = createSet(new_capacity);
    
    for (int i = 0; i < setA->size; i++) {
        add(result, setA->elements[i]);
    }

    for (int i = 0; i < setB->size; i++) {
        add(result, setB->elements[i]);
    }
    return result;
}

Set* intersection(Set* setA, Set* setB) {
    int new_capacity = (setA->size < setB->size) ? setA->size : setB->size; 
    Set* result = createSet(new_capacity);
    
    for (int i = 0; i < setA->size; i++) {
        if (contains(setB, setA->elements[i])) {
            add(result, setA->elements[i]);
        }
    }
    return result;
}

Set* difference(Set* setA, Set* setB) {
    Set* result = createSet(setA->capacity);

    for (int i = 0; i < setA->size; i++) {
        if (!contains(setB, setA->elements[i])) {
            add(result, setA->elements[i]);
        }
    }
    return result;
}

int isEmpty(Set* set) {
    return set->size == 0;
}

int getSize(Set* set) {
    return set->size;
}

void printSet(Set* set) {
    printf("{ ");  
    for (int i = 0; i < set->size; i++) {
        printf("%d", set->elements[i]);
        if (i < set->size - 1) {
            printf(", ");
        }
    }
    printf(" }\n");  
}
