#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printNumbers(const int*array, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int numbers[15];

    srand(time(NULL));

    for (int i = 0; i < 15; i++) {
        numbers[i] = rand() % 100;
    }
    printNumbers(numbers, 15);
    return 0;
}