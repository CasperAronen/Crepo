#include <stdio.h>

int readRange(int low, int high) {
    int number;

    while (1) {
        printf("Roll a die and enter the result: ");

        if (scanf("%d", &number) != 1) {
            printf("Invalid input");
            while (getchar() != '\n');

        }
        else if (number < low || number > high) {
            printf("Invalid input");
            printf("number must be between %d and %d\n", low, high);
        }
        else {
            return number;
        }
    }
}

int main() {
    int uRoll;
    int cRoll;

    for (int round = 1; round <= 3; round++) {
        printf("Round %d\n ", round);

        uRoll = readRange(1,6);

        if (uRoll == 6) {
            cRoll = 6;
            printf("You roled %d I rolled %d. It's a tie\n ",uRoll,cRoll);
        }
        else {
            cRoll = uRoll+1;
            printf("You roled %d I rolled %d. I win\n ",uRoll,cRoll);
        }
    }
    printf("Better luck next time");
    return 0;

}