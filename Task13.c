#include <stdio.h>
#include <stdlib.h>

int main() {
    char Fname[256];
    FILE *file;
    int Number;
    int Count = 0;
    int low, high;

    printf("Enter your file's name: ");
    scanf("%255s", Fname);

    file = fopen(Fname, "r");
    if (file == NULL) {
        fprintf(stderr, "Can't open file %s\n", Fname);
        return EXIT_FAILURE;

    }
    while (fscanf(file, "%d", &Number) == 1) {
        if (Count == 0) {
            low = Number;
            high = Number;
        }
        else {
            if (Number < low)
                low= Number;
            if (Number > high)
                high= Number;
        }
        Count++;
    }
    if (Count > 0) {
        printf("COunt %d\n", Count);
        printf("Highest number: %d\n", high);
        printf("Lowest number: %d\n", low);
    }
    else {
        printf("No numbers found in file\n");
    }
    fclose(file);

    return EXIT_SUCCESS;
}