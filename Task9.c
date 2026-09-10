#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findFirst(const unsigned int *array, unsigned int num) {
    int index = 0;
    while (array[index] != 0) {
        if (array[index] == num) {
            return index;
        }
        index++;
    }
    return -1;
}

int main() {
    unsigned int numbers[20];

    srand(time(NULL));

    for (int i = 0; i < 19; i++) {
        numbers[i] = rand() % 20+1;
    }
    numbers[19] = 0;

    printf("Array:\n");

    for (int i = 0; i < 19; i++) {
        printf("%u \n ", numbers[i]);
    }

    unsigned int search;

    while (1) {
        printf("Enter a number to search for (enter 0 to stop): ");
        scanf("%u", &search);

        if (search == 0) {
            printf("Lets stop time");
            break;
        }
        int index = findFirst(numbers, search);

        if (index == -1) {
            printf("Not found\n");
        }
        else {
            printf("Found at index %d\n", index);
        }
    }
    return 0;
}