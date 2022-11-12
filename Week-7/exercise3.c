#include <stdio.h>
#include <string.h>

typedef struct BankAccount {
    int account; 
    char name[40];
    double balance;
} BankAccount;

void addBankAccounts(FILE* fptr);
void printBankAccounts(FILE* fptr);

void main() {
    FILE* fptr;
    char filename[20];
    printf("Enter filename write to: ");
    scanf("%s", filename);

    if ((fptr = fopen(filename, "w")) == NULL) {
        printf("\nFile could not be opened, exiting program.\n");
    } else {
        addBankAccounts(fptr);
        fclose(fptr);
        fptr = fopen(filename, "r");
        printBankAccounts(fptr);
    }
}

void addBankAccounts(FILE* fptr) {
    BankAccount bankAccount;
    size_t len;

    printf("\nEnter the account of the customer or -1 to finish:");
    scanf("%i", &bankAccount.account);
    while (bankAccount.account != -1) {
        printf("\nEnter the name of the customer:");
        while(getchar() != '\n') continue;
        fgets(bankAccount.name, 40, stdin);
        len = strlen(bankAccount.name);
        if(bankAccount.name[len-1] == '\n' ) bankAccount.name[len-1] = '\0';

        printf("\nEnter the balance of the customer:");
        scanf("%lf", &bankAccount.balance);

        fwrite(&bankAccount, sizeof(bankAccount), 1, fptr );

        printf("\nEnter the account of the customer or -1 to finish:");
        scanf("%i", &bankAccount.account);
    }    
}

void printBankAccounts(FILE* fptr) {
    BankAccount bankAccount;

    printf("\n%-10s%-13s%s\n", "Account", "Name", "Balance");
    fread(&bankAccount, sizeof(bankAccount), 1, fptr);
    while (!feof (fptr)) {
        printf("\n%-10d%-13s%7.2f", bankAccount.account, bankAccount.name, bankAccount.balance);
        fread(&bankAccount, sizeof(bankAccount), 1, fptr);
    }
    fclose(fptr);
}