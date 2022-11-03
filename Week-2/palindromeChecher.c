#include <stdio.h>
// main function, the program will start from this function.
void main() {
    char word[30];
    printf("Enter word: ");
    scanf("%30s", word); // Collects a input and stores in the word variable.
    int actualWordLength = 0;
    int i = 0;
    while (word[i] != '\0') { // We loop loop through the char array (string) until the current character is equals to the null terminator.
        actualWordLength++;
        i++;
    }
    char actualWord[actualWordLength]; // Creates a string of the length of the input minus the null terminator.
    for (int i = 0; i < actualWordLength; i++) { // We copy the contents of the input string into the new char array, excluding the null terminator.
        actualWord[i] = word[i];
    }
    int isPalindrome = 1; // Initiliaze to 1 to assume the word is palindrome
    // as one character uses one byte then sizeof will return the number of characters.
    for (int i = 0; i <= sizeof(actualWord) / 2 || isPalindrome == 0; i++) { // We loop from 0 to the half of the char array. Exits the loop once the word has been determined to not be palindrome or all the possible values of i has been exhausted.
        if (word[i] != word[sizeof(actualWord) - 1 - i]) { // We compare characters at index 0 and n (last character) and if they are not equal then we set the variable to 0 (0 = not palindrome). Then repeat but for index 1 and n - 1, and then 2 and n - 2, and so on. 
            isPalindrome = 0;
        }
    }
    isPalindrome == 1? printf("This word is palindrome"): printf("This word is not palindrome"); // if variable is equals to 1, then it is palindrome, message palindrome displayed. else means the word is not palindrome, message for non polindrome is displayed. 
}