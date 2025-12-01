#ifndef TDA_HASHTABLE_H
#define TDA_HASHTABLE_H

typedef struct HashTable HashTable;


HashTable* createHashTable(int capacity);
void destroyHashTable(HashTable* ht);


void put(HashTable* ht, const char* key, int value);
int get(HashTable* ht, const char* key);
void removeKey(HashTable* ht, const char* key);
int containsKey(HashTable* ht, const char* key);


int getSize(HashTable* ht);
int getCapacity(HashTable* ht);
void printHashTable(HashTable* ht);

#endif