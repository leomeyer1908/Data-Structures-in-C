#include "SinglyLinkedList.h"



void initSinglyList(SinglyLinkedList* list) {
    list->head = NULL;
}

void pushBackSinglyList(SinglyLinkedList* list, void* value) {
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

void removeElementSinglyList(SinglyLinkedList* list, void* value) {
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

void destroySinglyList(SinglyLinkedList* list) {
    Node* currentNode = list->head;
    Node* nextNode;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    list->head = NULL;
}

