#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char line[100];
    int n;

    srand((unsigned)time(NULL));

    while (1) {
        printf("Enter a number(1-15) (negative to stop): ");

        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }
        if (sscanf(line, "%d", &n) != 1) {
            printf("Not a numeber\n");
            continue;
        }
        if (n<0) {
            break;
        }
        if (n > 15) {
            printf("Number must be between 0 and 15\n");
            continue;
        }
        unsigned int r = (unsigned int) rand();
        printf("Random number: 0x%x\n", r);

        unsigned int result = (r>>n) & 0x3F;
        printf("Result: 0x%x\n", result);
    }
    return 0;
}