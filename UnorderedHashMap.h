#ifndef UNORDERED_HASH_MAP_H
#define UNORDERED_HASH_MAP_H

#include <stdlib.h>
#include "LinkedList.h"

#ifndef KEY_VALUE_PAIR
#define KEY_VALUE_PAIR
typedef struct KeyValuePair {
    size_t key;
    void* value;
} KeyValuePair;
#endif //KEY_VALUE_PAIR

typedef struct UnorderedHashMap {
    size_t size;
    size_t capacity; 
    LinkedList* array;
} UnorderedHashMap;

void initUnorderedHashMap(UnorderedHashMap* map, size_t initialCapacity);
void insertUnorderedHashMap(UnorderedHashMap* map, size_t key, void* value);

//returns 0 if key exists, but returns -1 if it does not.
int updateUnorderedHashMap(UnorderedHashMap* map, size_t key, void* value); 
int containsUnorderedHashMap(UnorderedHashMap* map, size_t key);

//returns NULL if key does not exist.
void* getUnorderedHashMap(UnorderedHashMap* map, size_t key); 

void destroyUnorderedHashMap(UnorderedHashMap* map);

#endif //UNORDERED_HASH_MAP_H