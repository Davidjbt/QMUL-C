#include <stdio.h>
#include <stdlib.h>
#define ADDITION(a,b) a+b
#define SUBTRACTION(a,b) a-b
#define MULTIPLICATION(a,b) a*b
#define DIVISION(a,b) a/b
#define SIZE 20

void main() {
    char input[SIZE];
    printf("Enter operation: ");
    scanf("%20s", input);
    int actualOperationLength = 0;
    int i = 0;

    while (input[actualOperationLength] != '\0') {
        actualOperationLength++;
    }

    char operation[actualOperationLength];
    for (int j = 0; j < actualOperationLength; j++) {
        operation[j] = input[j];
    }

    char operand1[SIZE];
    char operand2[SIZE];
    int operatorIndex = 0;
    char operator = ' ';

    i = 0;
    while (operator == ' ' && i != SIZE) {
        if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == 'x' || operation[i] == '/') {
            operator = operation[i];
            operatorIndex = i;
        }
        i++;
    }

    if (operator != ' ') {
        for (int j = 0; j < operatorIndex; j++) {
            operand1[j] = (int)operation[j];
        }

        i = operatorIndex + 1;
        int j = 0;
        while (i < sizeof(operation)) { 
            operand2[j] = operation[i];
            i++;
            j++;
        }

        int a = atoi(operand1);
        int b = atoi(operand2);
        if (operator == '+') printf("Result is %i", ADDITION(a, b));
        else if (operator == '-') printf("Result is %i", SUBTRACTION(a, b));
        else if (operator == '*') printf("Result is %i", MULTIPLICATION(a, b));
        else if (operator == 'x') printf("Result is %i", MULTIPLICATION(a, b));
        else if (operator == '/') printf("Result is %i", DIVISION(a, b));
    }
}


// int findOperatorIndex(char operation[]) {

//     for (int i = 0; i < sizeof(operation) / 4; i++) {
//         if (operation == '+' || operation == '-' || operation == '*' || operation == 'x' || operation == '/') return i;
//     }

//     return -1;
// }

// int getOperand(char operation[], int operatorIndex, int operandNumber) {
//     int length = operandNumber == 1? operatorIndex: sizeof(operation)/4 - operatorIndex
//     int temp[length];

//     for (int i; i < operatorIndex; i++) {
//         temp[i] = operation[i];
//     }

//     return atoi(temp);
// }

// void main() {
//     char input[SIZE];
//     printf("Enter operation: ");
//     scanf("%30s", input);
//     int actualOperationLength = 0;
//     int i = 0;
//     while (input[i] != '\0') {
//         actualOperationLength++;
//         i++;
//     }

//     char operation[actualOperationLength];
//     for (int i = 0; i < actualOperationLength; i++) {
//         operation[i] = operation[i];
//     }

//     int operatorIndex = findOperatorIndex(operation);
//     int operand1 = getOperand(operation, operatorIndex, 1);
//     int operand2 = getOperand(operation, operatorIndex, 2);

//     if (operatorIndex != -1) {
        


//     } else {
//         printf("Not a valid operation.")
//     }



// }