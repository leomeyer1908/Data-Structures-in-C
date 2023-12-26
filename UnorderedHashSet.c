#include "UnorderedHashSet.h"

static size_t hashFunc(size_t key, size_t capacity) {
    return key % capacity;
}

void initUnorderedHashSet(UnorderedHashSet* set, size_t initialCapacity) {
    set->size = 0;
    set->capacity = initialCapacity;
    set->array = (LinkedList*) malloc(initialCapacity*sizeof(LinkedList));
    for (size_t i = 0; i < initialCapacity; i++) {
        initList(&(set->array[i]));
    }
}

void insertUnorderedHashSet(UnorderedHashSet* set, size_t key) {
    if (containsHashSet(set, key)) {
        return;
    }
    double load_factor = (double) set->size/set->capacity;
    if (load_factor > 0.7) {
        size_t newCapacity = set->capacity*2;
        LinkedList* newArray = (LinkedList*) malloc(newCapacity*sizeof(LinkedList));
        for (size_t i = 0; i < newCapacity; i++) {
            initList(&newArray[i]);
        }
        for (size_t i = 0; i < set->capacity; i++) {
            for (DoublyNode* currentNode = set->array[i].head; currentNode != NULL; currentNode = currentNode->next) {
                size_t index = hashFunc((size_t) (uintptr_t) currentNode->value, newCapacity);
                pushBackList(&newArray[index], currentNode->value);
            }
            destroyList(&set->array[i]);
        }
        free(set->array);
        set->array = newArray;

        set->capacity = newCapacity;
    }
    size_t index = hashFunc(key, set->capacity);
    pushBackList(&(set->array[index]), (void*) (uintptr_t) key);
    set->size++;
}

int containsUnorderedHashSet(UnorderedHashSet* set, size_t key) {
    size_t index = hashFunc(key, set->capacity);
    for (DoublyNode* currentNode = set->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if ((size_t) (uintptr_t) currentNode->value == key) {
            return 1;
        }
    }
    return 0;
}

void removeElementUnorderedHashSet(UnorderedHashSet* set, size_t key) {
    if (!containsHashSet(set, key)) {
        return;
    }
    size_t index = hashFunc(key, set->capacity);
    removeElementList(&set->array[index], (void*) (uintptr_t) key);
}

void destroyUnorderedHashSet(UnorderedHashSet* set) {
    for (size_t i = 0; i < set->capacity; i++) {
        destroyList(&set->array[i]);
    }
    free(set->array);
}


