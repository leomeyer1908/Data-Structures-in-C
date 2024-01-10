#include <stdio.h>
#include "../HashMap.h"

//Assumes value is a char*
void printKeyValuePairs(LinkedList* list) {
    DoublyNode* currentNode = list->head;
    while (currentNode != NULL) {
        size_t key = (size_t)((KeyValuePair*)currentNode->value)->key;
        char* value = (char*) ((KeyValuePair*)currentNode->value)->value;
        printf("%zu: %s", key, value);
        currentNode = currentNode->next;
        if (currentNode != NULL) {
            printf(", ");
        }
    }
    printf("\n");
}

typedef struct ImmutableArray {
    size_t size;
    const int* array;
} ImmutableArray;

size_t immutableArrayHashFunc(const void* key, const size_t capacity) {
    size_t size = (size_t) ((ImmutableArray*) key)->size;
    const int* array = (const int*) ((ImmutableArray*) key)->array;

    size_t total = 0;
    for (size_t i = 0; i < size; i++) {
        total += (size_t) array[i];
    }

    return (size_t) total % capacity;
}

int immutableArrayCmpFunc(const void* key1, const void* key2) {
    size_t size1 = (size_t) ((ImmutableArray*) key1)->size;
    const int* array1 = (const int*) ((ImmutableArray*) key1)->array;

    size_t size2 = (size_t) ((ImmutableArray*) key2)->size;
    const int* array2 = (const int*) ((ImmutableArray*) key2)->array;

    if (size1 != size2) {
        return 0;
    }

    for (size_t i = 0; i < size1; i++) {
        if (array1[i] != array2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Initialize HashMap with an initial capacity of 5
    HashMap myMap;
    initHashMap(&myMap, (size_t) 7, NULL, NULL);

    printf("Test Case: Empty Map\n");
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys:");
    printKeyValuePairs(&myMap.keyValuePairs);

    // Insert elements into the map
    printf("\nTest Case: Insert elements into map (42, 17, 8, 29, 55)\n");
    insertHashMap(&myMap, (void*) 42, (void*) "Fourty-two");
    insertHashMap(&myMap, (void*) 17, (void*) "Seventeen");
    insertHashMap(&myMap, (void*) 8, (void*) "Eight");
    insertHashMap(&myMap, (void*) 29, (void*) "Twenty-Nine");
    insertHashMap(&myMap, (void*) 55, (void*) "Fifty-five");
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    // Remove an element and test containment again
    printf("\nTest Case: Remove element 17\n");
    removeElementHashMap(&myMap, (void*) 17);
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    // Try to remove a non-existent element
    printf("\nTest Case: Remove non-existant element (99)\n");
    removeElementHashMap(&myMap, (void*) 99);
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    // Insert more elements to trigger a resize
    printf("\nTest Case: Insert more elements to trigger resize (88, 13)\n");
    insertHashMap(&myMap, (void*) 88, "Eighty-eight");
    insertHashMap(&myMap, (void*) 13, "Thirteen");
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Contains 88: %d\n", containsHashMap(&myMap, (void*) 88));
    printf("Contains 13: %d\n", containsHashMap(&myMap, (void*) 13));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Get 88: %s\n", (char*) getHashMap(&myMap, (void*) 88));
    printf("Get 13: %s\n", (char*) getHashMap(&myMap, (void*) 13));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    printf("\nTest Case: Update HashMap (8, 29, 55)\n");
    updateHashMap(&myMap, (void*) 8, "Eight Updated");
    updateHashMap(&myMap, (void*) 29, "Twenty-Nine Updated");
    updateHashMap(&myMap, (void*) 55, "Fifty-Five Updated");
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Contains 88: %d\n", containsHashMap(&myMap, (void*) 88));
    printf("Contains 13: %d\n", containsHashMap(&myMap, (void*) 13));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Get 88: %s\n", (char*) getHashMap(&myMap, (void*) 88));
    printf("Get 13: %s\n", (char*) getHashMap(&myMap, (void*) 13));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    printf("\nTest Case: Update Non-Existant Element (300)\n");
    updateHashMap(&myMap, (void*) 300, "Three-Hundred");
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Contains 88: %d\n", containsHashMap(&myMap, (void*) 88));
    printf("Contains 13: %d\n", containsHashMap(&myMap, (void*) 13));
    printf("Contains 300: %d\n", containsHashMap(&myMap, (void*) 300));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Get 88: %s\n", (char*) getHashMap(&myMap, (void*) 88));
    printf("Get 13: %s\n", (char*) getHashMap(&myMap, (void*) 13));
    printf("Get 300: %s\n", (char*) getHashMap(&myMap, (void*) 300));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);


    printf("\nTest Case: Remove all keys from map\n");
    removeElementHashMap(&myMap, (void*) 42);
    removeElementHashMap(&myMap, (void*) 8);
    removeElementHashMap(&myMap, (void*) 29);
    removeElementHashMap(&myMap, (void*) 55);
    removeElementHashMap(&myMap, (void*) 88);
    removeElementHashMap(&myMap, (void*) 13);
    removeElementHashMap(&myMap, (void*) 300);
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Contains 88: %d\n", containsHashMap(&myMap, (void*) 88));
    printf("Contains 13: %d\n", containsHashMap(&myMap, (void*) 13));
    printf("Contains 300: %d\n", containsHashMap(&myMap, (void*) 300));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Get 88: %s\n", (char*) getHashMap(&myMap, (void*) 88));
    printf("Get 13: %s\n", (char*) getHashMap(&myMap, (void*) 13));
    printf("Get 300: %s\n", (char*) getHashMap(&myMap, (void*) 300));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    printf("\nTest Case: insert duplicate to HashMap (200)\n");
    printf("First insert:\n");
    insertHashMap(&myMap, (void*) 200, "Two-hundred");
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Contains 88: %d\n", containsHashMap(&myMap, (void*) 88));
    printf("Contains 13: %d\n", containsHashMap(&myMap, (void*) 13));
    printf("Contains 300: %d\n", containsHashMap(&myMap, (void*) 300));
    printf("Contains 200: %d\n", containsHashMap(&myMap, (void*) 200));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Get 88: %s\n", (char*) getHashMap(&myMap, (void*) 88));
    printf("Get 13: %s\n", (char*) getHashMap(&myMap, (void*) 13));
    printf("Get 300: %s\n", (char*) getHashMap(&myMap, (void*) 300));
    printf("Get 200: %s\n", (char*) getHashMap(&myMap, (void*) 200));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);
    printf("Second insert:\n");
    insertHashMap(&myMap, (void*) 200, "Two-hundred duplicate");
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Contains 88: %d\n", containsHashMap(&myMap, (void*) 88));
    printf("Contains 13: %d\n", containsHashMap(&myMap, (void*) 13));
    printf("Contains 300: %d\n", containsHashMap(&myMap, (void*) 300));
    printf("Contains 200: %d\n", containsHashMap(&myMap, (void*) 200));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Get 88: %s\n", (char*) getHashMap(&myMap, (void*) 88));
    printf("Get 13: %s\n", (char*) getHashMap(&myMap, (void*) 13));
    printf("Get 300: %s\n", (char*) getHashMap(&myMap, (void*) 300));
    printf("Get 200: %s\n", (char*) getHashMap(&myMap, (void*) 200));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    printf("\nTest Case: Destroy HashMap\n");
    destroyHashMap(&myMap);
    printf("Contains 42: %d\n", containsHashMap(&myMap, (void*) 42));
    printf("Contains 17: %d\n", containsHashMap(&myMap, (void*) 17));
    printf("Contains 8: %d\n", containsHashMap(&myMap, (void*) 8));
    printf("Contains 29: %d\n", containsHashMap(&myMap, (void*) 29));
    printf("Contains 55: %d\n", containsHashMap(&myMap, (void*) 55));
    printf("Contains 99: %d\n", containsHashMap(&myMap, (void*) 99));
    printf("Contains 88: %d\n", containsHashMap(&myMap, (void*) 88));
    printf("Contains 13: %d\n", containsHashMap(&myMap, (void*) 13));
    printf("Contains 300: %d\n", containsHashMap(&myMap, (void*) 300));
    printf("Contains 200: %d\n", containsHashMap(&myMap, (void*) 200));
    printf("Get 42: %s\n", (char*) getHashMap(&myMap, (void*) 42));
    printf("Get 17: %s\n", (char*) getHashMap(&myMap, (void*) 17));
    printf("Get 8: %s\n", (char*) getHashMap(&myMap, (void*) 8));
    printf("Get 29: %s\n", (char*) getHashMap(&myMap, (void*) 29));
    printf("Get 55: %s\n", (char*) getHashMap(&myMap, (void*) 55));
    printf("Get 99: %s\n", (char*) getHashMap(&myMap, (void*) 99));
    printf("Get 88: %s\n", (char*) getHashMap(&myMap, (void*) 88));
    printf("Get 13: %s\n", (char*) getHashMap(&myMap, (void*) 13));
    printf("Get 300: %s\n", (char*) getHashMap(&myMap, (void*) 300));
    printf("Get 200: %s\n", (char*) getHashMap(&myMap, (void*) 200));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    // Test Case 6: Using immutable array
    int* a = (int*) malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++) {
        a[i] = i*i;
    }
    ImmutableArray immutableArrayA;
    immutableArrayA.array = (const int*) a;
    immutableArrayA.size = 5;

    int* b = (int*) malloc(6*sizeof(int));
    for (int i = 0; i < 6; i++) {
        b[i] = i;
    }
    ImmutableArray immutableArrayB;
    immutableArrayB.array = (const int*) b;
    immutableArrayB.size = 6;

    int* c = (int*) malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++) {
        c[i] = i*2;
    }
    ImmutableArray immutableArrayC;
    immutableArrayC.array = (const int*) c;
    immutableArrayC.size = 3;

    int* a2 = (int*) malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++) {
        a2[i] = i*i;
    }
    ImmutableArray immutableArrayA2;
    immutableArrayA2.array = (const int*) a2;
    immutableArrayA2.size = 5;

    int* b2 = (int*) malloc(6*sizeof(int));
    for (int i = 0; i < 6; i++) {
        b2[i] = i;
    }
    ImmutableArray immutableArrayB2;
    immutableArrayB2.array = (const int*) b2;
    immutableArrayB2.size = 6;

    int* c2 = (int*) malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++) {
        c2[i] = i*2;
    }
    ImmutableArray immutableArrayC2;
    immutableArrayC2.array = (const int*) c2;
    immutableArrayC2.size = 3;

    int* d = (int*) malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++) {
        d[i] = i*3;
    }
    ImmutableArray immutableArrayD;
    immutableArrayD.array = (const int*) d;
    immutableArrayD.size = 3;

    printf("\n\nCustom Hash and Cmp Func Test\n");
    printf("Created immutable arrays A, B, C, D, and A2, B2, and C2. Check source code for more detail.\n");
    initHashMap(&myMap, 5, &immutableArrayHashFunc, &immutableArrayCmpFunc);

    printf("\nTest Case: Insert keys (Arrays A, B, and C)\n");
    insertHashMap(&myMap, (void*) &immutableArrayA, "A");
    insertHashMap(&myMap, (void*) &immutableArrayB, "B");
    insertHashMap(&myMap, (void*) &immutableArrayC, "C");
    printf("Contains key A: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashMap(&myMap, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Get key A: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA));
    printf("Get key A2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA2));
    printf("Get key B: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB));
    printf("Get key B2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB2));
    printf("Get key C: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC));
    printf("Get key C2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC2));
    printf("Get key D: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayD));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);

    printf("\nTest Case: Remove Array D\n");
    removeElementHashMap(&myMap, (void*) &immutableArrayD);
    printf("Contains key A: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashMap(&myMap, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Get key A: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA));
    printf("Get key A2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA2));
    printf("Get key B: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB));
    printf("Get key B2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB2));
    printf("Get key C: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC));
    printf("Get key C2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC2));
    printf("Get key D: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayD));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);

    printf("\nTest Case: Insert Array D and remove Array B\n");
    insertHashMap(&myMap, (void*) &immutableArrayD, "D");
    removeElementHashMap(&myMap, (void*) &immutableArrayB);
    printf("Contains key A: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashMap(&myMap, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Get key A: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA));
    printf("Get key A2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA2));
    printf("Get key B: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB));
    printf("Get key B2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB2));
    printf("Get key C: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC));
    printf("Get key C2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC2));
    printf("Get key D: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayD));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);

    printf("\nTest Case: Insert duplicate (Array C)\n");
    insertHashMap(&myMap, (void*) &immutableArrayC, "C Duplicate");
    printf("Contains key A: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashMap(&myMap, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Get key A: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA));
    printf("Get key A2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA2));
    printf("Get key B: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB));
    printf("Get key B2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB2));
    printf("Get key C: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC));
    printf("Get key C2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC2));
    printf("Get key D: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayD));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);

    printf("\nTest Case: Update HashMap (A)\n");
    updateHashMap(&myMap, (void*) &immutableArrayA, "A Updated");
    printf("Contains key A: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashMap(&myMap, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Get key A: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA));
    printf("Get key A2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA2));
    printf("Get key B: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB));
    printf("Get key B2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB2));
    printf("Get key C: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC));
    printf("Get key C2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC2));
    printf("Get key D: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayD));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);

    printf("\nTest Case: Update Non-Existant Element (B2)\n");
    updateHashMap(&myMap, (void*) &immutableArrayB2, "B Updated");
    printf("Contains key A: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashMap(&myMap, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Get key A: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA));
    printf("Get key A2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA2));
    printf("Get key B: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB));
    printf("Get key B2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB2));
    printf("Get key C: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC));
    printf("Get key C2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC2));
    printf("Get key D: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayD));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);

    printf("\nTest Case: Remove all keys\n");
    removeElementHashMap(&myMap, (void*) &immutableArrayB);
    removeElementHashMap(&myMap, (void*) &immutableArrayC);
    removeElementHashMap(&myMap, (void*) &immutableArrayA);
    removeElementHashMap(&myMap, (void*) &immutableArrayD);
    printf("Contains key A: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashMap(&myMap, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashMap(&myMap, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Get key A: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA));
    printf("Get key A2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayA2));
    printf("Get key B: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB));
    printf("Get key B2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayB2));
    printf("Get key C: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC));
    printf("Get key C2: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayC2));
    printf("Get key D: %s\n", (char*) getHashMap(&myMap, (void*) &immutableArrayD));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);

    // Destroy the map
    printf("\nTest Case: Destroy map\n");
    destroyHashMap(&myMap);

    free(a);
    free(b);
    free(c);
    free(a2);
    free(b2);
    free(c2);
    free(d);


    printf("\nTest Case: Add the same value to different keys by adding keys 1 and 2 with a shared char*\n");
    destroyHashMap(&myMap);
    initHashMap(&myMap, 5, NULL, NULL);
    char* value = "value";
    insertHashMap(&myMap, (void*) 1, value);
    insertHashMap(&myMap, (void*) 2, value);
    printf("Contains 1: %d\n", containsHashMap(&myMap, (void*) 1));
    printf("Contains 2: %d\n", containsHashMap(&myMap, (void*) 1));
    printf("Get 1: %s\n", (char*) getHashMap(&myMap, (void*) 1));
    printf("Get 2: %s\n", (char*) getHashMap(&myMap, (void*) 2));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    printf("\nTest Case: Changing value of one key will not change the value (changing key 1)\n");
    updateHashMap(&myMap, (void*) 1, "New Value");
    printf("Contains 1: %d\n", containsHashMap(&myMap, (void*) 1));
    printf("Contains 2: %d\n", containsHashMap(&myMap, (void*) 1));
    printf("Get 1: %s\n", (char*) getHashMap(&myMap, (void*) 1));
    printf("Get 2: %s\n", (char*) getHashMap(&myMap, (void*) 2));
    printf("Size: %zu\n", myMap.size);
    printf("Capacity: %zu\n", myMap.capacity);
    printf("Keys: ");
    printKeyValuePairs(&myMap.keyValuePairs);

    destroyHashMap(&myMap);

    return 0;
}