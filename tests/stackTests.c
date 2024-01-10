#include <stdio.h>
#include <stdint.h>
#include "../Stack.h"

int main() {
    Stack myStack;
    initStack(&myStack);

    printf("Test Case: Empty Stack\n");
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));

    printf("\nTest Case: Pushing elements to stack\n");
    printf("Pushing 10\n");
    pushStack(&myStack, (void*) (uintptr_t) 10);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Pushing 20\n");
    pushStack(&myStack, (void*) (uintptr_t) 20);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Pushing 30\n");
    pushStack(&myStack, (void*) (uintptr_t) 30);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));

    printf("\nTest Case: Popping elements from the stack\n");
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));

    printf("\nTest Case: Popping elements from an empty stack\n");
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));


    printf("\nTest Case: Pushing and popping elements to stack again\n");
    printf("Pushing 10\n");
    pushStack(&myStack, (void*) (uintptr_t) 10);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Pushing 20\n");
    pushStack(&myStack, (void*) (uintptr_t) 20);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Pushing 30\n");
    pushStack(&myStack, (void*) (uintptr_t) 30);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    
    printf("\nTest Case: Destroy Stack:\n");
    destroyStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));

    printf("\nTest Case: Pushing and popping elements to stack last time\n");
    printf("Pushing 10\n");
    pushStack(&myStack, (void*) (uintptr_t) 10);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Pushing 20\n");
    pushStack(&myStack, (void*) (uintptr_t) 20);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Pushing 30\n");
    pushStack(&myStack, (void*) (uintptr_t) 30);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));
    printf("Popping:\n");
    popStack(&myStack);
    printf("Top of stack: %zu\n", (size_t) topStack(&myStack));

    return 0;
}