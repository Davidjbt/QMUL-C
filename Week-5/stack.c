#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 30
#define TRUE 1
#define FALSE 0

struct stackNode {
    int nodeData;
    struct stackNode *nextPtr;
};

typedef struct stackNode stackNode;

int isEmpty(stackNode **stackPtr) {
    return *stackPtr == NULL? TRUE: FALSE;
}

void push(stackNode **stackPtr, int nodeData) {
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode));
    assert(newNode!=NULL);
    newNode->nodeData = nodeData;

    newNode->nextPtr = isEmpty(stackPtr) == TRUE? NULL: *stackPtr;
    *stackPtr = newNode;
}

void pop(stackNode  **stackPtr, int nodeData) {
    if (isEmpty(stackPtr) == FALSE) {
        stackNode *tempNode = *stackPtr;
        if (nodeData == tempNode->nodeData) {
            *stackPtr = tempNode->nextPtr;
            free(tempNode);
        } else printf("Argument not allowed!!\n");
    }
}

void printStack(stackNode *stackPtr) {
    if (isEmpty(&stackPtr) == 0) {
        int i = 0;
        printf("\n");
        while (isEmpty(&stackPtr) == 0) {
            i == 0? printf("Stack Pointer --> %i\n", stackPtr->nodeData): printf("%*c %i\n", 17, ' ', stackPtr->nodeData);
            i = 1;
            stackPtr = stackPtr->nextPtr;
        }
        printf("\n");
    } else printf("Stack is empty!!\n");
}

void main() {
    stackNode *stackPtr = NULL;
    char *input;
    char c;
    int exit = 0;
    while (exit == 0) {
        input = (char*) calloc(SIZE, sizeof(char));
        printf("Write stack command or Q to quit: ");
        c = getchar();
        for (int i = 0; c != '\n' && c != EOF && i < sizeof(input); i++) {
            input[i] = c;
            c = getchar();
        }

        if (input[0] != 'Q') {
            char *action = strtok(input, " ");
            int nodeData = atoi(strtok(NULL, " "));

            if (strcmp(action, "push") == 0) {
                push(&stackPtr, nodeData);
                printStack(stackPtr);
            } else if (strcmp(action, "pop") == 0) {
                pop(&stackPtr, nodeData);
                printStack(stackPtr);
            } else {
                
                printf("Action not recognized.");   
            }
        } else exit = 1;
    }
    printf("Exiting program...");
}