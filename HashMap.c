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
    initList(&map->keyValuePairs);
}

void insertHashMap(HashMap* map, size_t key, void* value) {
    if (containsHashMap(map, key)) {
        updateHashMap(map, key, value);
        return;
    }
    double load_factor = (double) map->size/map->capacity;
    if (load_factor > 0.7) {
        size_t newCapacity = map->capacity*2;
        LinkedList* newArray = (LinkedList*) malloc(newCapacity*sizeof(LinkedList));
        for (size_t i = 0; i < newCapacity; i++) {
            initList(&newArray[i]);
        }

        for (DoublyNode* currentNode = map->keyValuePairs.head; currentNode != NULL; currentNode = currentNode->next) {
            KeyValuePair* currentKeyValuePair = (KeyValuePair*) currentNode->value;
            size_t index = hashFunc(currentKeyValuePair->key, newCapacity);
            pushBackList(&newArray[index], (void*) currentNode);
        }

        for (size_t i = 0; i < map->capacity; i++) {
            destroyList(&map->array[i]);
        }
        free(map->array);

        map->array = newArray;
        map->capacity = newCapacity;
    }

    KeyValuePair * keyValuePair = (KeyValuePair*) malloc(sizeof(KeyValuePair));
    keyValuePair->key = key;
    keyValuePair->value = value;
    pushBackList(&map->keyValuePairs, (void*) keyValuePair);
    DoublyNode* keyNode = map->keyValuePairs.tail;

    size_t index = hashFunc(key, map->capacity);
    pushBackList(&(map->array[index]), (void*) keyNode);

    map->size++;
}

int updateHashMap(HashMap* map, size_t key, void* value) {
    size_t index = hashFunc(key, map->capacity);
    for (DoublyNode* currentNode = map->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if (((KeyValuePair*) ((DoublyNode*) currentNode->value)->value)->key == key) {
            ((KeyValuePair*) ((DoublyNode*) currentNode->value)->value)->value = value;
            return 0;
        }
    }
    return -1;
}

int containsHashMap(HashMap* map, size_t key) {
    size_t index = hashFunc(key, map->capacity);
    for (DoublyNode* currentNode = map->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if (((KeyValuePair*) ((DoublyNode*) currentNode->value)->value)->key == key) {
            return 1;
        }
    }
    return 0;
}

void* getHashMap(HashMap* map, size_t key) {
    size_t index = hashFunc(key, map->capacity);
    for (DoublyNode* currentNode = map->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if (((KeyValuePair*) ((DoublyNode*) currentNode->value)->value)->key == key) {
            return ((KeyValuePair*) ((DoublyNode*) currentNode->value)->value)->value; 
        }
    }
    return NULL;
}

void removeElementHashMap(HashMap* map, size_t key) {
    if (!containsHashMap(map, key)) {
        return;
    }
    size_t index = hashFunc(key, map->capacity);
    for (DoublyNode* currentNode = map->array[index].head; currentNode != NULL; currentNode = currentNode->next) {
        if (((KeyValuePair*) ((DoublyNode*) currentNode->value)->value)->key == key) {
            free((KeyValuePair*) ((DoublyNode*) currentNode->value)->value);
            removeNodeFromList(&map->keyValuePairs, (DoublyNode*) currentNode->value);
            removeNodeFromList(&map->array[index], currentNode);
            map->size--;
            break;
        }
    }
}

void destroyHashMap(HashMap* map) {
    for (size_t i = 0; i < map->capacity; i++) {
        destroyList(&map->array[i]);
    }
    free(map->array);
    for (DoublyNode* currentNode = map->keyValuePairs.head; currentNode != NULL; currentNode = currentNode->next) {
        free((KeyValuePair*) currentNode->value);
    }
    destroyList(&map->keyValuePairs);
    map->capacity = 0;
    map->size = 0;
}


