#include "HashSet.h"




static size_t hashFunc(int key, size_t capacity) {
    return key % capacity;
}

void initHashSet(HashSet* set, size_t initialCapacity) {
    set->size = 0;
    set->capacity = initialCapacity;
    set->array = (LinkedList*) malloc(initialCapacity*sizeof(LinkedList));
    for (size_t i = 0; i < initialCapacity; i++) {
        initList(&(set->array[i]));
    }
}

void insertHashSet(HashSet* set, int key) {
    double load_factor = (double) set->size/set->capacity;
    if (load_factor > 0.7) {
        size_t newCapacity = set->capacity*2;
        LinkedList* newArray = (LinkedList*) malloc(newCapacity*sizeof(LinkedList));
        for (int i = 0; i < newCapacity; i++) {
            initList(&newArray[i]);
        }
        for (int i = 0; i < set->capacity; i++) {
            for (Node* currentNode = set->array[i].head; currentNode != NULL; currentNode = currentNode->next) {
                size_t index = hashFunc(*((int*) currentNode->value), newCapacity);
                pushBackList(&set->array[index], currentNode->value);
            }
            destroyList(&set->array[i]);
        }
        free(set->array);
        set->array = newArray;

        set->capacity = newCapacity;
    }
    size_t index = hashFunc(key, set->capacity);
    int* keyValue = (int*) malloc(sizeof(int)); 
    *keyValue = key;
    pushBackList(&(set->array[index]), (void*) keyValue);
    set->size++;
}

int containsHashSet(HashSet* set, int key) {
    size_t index = hashFunc(key, set->capacity);
    for (Node* currentNode = set->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if (*((int*)currentNode->value) == key) {
            return 1;
        }
    }
    return 0;
}

void destroyHashSet(HashSet* set) {
    for (int i = 0; i < set->capacity; i++) {
        if (set->array[i].head != NULL) {
            for (Node* currentNode = set->array[i].head; currentNode != NULL; currentNode = currentNode->next) {
                free((int*)currentNode->value);
            }
        }
        destroyList(&set->array[i]);
    }
    free(set->array);
}


