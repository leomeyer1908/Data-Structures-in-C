#include <stdio.h>
#include <stdint.h>
#include "../LinkedList.h"

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

int main() {
    LinkedList myList;
    initList(&myList);

    printf("Test Case: Empty List\n");
    printList(&myList);
    printf("Size: %zu\n", myList.size); 

    // Verify the elements are in the correct order
    printf("\nTest Case: Push Back Elements (10, 20, 30, 40, 50)\n");

    pushBackList(&myList, (void*) (uintptr_t) 10);
    pushBackList(&myList, (void*) (uintptr_t) 20);
    pushBackList(&myList, (void*) (uintptr_t) 30);
    pushBackList(&myList, (void*) (uintptr_t) 40);
    pushBackList(&myList, (void*) (uintptr_t) 50);

    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    // Test Case: Remove Element from the Middle
    printf("\nTest Case: Remove Element from the Middle \n");
    removeElementList(&myList, (void*) (uintptr_t) 30);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    // Test Case: Remove Element from the Beginning
    printf("\nTest Case: Remove Element from the Beginning\n");
    removeElementList(&myList, (void*) (uintptr_t) 10);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    // Test Case: Remove Element from the End
    printf("\nTest Case: Remove Element from the End\n");
    removeElementList(&myList, (void*) (uintptr_t) 50);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    printf("\nTest Case: Copy List\n");
    LinkedList myList2;
    copyList(&myList, &myList2);

    printf("New List:\n");
    printList(&myList2); 
    printf("New List Size: %zu\n", myList2.size); // Print the size
    printf("Old List:\n");
    printList(&myList); 
    printf("Old List Size: %zu\n", myList.size); // Print the size

    printf("\nTest Case: Modifying old list does not affect new list\n");
    printf("Removing First 2 elements of old list then adding a new one:\n");
    removeElementList(&myList, (void*) (uintptr_t) 20);
    removeElementList(&myList, (void*) (uintptr_t) 40);
    pushBackList(&myList, (void*) (uintptr_t) 90);
    printf("New List:\n");
    printList(&myList2); 
    printf("New List Size: %zu\n", myList2.size); // Print the size
    printf("Old List:\n");
    printList(&myList); 
    printf("Old List Size: %zu\n", myList.size); // Print the size

    printf("\nTest Case: Modifying new list does not affect new list\n");
    printf("Destroying new list: \n");
    destroyList(&myList2);
    printf("New List:\n");
    printList(&myList2); 
    printf("New List Size: %zu\n", myList2.size); // Print the size
    printf("Old List:\n");
    printList(&myList); 
    printf("Old List Size: %zu\n", myList.size); // Print the size


    printf("\nTest Case: Adding duplicate elements then removing both\n");
    pushBackList(&myList, (void*) (uintptr_t) 10);
    pushBackList(&myList, (void*) (uintptr_t) 10);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size
    removeElementList(&myList, (void*) (uintptr_t) 10);
    removeElementList(&myList, (void*) (uintptr_t) 10);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    
    printf("\nTest Case: removing non existant element from list (10):\n");
    removeElementList(&myList, (void*) (uintptr_t) 100);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size


    printf("\nTest Case: removing last element from list:\n");
    removeElementList(&myList, (void*) (uintptr_t) 90);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    printf("\nTest Case: removing element from empty list:\n");
    removeElementList(&myList, (void*) (uintptr_t) 10);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    printf("\nTest Case: Adding element and removing again one more time:\n");
    pushBackList(&myList, (void*) (uintptr_t) 10);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size
    removeElementList(&myList, (void*) (uintptr_t) 10);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    printf("\nTest Case: Destroying list, then adding element and removing again:\n");
    destroyList(&myList);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size
    pushBackList(&myList, (void*) (uintptr_t) 10);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size
    removeElementList(&myList, (void*) (uintptr_t) 10);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size

    printf("\nTest Case: Destroying list again:\n");
    destroyList(&myList);
    printList(&myList);
    printf("Size: %zu\n", myList.size); // Print the size
    //No need to test removeNodeFromList function because it is already called in removeElementList

    return 0;
}