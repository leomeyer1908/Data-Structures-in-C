#include <stdio.h>
#include <stdint.h>
#include "../HashSet.h"

void printList(LinkedList* list) {
    DoublyNode* currentNode = list->head;
    while (currentNode != NULL) {
        printf("%zu", (size_t)currentNode->value); 
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
    // Initialize HashSet with an initial capacity of 4
    HashSet mySet;
    initHashSet(&mySet, (size_t) 7, NULL, NULL);

    printf("Test Case: Empty Set\n");
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys:");
    printList(&mySet.keys);

    // Insert elements into the set
    printf("\nTest Case: Insert elements into set (42, 17, 8, 29, 55)\n");
    insertHashSet(&mySet, (void*) 42);
    insertHashSet(&mySet, (void*) 17);
    insertHashSet(&mySet, (void*) 8);
    insertHashSet(&mySet, (void*) 29);
    insertHashSet(&mySet, (void*) 55);
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    // Remove an element and test containment again
    printf("\nTest Case: Remove element 17\n");
    removeElementHashSet(&mySet, (void*) 17);
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    // Try to remove a non-existent element
    printf("\nTest Case: Remove non-existant element (99)\n");
    removeElementHashSet(&mySet, (void*) 99);
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    // Insert more elements to trigger a resize
    printf("\nTest Case: Insert more elements to trigger resize (88, 13)\n");
    insertHashSet(&mySet, (void*) 88);
    insertHashSet(&mySet, (void*) 13);
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet, (void*) 13));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    printf("\nTest Case: Copy hash set\n");
    HashSet mySet2;
    copyHashSet(&mySet, &mySet2);
    printf("Original Set:\n");
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet, (void*) 13));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);
    printf("New Set:\n");
    printf("Contains 42: %d\n", containsHashSet(&mySet2, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet2, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet2, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet2, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet2, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet2, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet2, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet2, (void*) 13));
    printf("Size: %zu\n", mySet2.size);
    printf("Capacity: %zu\n", mySet2.capacity);
    printf("Keys: ");
    printList(&mySet2.keys);


    printf("\nTest Case: Remove elements (42, 8) and insert new element (101) to old set\n");
    removeElementHashSet(&mySet, (void*) 42);
    removeElementHashSet(&mySet, (void*) 8);
    insertHashSet(&mySet, (void*) 101);
    printf("Original Set:\n");
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet, (void*) 13));
    printf("Contains 101: %d\n", containsHashSet(&mySet, (void*) 101));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);
    printf("New Set:\n");
    printf("Contains 42: %d\n", containsHashSet(&mySet2, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet2, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet2, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet2, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet2, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet2, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet2, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet2, (void*) 13));
    printf("Contains 101: %d\n", containsHashSet(&mySet2, (void*) 101));
    printf("Size: %zu\n", mySet2.size);
    printf("Capacity: %zu\n", mySet2.capacity);
    printf("Keys: ");
    printList(&mySet2.keys);

    printf("\nTest Case: Destroy new set\n");
    destroyHashSet(&mySet2);
    printf("Original Set:\n");
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet, (void*) 13));
    printf("Contains 101: %d\n", containsHashSet(&mySet, (void*) 101));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);
    printf("New Set:\n");
    printf("Contains 42: %d\n", containsHashSet(&mySet2, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet2, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet2, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet2, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet2, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet2, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet2, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet2, (void*) 13));
    printf("Contains 101: %d\n", containsHashSet(&mySet2, (void*) 101));
    printf("Size: %zu\n", mySet2.size);
    printf("Capacity: %zu\n", mySet2.capacity);
    printf("Keys: ");
    printList(&mySet2.keys);

    printf("\nTest Case: Remove all keys from set\n");
    removeElementHashSet(&mySet, (void*) 29);
    removeElementHashSet(&mySet, (void*) 55);
    removeElementHashSet(&mySet, (void*) 99);
    removeElementHashSet(&mySet, (void*) 88);
    removeElementHashSet(&mySet, (void*) 13);
    removeElementHashSet(&mySet, (void*) 101);
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet, (void*) 13));
    printf("Contains 101: %d\n", containsHashSet(&mySet, (void*) 101));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    printf("\nTest Case: insert duplicate to HashSet (200)\n");
    printf("First insert:\n");
    insertHashSet(&mySet, (void*) 200);
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet, (void*) 13));
    printf("Contains 101: %d\n", containsHashSet(&mySet, (void*) 101));
    printf("Contains 200: %d\n", containsHashSet(&mySet, (void*) 200));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);
    printf("Second insert:\n");
    insertHashSet(&mySet, (void*) 200);
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet, (void*) 13));
    printf("Contains 101: %d\n", containsHashSet(&mySet, (void*) 101));
    printf("Contains 200: %d\n", containsHashSet(&mySet, (void*) 200));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    printf("\nTest Case: Destroy HashSet\n");
    destroyHashSet(&mySet);
    printf("Contains 42: %d\n", containsHashSet(&mySet, (void*) 42));
    printf("Contains 17: %d\n", containsHashSet(&mySet, (void*) 17));
    printf("Contains 8: %d\n", containsHashSet(&mySet, (void*) 8));
    printf("Contains 29: %d\n", containsHashSet(&mySet, (void*) 29));
    printf("Contains 55: %d\n", containsHashSet(&mySet, (void*) 55));
    printf("Contains 99: %d\n", containsHashSet(&mySet, (void*) 99));
    printf("Contains 88: %d\n", containsHashSet(&mySet, (void*) 88));
    printf("Contains 13: %d\n", containsHashSet(&mySet, (void*) 13));
    printf("Contains 101: %d\n", containsHashSet(&mySet, (void*) 101));
    printf("Contains 200: %d\n", containsHashSet(&mySet, (void*) 200));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

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
    initHashSet(&mySet, 5, &immutableArrayHashFunc, &immutableArrayCmpFunc);

    printf("\nTest Case: Insert keys (Arrays A, B, and C)\n");
    insertHashSet(&mySet, (void*) &immutableArrayA);
    insertHashSet(&mySet, (void*) &immutableArrayB);
    insertHashSet(&mySet, (void*) &immutableArrayC);
    printf("Contains key A: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashSet(&mySet, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);

    printf("\nTest Case: Remove Non-existant Array D\n");
    removeElementHashSet(&mySet, (void*) &immutableArrayD);
    printf("Contains key A: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashSet(&mySet, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);

    printf("\nTest Case: Insert Array D and remove Array B\n");
    insertHashSet(&mySet, (void*) &immutableArrayD);
    removeElementHashSet(&mySet, (void*) &immutableArrayB);
    printf("Contains key A: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashSet(&mySet, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);

    printf("\nTest Case: Insert duplicate (Array C)\n");
    insertHashSet(&mySet, (void*) &immutableArrayC);
    printf("Contains key A: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashSet(&mySet, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);


    printf("\nTest Case: Copy HashMap with Custom Hash and Cmp\n");
    copyHashSet(&mySet, &mySet2);
    printf("Old Set Contains key A: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Old Set Contains key A2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Old Set Contains key B: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Old Set Contains key B2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Old Set Contains key C: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Old Set Contains key C2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Old Set Contains key D: %s\n", containsHashSet(&mySet, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Old Set Size: %zu\n", mySet.size);
    printf("Old Set Capacity: %zu\n", mySet.capacity);
    printf("New Set Contains key A: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("New Set Contains key A2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("New Set Contains key B: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("New Set Contains key B2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("New Set Contains key C: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("New Set Contains key C2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("New Set Contains key D: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("New Set Size: %zu\n", mySet2.size);
    printf("New Set Capacity: %zu\n", mySet2.capacity);

    printf("\nTest Case: Removing and inserting to old set does not affect new (Remove Array A2, C, and insert B2) \n");
    removeElementHashSet(&mySet, (void*) &immutableArrayA2);
    removeElementHashSet(&mySet, (void*) &immutableArrayC);
    insertHashSet(&mySet, (void*) &immutableArrayB2);
    printf("Old Set Contains key A: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Old Set Contains key A2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Old Set Contains key B: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Old Set Contains key B2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Old Set Contains key C: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Old Set Contains key C2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Old Set Contains key D: %s\n", containsHashSet(&mySet, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Old Set Size: %zu\n", mySet.size);
    printf("Old Set Capacity: %zu\n", mySet.capacity);
    printf("New Set Contains key A: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("New Set Contains key A2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("New Set Contains key B: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("New Set Contains key B2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("New Set Contains key C: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("New Set Contains key C2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("New Set Contains key D: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("New Set Size: %zu\n", mySet2.size);
    printf("New Set Capacity: %zu\n", mySet2.capacity);

    printf("\nTest Case: Destroy new set \n");
    destroyHashSet(&mySet2);
    printf("Old Set Contains key A: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Old Set Contains key A2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Old Set Contains key B: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Old Set Contains key B2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Old Set Contains key C: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Old Set Contains key C2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Old Set Contains key D: %s\n", containsHashSet(&mySet, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Old Set Size: %zu\n", mySet.size);
    printf("Old Set Capacity: %zu\n", mySet.capacity);
    printf("New Set Contains key A: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("New Set Contains key A2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("New Set Contains key B: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("New Set Contains key B2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("New Set Contains key C: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("New Set Contains key C2: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("New Set Contains key D: %s\n", containsHashSet(&mySet2, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("New Set Size: %zu\n", mySet2.size);
    printf("New Set Capacity: %zu\n", mySet2.capacity);


    printf("\nTest Case: Remove all keys\n");
    removeElementHashSet(&mySet, (void*) &immutableArrayD);
    removeElementHashSet(&mySet, (void*) &immutableArrayB2);
    printf("Contains key A: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA) ? "Yes" : "No");
    printf("Contains key A2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayA2) ? "Yes" : "No");
    printf("Contains key B: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB) ? "Yes" : "No");
    printf("Contains key B2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayB2) ? "Yes" : "No");
    printf("Contains key C: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC) ? "Yes" : "No");
    printf("Contains key C2: %s\n", containsHashSet(&mySet, (void*) &immutableArrayC2) ? "Yes" : "No");
    printf("Contains key D: %s\n", containsHashSet(&mySet, (void*) &immutableArrayD) ? "Yes" : "No");
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);

    // Destroy the set
    printf("\nTest Case: Destroy set\n");
    destroyHashSet(&mySet);





    free(a);
    free(b);
    free(c);
    free(a2);
    free(b2);
    free(c2);
    free(d);

    printf("\nTest Case: Make Set from list\n");
    initHashSet(&mySet, (size_t) 5, NULL, NULL);
    LinkedList myList;
    initList(&myList);
    pushBackList(&myList, (void*) (uintptr_t) 10);
    pushBackList(&myList, (void*) (uintptr_t) 20);
    pushBackList(&myList, (void*) (uintptr_t) 30);
    pushBackList(&myList, (void*) (uintptr_t) 40);
    pushBackList(&myList, (void*) (uintptr_t) 50);
    getSetFromList(&myList, &mySet);
    printf("List:\n");
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size
    printf("Set:\n");
    printf("Contains 10: %d\n", containsHashSet(&mySet, (void*) 10));
    printf("Contains 20: %d\n", containsHashSet(&mySet, (void*) 20));
    printf("Contains 30: %d\n", containsHashSet(&mySet, (void*) 30));
    printf("Contains 40: %d\n", containsHashSet(&mySet, (void*) 40));
    printf("Contains 50: %d\n", containsHashSet(&mySet, (void*) 50));
    printf("Contains 60: %d\n", containsHashSet(&mySet, (void*) 60));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    printf("\nTest Case: Removing elements (30, 40) and inserting (60) to list does not change set\n");
    removeElementList(&myList, (void*) (uintptr_t) 30);
    removeElementList(&myList, (void*) (uintptr_t) 40);
    pushBackList(&myList, (void*) (uintptr_t) 60);
    printf("List:\n");
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size
    printf("Set:\n");
    printf("Contains 10: %d\n", containsHashSet(&mySet, (void*) 10));
    printf("Contains 20: %d\n", containsHashSet(&mySet, (void*) 20));
    printf("Contains 30: %d\n", containsHashSet(&mySet, (void*) 30));
    printf("Contains 40: %d\n", containsHashSet(&mySet, (void*) 40));
    printf("Contains 50: %d\n", containsHashSet(&mySet, (void*) 50));
    printf("Contains 60: %d\n", containsHashSet(&mySet, (void*) 60));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    printf("\nTest Case: Destroy List\n");
    destroyList(&myList);
    printf("List:\n");
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size
    printf("Set:\n");
    printf("Contains 10: %d\n", containsHashSet(&mySet, (void*) 10));
    printf("Contains 20: %d\n", containsHashSet(&mySet, (void*) 20));
    printf("Contains 30: %d\n", containsHashSet(&mySet, (void*) 30));
    printf("Contains 40: %d\n", containsHashSet(&mySet, (void*) 40));
    printf("Contains 50: %d\n", containsHashSet(&mySet, (void*) 50));
    printf("Contains 60: %d\n", containsHashSet(&mySet, (void*) 60));
    printf("Size: %zu\n", mySet.size);
    printf("Capacity: %zu\n", mySet.capacity);
    printf("Keys: ");
    printList(&mySet.keys);

    destroyHashSet(&mySet);

    return 0;
}