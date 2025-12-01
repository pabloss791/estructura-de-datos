#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA_Hashtable.h"

typedef struct HashNode {
    char* key;
    int value;
    struct HashNode* next;
} HashNode;

struct HashTable {
    HashNode** buckets;
    int size;
    int capacity;
};

// FUNCIÓN HASH
unsigned int hashFunction(const char* key, int capacity) {  
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key;
        key++;
    }
    return hash % capacity;
}

// CREAR NODO
HashNode* createHashNode(const char* key, int value) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// LIBERAR NODO
void freeHashNode(HashNode* node) {
    free(node->key);
    free(node);
}


HashTable* createHashTable(int capacity) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->capacity = capacity;
    ht->size = 0;
    
    ht->buckets = (HashNode**)calloc(capacity, sizeof(HashNode*));
    return ht;
}


void destroyHashTable(HashTable* ht) {
    if (ht == NULL) return;

    for (int i = 0; i < ht->capacity; i++) {
        HashNode* current = ht->buckets[i];
        while (current != NULL) {
            HashNode* next = current->next;
            freeHashNode(current);
            current = next;
        }
    }
    free(ht->buckets);
    free(ht);
}


void put(HashTable* ht, const char* key, int value) {
    if (ht == NULL || key == NULL) {
        return;
    }

    unsigned int index = hashFunction(key, ht->capacity);

    HashNode* current = ht->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    HashNode* newNode = createHashNode(key, value);
    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;
    ht->size++;
}


int get(HashTable* ht, const char* key) {
    if (ht == NULL || key == NULL) {
        return -1;
    }

    unsigned int index = hashFunction(key, ht->capacity);
    HashNode* current = ht->buckets[index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;  
    }
    return -1;
}


void removeKey(HashTable* ht, const char* key) {
    if (ht == NULL || key == NULL) return;
    
    unsigned int index = hashFunction(key, ht->capacity);
    
    HashNode* current = ht->buckets[index];
    HashNode* prev = NULL;
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                ht->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            
            freeHashNode(current);
            ht->size--;
            return;
        }
        
        prev = current;
        current = current->next;
    }
}


int containsKey(HashTable* ht, const char* key) {
    if (ht == NULL || key == NULL) {
        return 0;  
    
    unsigned int index = hashFunction(key, ht->capacity);
    HashNode* current = ht->buckets[index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return 1;  
        }
        current = current->next;
    }
    
    return 0;  
}


int getSize(HashTable* ht) {
    if (ht == NULL) return 0;
    return ht->size;
}


int getCapacity(HashTable* ht) {
    if (ht == NULL) return 0;
    return ht->capacity;
}

// PRINT HASHTABLE
void printHashTable(HashTable* ht) {
    if (ht == NULL) {
        return;
    }

    printf("Hash Table (Size: %d, Capacity: %d)\n", ht->size, ht->capacity);
    printf("===================================\n");
    
    for (int i = 0; i < ht->capacity; i++) {
        printf("Bucket[%d]: ", i);
        HashNode* current = ht->buckets[i];
        
        if (current == NULL) {
            printf("(vacío)\n");  
        } else {
            while (current != NULL) {
                printf("[\"%s\":%d]", current->key, current->value);  
                if (current->next != NULL) {
                    printf(" -> ");
                }
                current = current->next;
            }
            printf("\n");
        }
    }
    printf("===================================\n");
}