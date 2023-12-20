#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>

typedef struct {
    void* array;
    size_t size;
    size_t capacity;
    size_t elementSize;
} DynamicArray;

void initDynamicArray(DynamicArray* dynamicArray, size_t elementSize, size_t initialCapacity);
void pushBackDynamicArray(DynamicArray* dynamicArray, const void* element);
void* getIndexDynamicArray(const DynamicArray* dynamicArray, size_t index);
void destroyDynamicArray(DynamicArray* dynamicArray);


#endif //DYNAMIC_ARRAY_H