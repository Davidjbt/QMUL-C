/* This program reads information from a character stream data file */
/* (e.g. Files_ex3.c) */
#include <stdio.h>
#include <string.h>
int main() {
    int account;
    char name[40];
    double balance;
    FILE *fptr;
    if ( (fptr = fopen("clients.dat", "r")) == NULL)
        printf("\nFile could not be opened, exiting program.\n");
    else {
        printf("\n%-10s%-13s%s\n", "Account", "Name", "Balance");
        fscanf(fptr, "%d%s%lf", &account, name, &balance);
        while (!feof (fptr)) {
        printf("\n%-10d%-13s%7.2f", account, name, balance);
        fscanf(fptr, "%d%s%lf", &account, name, &balance);
        }
        fclose(fptr);
    }
    return 0;
}