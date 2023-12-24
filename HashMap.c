#include "HashMap.h"

static size_t hashFunc(size_t key, size_t capacity) {
    return key % capacity;
}

void initHashMap(HashMap* map, size_t initialCapacity) {
    map->size = 0;
    map->capacity = initialCapacity;
    map->array = (LinkedList*) malloc(initialCapacity*sizeof(LinkedList));
    for (size_t i = 0; i < initialCapacity; i++) {
        initList(&(map->array[i]));
    }
}

void insertHashMap(HashMap* map, size_t key, void* value) {
    double load_factor = (double) map->size/map->capacity;
    if (load_factor > 0.7) {
        size_t newCapacity = map->capacity*2;
        LinkedList* newArray = (LinkedList*) malloc(newCapacity*sizeof(LinkedList));
        for (size_t i = 0; i < newCapacity; i++) {
            initList(&newArray[i]);
        }
        for (size_t i = 0; i < map->capacity; i++) {
            for (Node* currentNode = map->array[i].head; currentNode != NULL; currentNode = currentNode->next) {
                size_t index = hashFunc(*((size_t*) currentNode->value), newCapacity);
                pushBackList(&newArray[index], currentNode->value);
            }
            destroyList(&map->array[i]);
        }
        free(map->array);
        map->array = newArray;

        map->capacity = newCapacity;
    }
    size_t index = hashFunc(key, map->capacity);
    KeyValuePair * keyValuePair = (KeyValuePair*) malloc(sizeof(KeyValuePair));
    keyValuePair->key = key;
    keyValuePair->value = value;
    pushBackList(&(map->array[index]), (void*) keyValuePair);
    map->size++;
}

int updateHashMap(HashMap* map, size_t key, void* value) {
    size_t index = hashFunc(key, map->capacity);
    for (Node* currentNode = map->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if (((KeyValuePair*)currentNode->value)->key == key) {
            ((KeyValuePair*) currentNode->value)->value = value;
            return 0;
        }
    }
    return -1;
}

int containsHashMap(HashMap* map, size_t key) {
    size_t index = hashFunc(key, map->capacity);
    for (Node* currentNode = map->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if (((KeyValuePair*)currentNode->value)->key == key) {
            return 1;
        }
    }
    return 0;
}

void* getHashMap(HashMap* map, size_t key) {
    size_t index = hashFunc(key, map->capacity);
    for (Node* currentNode = map->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if (((KeyValuePair*)currentNode->value)->key == key) {
            return ((KeyValuePair*)currentNode->value)->value; 
        }
    }
    return NULL;
}

void destroyHashMap(HashMap* map) {
    for (size_t i = 0; i < map->capacity; i++) {
        if (map->array[i].head != NULL) {
            for (Node* currentNode = map->array[i].head; currentNode != NULL; currentNode = currentNode->next) {
                free((KeyValuePair*)currentNode->value);
            }
        }
        destroyList(&map->array[i]);
    }
    free(map->array);
}


