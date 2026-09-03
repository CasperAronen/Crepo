#include <stdio.h>

int readInteger() {
    int number;

    while (scanf("%d" , &number) != 1) {
        printf("invalid number \n");
        printf("Enter positive number. Enter negative number to stop:");
        while (getchar() != '\n');
    }
    return number;
}


int main () {
    int number;
    int count = 0;
    int sum = 0;

    while (1) {
        printf("Enter positive number. Enter negative number to stop: ");
        number = readInteger();

        if (number < 0) {

            break;
        }
        sum += number;
        count++;
    }
    if (count > 0) {
        double average = (double)sum / count;
        printf("You entered %d numbers. The average is %.3f\n", count, average);
    } else {
        printf("You entered nothing.\n");
    }
    return 0;
}

