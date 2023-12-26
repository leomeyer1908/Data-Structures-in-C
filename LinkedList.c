#include "LinkedList.h"



void initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void pushBackList(LinkedList* list, void* value) {
    DoublyNode* newNode = getNewDoublyNode();
    newNode->value = value;
    list->tail = newNode;
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        DoublyNode* currentNode = list->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
        newNode->prev = currentNode;
    }
}

void removeElementList(LinkedList* list, void* value) {
    DoublyNode* currentNode = list->head;
    while (currentNode != NULL) {
        if (currentNode->value == value) {
            if (currentNode->prev != NULL) {
                currentNode->prev->next = currentNode->next;
            } else {
                list->head = currentNode->next;
            }

            if (currentNode->next != NULL) {
                currentNode->next->prev = currentNode->prev;
            } else {
                list->tail = currentNode->prev;
            }

            free(currentNode);
            break;
        }
        currentNode = currentNode->next;
    }
}

void destroyList(LinkedList* list) {
    DoublyNode* currentNode = list->head;
    DoublyNode* nextNode;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    list->head = NULL;
    list->tail = NULL;
}

