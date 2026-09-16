#include <stdio.h>
#include <string.h>

int main () {
    char str[100];
    while (1) {
        printf("Enter a string (Enter stop to end the program): ");
        fgets(str,100,stdin);
        str[strlen(str)-1] = '\0';

        if (strlen(str) == 0) {
            printf("You didnt input anything.\n");
            continue;
        }
        if (strcmp(str, "stop") == 0) {
            break;
        }
        printf("Lenght of entered string is %lu \n", strlen(str));
    }
}