#include <stdio.h>

void main() {
    char word[30];
    printf("Enter word: ");
    scanf("%30s", word);
    int actualWordLength = 0;
    int i = 0;
    while (word[i] != '\0') {
        actualWordLength++;
        i++;
    }
    char actualWord[actualWordLength];
    for (int i = 0; i < actualWordLength; i++) {
        actualWord[i] = word[i];
    }
    int isPalindrome = 1;
    // as one character uses one byte then sizeof will return the number of characters
    for (int i = 0; i <= sizeof(actualWord) / 2; i++) {
        if (word[i] != word[sizeof(actualWord) - 1 - i]) {
            isPalindrome = 0;
        }
    }
    isPalindrome == 1? printf("This word is palindrome"): printf("This word is not palindrome");
}