#include <stdio.h>

#define SIZE 30
#define MARKS_SIZE 3
#define LIST_SIZE 5 

struct student {
    char name[SIZE];
    int number;
    double marks[MARKS_SIZE];
};

void displayStudentDetails(struct student *student) {

    printf("Name: %s", student->name);

    double total = 0;
    for (int i = 0; i < MARKS_SIZE; i++) { 
        total += student->marks[i];
    }

    double average = total /  MARKS_SIZE;

    printf("\nAverage: %.2f\n\n", average);

}

void main() {
    struct student students[LIST_SIZE] = {
        {"David", 1, {8.7, 9.2, 7.2}},
        {"Kevin", 2, {3.5, 5.6, 4.5}},
        {"Luis", 3, {9.5, 3.5, 8.8}},
        {"Mario", 4, {5.6, 9.2, 7.5}},
        {"John", 5, {7.8, 9.0,6.7}}
    };

    for (int i = 0; i < LIST_SIZE; i++) {
        displayStudentDetails(&students[i]);
    }
}