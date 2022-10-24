#include <stdio.h>
#include <stdlib.h>

void main() {
    int *newPtr;
    newPtr = (int*) malloc(1000*sizeof(int));

    printf("%i\n", sizeof(*newPtr));


    int num = 5;
    newPtr = &num;

    printf("%p %i\n", &num, *newPtr);
    printf("%i", sizeof(*newPtr));
}