#include <stdio.h>
#include <math.h>
// #include <stdlib.h> // if we want to use atoi()
#define ADDITION(a,b) a+b
#define SUBTRACTION(a,b) a-b
#define MULTIPLICATION(a,b) a*b
#define DIVISION(a,b) a/b
#define SIZE 20

// Returns the integer value of the char.
int parseCharToInt(char n) {
    if (n == '1') return 1;
    if (n == '2') return 2;
    if (n == '3') return 3;
    if (n == '4') return 4;
    if (n == '5') return 5;
    if (n == '6') return 6;
    if (n == '7') return 7;
    if (n == '8') return 8;
    if (n == '9') return 9;
    return 0;
}
// function that will return the char array argument convertd as a integer.
int parseCharArrToInt(char operand[]) {
    int value = 0;
    int power = 0;

    // Creating an array which will contain the same values of the input array but without null terminator.
    int actualInputLength = 0;

    while (operand[actualInputLength] != '\0') { // We loop loop through the char array (string) until the current character is equals to the null terminator.
        actualInputLength++;
    }

    char actualOperand[actualInputLength]; // Creates a string of the length of the input minus the null terminator.
    for (int j = 0; j < actualInputLength; j++) { // We copy the contents of the input string into the new char array, excluding the null terminator.
        actualOperand[j] = operand[j];
    }
    // Char array without unused cells done!!!

    for (int i = actualInputLength - 1; i >= 0; i--) { // loop from the index of the last character to  0.
        value += parseCharToInt(actualOperand[i])*pow(10, power); // accumulator pattern, we add the parsed char(now int) times the power to the power of its order.
        power++; // increment order.
    }

    return value;
}

void main() {
    char input[SIZE];
    printf("Enter operation: ");
    scanf("%20s", input);

    // Creating an array which will contain the same values of the input array but without the unused cells.
    int actualOperationLength = 0;

    while (input[actualOperationLength] != '\0') {
        actualOperationLength++;
    }

    char operation[actualOperationLength];
    for (int j = 0; j < actualOperationLength; j++) {
        operation[j] = input[j];
    }
    // Char array without unused cells done!!!

    char operand1[SIZE];
    char operand2[SIZE];
    int operatorIndex = 0;
    char operator = ' ';

    int i = 0;
    //Finds the index at which the operator is.
    while (operator == ' ' && i != SIZE) {
        if (operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == 'x' || operation[i] == '/') {
            operator = operation[i];
            operatorIndex = i;
        }
        i++;
    }
    
    /// If the operator is not empty then it will evaluate the expression.
    if (operator != ' ') {
        // Operand1 will be the content from index 0 to one less than the operator index.
        for (int j = 0; j < operatorIndex; j++) {
            operand1[j] = (int)operation[j];
        }

        i = operatorIndex + 1;
        int j = 0;
        // Operand2 will be the content from one plus the operator index to the end of the operation char.
        while (i < sizeof(operation)) { 
            operand2[j] = operation[i];
            i++;
            j++;
        }

        // Both operands are then converted to integer values using the atoi function. 
        // int a = atoi(operand1);
        // int b = atoi(operand2);
        // Or parse through the array
        int a = parseCharArrToInt(operand1); 
        int b = parseCharArrToInt(operand2); 
        if (operator == '+') printf("Result is %i", ADDITION(a, b)); // if the operator is equals to any of these operation we execute the correspodent macro function.
        else if (operator == '-') printf("Result is %i", SUBTRACTION(a, b));
        else if (operator == '*') printf("Result is %i", MULTIPLICATION(a, b));
        else if (operator == 'x') printf("Result is %i", MULTIPLICATION(a, b));
        else if (operator == '/') printf("Result is %i", DIVISION(a, b));
    } else { // else not valid operator was entered.
        printf("Not operator has been found.");
    }
}
