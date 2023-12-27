#ifndef HASH_SET_H
#define HASH_SET_H

#include <stdlib.h>
#include <stdint.h>
#include "LinkedList.h"

typedef struct HashSet {
    size_t size;
    size_t capacity; 
    LinkedList* array;
    LinkedList keys;
} HashSet;

void initHashSet(HashSet* set, size_t initialCapacity);
void insertHashSet(HashSet* set, size_t key);
int containsHashSet(HashSet* set, size_t key);
void removeElementHashSet(HashSet* set, size_t key);
void destroyHashSet(HashSet* set);

void copyHashSet(HashSet* srcSet, HashSet* dstSet);

void getSetFromList(LinkedList* list, HashSet* set);

#endif