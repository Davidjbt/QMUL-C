#include <stdio.h>

// Calculates the average and displays it.
void average(double stdg_grades[3][4], int student) {
    double average = 0;
    int entries = 0;
    for (int i = 0; i < 4; i++) { // Loops from 0 to 3.
        average += stdg_grades[student][i]; // Adds the current mark of the current student to a variable.
        entries++; // stores the number of marks.
    }

    average /= entries; // Divide the the sum of the marks by the number of entries. average obtained.

    printf("\nStudent average = %.2f\n", average); // Displays it.
}
// main function, the program will start from this function.
void main() {
    double std_grades[3][4] = { // 2d array containing the students and their marks.
        {7.7, 6.8, 8.6, 7.3},
        {9.6, 8.7, 8.9, 7.8},
        {7.0, 9.0, 8.6, 8.1}
    };

    for (int i = 0; i < 3; ++i) { // Loops through the rows, which represents the students.
        printf("\nGrades for student %i are: ", i); 
        for (int j = 0; j < 4; j++) { // Displays the contents of the rows (columns), which represents the students' marks.
            printf("%.1f ", std_grades[i][j]);
        }
        average(std_grades, i); // call method.
    }
}