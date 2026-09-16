#include <stdio.h>
#include <string.h>
//#include <ctype.h>

int replaceChar(char *str, char replace, char new) {
    int strLen = strlen(str);
    int mod = 0;
    for (int i = 0; i < strLen; i++) {

        if (str[i] == replace) {
            str[i] = new;
            mod++;
        }
    }
    return mod;
}
int main () {
    char InputChar[100];
    char first, second;
    printf("Enter a string: ");
    fgets(InputChar,100,stdin);
    printf("Enter 2 characters for each instance of the first one will be replace by the second: ");
    scanf("%c %c",&first, &second);

    int modded =replaceChar(InputChar, first, second);

    if (modded == 0) {
        printf("The string was not modified.");
    }else {
        printf("\n Replaced string: %s",InputChar);
        printf("The amount of changes %d.", modded);
    }
}


//Added tolower for input realised not necessary
//str[i] =  tolower(str[i]);
//first = tolower(first);
//second = tolower(second);
