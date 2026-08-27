#include <stdio.h>

int main() {
    int NumberStudents;

    printf("How many students: ");
    scanf("%d",&NumberStudents);

    int Grades[NumberStudents];

    for (int i = 0; i < NumberStudents; i++) {
        Grades[i] = -1;
    }
    int StudentId;

    while (1) {
        printf("Enter student number (1- %d) or 0 to stop: ", NumberStudents);
        scanf("%d",&StudentId);

        if (StudentId == 0) {
            break;
        }
        if (StudentId < 1 || StudentId > NumberStudents) {
            printf("invalid student number\n");
            continue;
        }
        int Grade;

        while (1) {
            printf("Enter grade(0-5) for student %d or -1 to cancel: ", StudentId);
            scanf("%d",&Grade);

            if (Grade >= -1 && Grade <= 5) {
                break;
            }
            printf("Invalid grade\n");
        }
        Grades[StudentId - 1] = Grade;
    }

    printf("\nStudent Grade\n");

    for (int i = 0; i < NumberStudents; i++) {
        printf("%-8d", i + 1);

        if (Grades[i] == -1) {
            printf("N/A\n");
        }
        else {
            printf("%d\n", Grades[i]);
        }
    }
    return 0;
}