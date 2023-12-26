#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include "Node.h"

typedef struct SinglyLinkedList {
    Node* head;
} SinglyLinkedList;

void initSinglyList(SinglyLinkedList* list);

void pushBackSinglyList(SinglyLinkedList* list, void* value);

void removeElementSinglyList(SinglyLinkedList* list, void* value);

void destroySinglyList(SinglyLinkedList* list);


#endif