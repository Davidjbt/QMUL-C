#include <stdio.h>
#include <string.h>
// struct that will represent a bank account, with account number, name, and balance fields.
typedef struct BankAccount {
    int account; 
    char name[40];
    double balance;
} BankAccount;
// function prototypes
void addBankAccounts(FILE* fptr);
void printBankAccounts(FILE* fptr);
 // main function, the program will start from this function.
void main() {
    FILE* fptr;
    char filename[20]; // char array that can store 20.
    printf("Enter filename write to: ");
    scanf("%s", filename); // Reads input and stores it into the filename variable.

    if ((fptr = fopen(filename, "w")) == NULL) { // if fopen does not manages to open a file, with the name stored in the filename variable, for read then proceed. 
        printf("\nFile could not be opened, exiting program.\n");
    } else { // else the filen was open for write.
        addBankAccounts(fptr); // call to function
        fclose(fptr); // close file
        fptr = fopen(filename, "r"); // open same file but for read.
        printBankAccounts(fptr); // call to function.
    }
}
// function that will add a bank account into the file pointed by the file pointer argument.
void addBankAccounts(FILE* fptr) {
    BankAccount bankAccount;
    size_t len;

    printf("\nEnter the account of the customer or -1 to finish:");
    scanf("%i", &bankAccount.account); // collect input and store it into the account field of the bank account 
    while (bankAccount.account != -1) { // if the value of the field is not -1 then preceed.
        printf("\nEnter the name of the customer:");
        while(getchar() != '\n') continue; // if the while the input is not a new line then continue.
        fgets(bankAccount.name, 40, stdin); // gets input and stores into the name field of bank account.
        len = strlen(bankAccount.name); // gets the len of the bank account name without the null terminator and stores into the variable.
        if(bankAccount.name[len-1] == '\n' ) bankAccount.name[len-1] = '\0'; // if the last character is a new line then substutite it with the null terminator.

        printf("\nEnter the balance of the customer:");
        scanf("%lf", &bankAccount.balance); // gets input and stores into the bank account balance.

        fwrite(&bankAccount, sizeof(bankAccount), 1, fptr ); // writes the contents of the bank account into the file.

        printf("\nEnter the account of the customer or -1 to finish:");
        scanf("%i", &bankAccount.account);
    }    
}
// function that will print the contents of the file pointed by the file pointer.
void printBankAccounts(FILE* fptr) {
    BankAccount bankAccount;

    printf("\n%-10s%-13s%s\n", "Account", "Name", "Balance");
    fread(&bankAccount, sizeof(bankAccount), 1, fptr); // reads a bank account variable and adds the contents of the input from the file into the memory allocated pointed by the bank account pointer.
    while (!feof (fptr)) {  // while end of file is not reached then procceed.
        printf("\n%-10d%-13s%7.2f", bankAccount.account, bankAccount.name, bankAccount.balance); // print the contents of bank account.
        fread(&bankAccount, sizeof(bankAccount), 1, fptr);
    }
    fclose(fptr); // close the file.
}