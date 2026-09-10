#include <stdio.h>
#include <stdbool.h>


bool readPositive(int *value) {
    int number;
    printf("Enter a positive number: ");
    if (scanf("%d",&number) != 1) {
        while (getchar() != '\n');
        return false;
    }
    if (number <= 0) {
        return false;
    }
    *value = number;
    return true;
}

int main() {
    int money=0;
    int guess;
    int wrongGuess = 0;

    while (wrongGuess < 3) {
        printf("Guess how much money i have\n");

        if (readPositive(&guess)) {
            money = guess * 2 + 20;
            printf("You entered %d euros.\n", guess);
            printf(" I have %d euros try again.\n", money);
        }
        else {
            printf("Please enter positive number \n");
            wrongGuess++;
        }
    }
    printf("You've guessed enough see ya");
}