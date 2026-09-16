#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countWords(const char* str, const char *word) {
    int count = 0;
    int wlen = strlen(word);

    const char *p = str;

    while ((p = strstr(p, word)) != NULL) {
        int start = (p == str || p[-1] == ' ');

        int end = (p[wlen] == '\0'  || p[wlen] == ' ');
        if (start && end) {
            count++;
        }
        p += wlen;
    }
    return count;
}

int main () {
    char S1[100];
    char S2[100];

    while (1) {
        printf("Please enter string: ");
        fgets(S1, sizeof(S1), stdin);
        S1[strcspn(S1, "\n")] = '\0';

        printf("Please enter a word: ");
        fgets(S2, sizeof(S2), stdin);
        S2[strcspn(S2, "\n")] = '\0';

        if (strcmp(S1, "stop") == 0 || strcmp(S2, "stop") == 0) {
            printf("Both strings had stop ending program.\n");
            break;
        }
        int result = countWords(S1, S2);

        printf("The ammount of times word %s happens is %d \n", S2, result);
    }
}