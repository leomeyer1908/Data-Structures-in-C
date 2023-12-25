#include "LinkedList.h"



void initList(LinkedList* list) {
    list->head = NULL;
}

void pushBackList(LinkedList* list, void* value) {
    Node* newNode = getNewNode();
    newNode->value = value;
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        Node* currentNode = list->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void removeElementList(LinkedList* list, void* value) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->value == value) {
        Node* head = list->head;
        list->head = list->head->next;
        free(head);
        return;
    }
    Node* currentNode = list->head;
    while (currentNode->next != NULL) {
        Node* nextNode = currentNode->next;
        if (nextNode->value == value) {
            currentNode->next = nextNode->next;
            free(nextNode);
            break;
        }
        currentNode = nextNode;
    }
}

void destroyList(LinkedList* list) {
    Node* currentNode = list->head;
    Node* nextNode;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    list->head = NULL;
}

