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

void removeNodeFromList(LinkedList* list, DoublyNode* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }

    free(node);

}

void removeElementList(LinkedList* list, void* value) {
    DoublyNode* currentNode = list->head;
    while (currentNode != NULL) {
        if (currentNode->value == value) {
            removeNodeFromList(list, currentNode);
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

void copyList(LinkedList* srcList, LinkedList* dstList) {
	if (srcList->head != NULL) {
		DoublyNode* dstNode = getNewDoublyNode();
		dstList->head = dstNode;
		DoublyNode* srcNode = srcList->head;
		while (srcNode != NULL) {
			dstNode->value = srcNode->value;
			if (srcNode->next != NULL) {
				DoublyNode* newDstNode = getNewDoublyNode();
				dstNode->next = newDstNode;
				dstNode = newDstNode;
			}
			srcNode = srcNode->next;
		}
	}
	else {
		dstList->head = NULL;
	}
}

