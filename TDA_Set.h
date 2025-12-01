#ifndef TDA_SET_H
#define TDA_SET_H

typedef struct Set Set;
Set* createSet(int capacity);
void destroySet(Set* set);
void add(Set* set, int value);
void removeElem(Set* set, int value);
int contains(Set* set, int value);
Set* unionSet(Set* setA, Set* setB);
Set* intersection(Set* setA, Set* setB);
Set* difference(Set* setA, Set* setB);
int isEmpty(Set* set);
int getSize(Set* set);
void printSet(Set* set);

#endif