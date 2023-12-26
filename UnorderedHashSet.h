#ifndef UNORDERED_HASH_SET_H
#define UNORDERED_HASH_SET_H

#include <stdlib.h>
#include <stdint.h>
#include "LinkedList.h"

typedef struct UnorderedHashSet {
    size_t size;
    size_t capacity; 
    LinkedList* array;
} UnorderedHashSet;

void initUnorderedHashSet(UnorderedHashSet* set, size_t initialCapacity);
void insertUnorderedHashSet(UnorderedHashSet* set, size_t key);
int containsUnorderedHashSet(UnorderedHashSet* set, size_t key);
void removeElementUnorderedHashSet(UnorderedHashSet* set, size_t key);
void destroyUnorderedHashSet(UnorderedHashSet* set);

#endif