#ifndef HASH_SET_H
#define HASH_SET_H

#include <stdlib.h>
#include "LinkedList.h"

typedef struct HashSet {
    size_t size;
    size_t capacity; 
    LinkedList* array;
} HashSet;

void initHashSet(HashSet* set, size_t initialCapacity);
void insertHashSet(HashSet* set, int key);
int containsHashSet(HashSet* set, int key);
void destroyHashSet(HashSet* set);

#endif