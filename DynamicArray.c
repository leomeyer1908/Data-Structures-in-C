#include "DynamicArray.h"

void initDynamicArray(DynamicArray* dynamicArray, size_t elementSize, size_t initialCapacity) {
    dynamicArray->array = malloc(initialCapacity * elementSize);
    dynamicArray->size = 0;
    dynamicArray->capacity = initialCapacity;
    dynamicArray->elementSize = elementSize;
}

void pushBackDynamicArray(DynamicArray* dynamicArray, const void* element) {
    if (dynamicArray->size == dynamicArray->capacity) {
        dynamicArray->capacity *= 2;
        dynamicArray->array = realloc(dynamicArray->array, dynamicArray->capacity * dynamicArray->elementSize);
    }

    char* lastIndexBytes = ((char*) dynamicArray->array) + dynamicArray->size*dynamicArray->elementSize;
    char* elementBytes = (char*) element;
    for (size_t i = 0; i < dynamicArray->elementSize; i++) {
        lastIndexBytes[i] = elementBytes[i];
    }

    dynamicArray->size++;
}

void* getIndexDynamicArray(const DynamicArray* dynamicArray, size_t index) {
    if (index >= dynamicArray->size) {
        return NULL;
    }

    return (void*) (((char*) dynamicArray->array) + index*dynamicArray->elementSize);
}

void destroyDynamicArray(DynamicArray* dynamicArray) {
    free(dynamicArray->array);
    dynamicArray->array = NULL;
    dynamicArray->size = 0;
    dynamicArray->capacity = 0;
    dynamicArray->elementSize = 0;
}
