#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 30
#define TRUE 1
#define FALSE 0

struct stackNode { // strucuture that stores some interger and a pointer to another struct of the same type.
    int nodeData;
    struct stackNode *nextPtr;
};

typedef struct stackNode stackNode; // this allows us to just stackNode instead of struct stackNode, 

int isEmpty(stackNode **stackPtr) { // check if the head pointer is empty, and returns a value.
    return *stackPtr == NULL? TRUE: FALSE;
}

void push(stackNode **stackPtr, int nodeData) { // pushes a new node to the stack on the top.
    stackNode *newNode = (stackNode*)malloc(sizeof(stackNode)); // Allocates some chunk of memory that will pointed by a pointer of the stackNode type.
    assert(newNode!=NULL); // Checks if the new node is not null, 
    newNode->nodeData = nodeData; // assign the int parameter to the data of the new node.

    newNode->nextPtr = isEmpty(stackPtr) == TRUE? NULL: *stackPtr; // if the stack pointer is empty NULL will assigned in the nextPtr field of the new node, otherwise the address of the stack pointer will assigned to it.
    *stackPtr = newNode; // now the stack pointer points to the next node.
}

void pop(stackNode  **stackPtr) { // pop the node at the top of the stack.
    if (isEmpty(stackPtr) == FALSE) { // if the stack is not empty
        stackNode *tempNode = *stackPtr; // then create temporary node that will content the node pointed by the stack pointer.
        *stackPtr = tempNode->nextPtr; // now the stack pointer points to the next pointer of temporary node (itself). 
        free(tempNode); // free the temp node, hence the previos node at the top of the stack.
    }
}

void printStack(stackNode *stackPtr) { // prints the content of the stack.
    if (isEmpty(&stackPtr) == 0) { // if the stack is not empty.
        int i = 0;
        printf("\n");
        while (isEmpty(&stackPtr) == 0) { // while the node pointed by the stack pointer is not null, loop
            i == 0? printf("Stack Pointer --> %i\n", stackPtr->nodeData): printf("%*c %i\n", 17, ' ', stackPtr->nodeData); // if 1st entry we will print a indicator that indicates the node on top.
            i = 1; // we change it so that the indicator is not displayed.
            stackPtr = stackPtr->nextPtr; // stackPtr is assigned to the its next ptr.
        }
        printf("\n");
    } else printf("Stack is empty!!\n"); // if the stack is empty display the message.
}
// main function, the program will start from this function.
void main() {
    stackNode *stackPtr = NULL; // stackPtr created and initilized with NULL.
    char *input;
    char c;
    int exit = 0;
    while (exit == 0) { // while exit is 0 then loop
        input = (char*) calloc(SIZE, sizeof(char)); // we allocate some chunk of memory to the input pointer 
        printf("Write stack command or Q to quit: ");
        c = getchar(); // Collects the input of user and assigns it to the input array. 
        for (int i = 0; c != '\n' && c != EOF && i < sizeof(input); i++) {
            input[i] = c;
            c = getchar();
        }

        if (input[0] != 'Q') { // if the 1st character of input is not equals to Q then 
            char *action = strtok(input, " "); // strtok return a pointer that points to the 1st word seperated by a space.
            int nodeData;
            if (strcmp(action, "push") == 0) { // if the action is push then we need another argument.
                nodeData = atoi(strtok(NULL, " ")); // obtained by using once more strktok, atoi is used to parse the string to a integer value.
            }

            if (strcmp(action, "push") == 0) { // if the action is equals to push
                push(&stackPtr, nodeData); // then call method.
                printStack(stackPtr); // print stack contents.
            } else if (strcmp(action, "pop") == 0) {
                pop(&stackPtr); // then call method.
                printStack(stackPtr); // print stack contents.
            } else { // not valid action was entered.
                printf("Action not recognized.");   
            }
        } else exit = 1;
    }
    printf("Exiting program...");
}