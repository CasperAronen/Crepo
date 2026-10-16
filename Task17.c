#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define WORD_SIZE 32
#define PW_SIZE   32

static char randomChar() {
    return (char)('!' + rand() % ('~' - '!' + 1));
}

bool PasswordGen(char *password, int size, const char *word) {
    int len = (int)strlen(word);
    int pwLen = len * 2 +1;

    if (pwLen + 1 > size) {
        return false;
    }

    int pos = 0;
    for (int i=0; i < len; i++) {
        password[pos++] = randomChar();
        password[pos++] = word[i];
    }
    password[pos++] = randomChar();
    password[pos] = '\0';

    return true;
}

int main() {
    char word[WORD_SIZE];
    char password[PW_SIZE];

    srand((unsigned)time(NULL));

    while (1) {
        printf("Enter a word: ");
        if (scanf("%31s", word)!= 1 ) {
            break;
        }
        if (strcmp(word, "stop") == 0) {
            break;
        }
        if (PasswordGen(password, WORD_SIZE, word)) {
            printf("Password generated: %s\n", password);
        }
        else {
            printf("Password not generated\n");
        }
    }
    return 0;
}