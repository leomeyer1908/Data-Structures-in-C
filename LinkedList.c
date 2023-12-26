#include "LinkedList.h"



void initList(LinkedList* list) {
    list->head = NULL;
}

void pushBackList(LinkedList* list, void* value) {
    DoublyNode* newNode = getNewDoublyNode();
    newNode->value = value;
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
    if (list->head == NULL) {
        return;
    }
    if (list->head->value == value) {
        DoublyNode* head = list->head;
        list->head = list->head->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
        free(head);
        return;
    }
    DoublyNode* currentNode = list->head;
    while (currentNode != NULL) {
        if (currentNode->value == value) {
            currentNode->prev->next = currentNode->next;
            if (currentNode->next != NULL) {
                currentNode->next->prev = currentNode->prev;
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
}

