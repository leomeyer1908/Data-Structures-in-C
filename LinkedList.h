#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include "DoublyNode.h"

typedef struct LinkedList {
    DoublyNode* head;
    DoublyNode* tail;
} LinkedList;

void initList(LinkedList* list);

void pushBackList(LinkedList* list, void* value);

void removeElementList(LinkedList* list, void* value);

void destroyList(LinkedList* list);


#endif