#include <stdio.h>
#include <string.h>
#define SIZE 20

void stringInsert(char str[], char c, int position); // function prototype.
// main function, the program will start from this function.
void main() {
    char str[SIZE];
    char c;
    int position;

    printf("Type in the word and press Enter: ");
    // fgets(str, sizeof(str), stdin);
    scanf("%20s", str); // Collects the input from the user and assign it to the str variable (which is a pointer).

    printf("Type in the the character to be inserted: "); 
    scanf(" %c", &c); //  Collects the input from the user and assigns it to the address ofthe c variable.

    printf("Type in the position of the character to be inserted: ");
    scanf("%i", &position); // Collects the input from the user and assign it to the address of the variable position.

    printf("\nOriginal word = %s", str);
    stringInsert(str, c, position); // call to function.
    printf("\nModified word = %s", str);
}
// main function, the program will start from this function.
void stringInsert(char str[], char c, int position) {
    char modifiedWord[strlen(str)+1]; // Creates a char array of the length of the str array without the null terminator + 1;

    for(int i = 0; i < sizeof(modifiedWord) + 1; i++) { // Loop throygh from 0 to size of newly created array.
        if (i < position - 1) { // if the current index is not the same as the index of the word to be replaced then just assign the char at index i to the char i of the modifiedword.
            modifiedWord[i] = str[i];
        } else if (i == position - 1){ // else if they are the same assign the character to be inserted to cell i of the modified word.
            modifiedWord[i] = c;
        } else { // else this will mean the character has been already inserted and character at index of modified word needs to have the character of str at the previous index.
            modifiedWord[i] = str[i - 1];
        }
    }

    strcpy(str, modifiedWord); // copy the contents of modifiedword to str.
}