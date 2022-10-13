#include <stdio.h>

void average(double stdg_grades[3][4], int student) {
    double average = 0;
    int entries = 0;
    for (int i = 0; i < 4; i++) {
        average += stdg_grades[student][i];
        // printf("%f", stdg_grades[student][i]);
        entries++;
    }

    average /= entries;

    printf("\nStudent average = %.2f\n", average);
}

void main() {
    double std_grades[3][4] = {
        {7.7, 6.8, 8.6, 7.3},
        {9.6, 8.7, 8.9, 7.8},
        {7.0, 9.0, 8.6, 8.1}
    };

    for (int i = 0; i < 3; ++i) {
        printf("\nGrades for student %i are: ", i);
        for (int j = 0; j < 4; j++) {
            printf("%.1f ", std_grades[i][j]);
        }
        average(std_grades, i);
    }

}