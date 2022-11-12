#include <stdio.h>

void main() {
    int distance;
    char* city;
    int flag = scanf("%i %s", &distance, city);
    int firstEntry = 1;

    while (flag == 2) {
        if (distance > 100) {
            firstEntry == 1? printf(""): printf("\n");
            firstEntry = 0;
            printf("%i %s", distance, city);
        }

        flag = scanf("%i %s", &distance, city);
    }
}