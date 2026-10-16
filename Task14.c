#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 100
#define MAX_LEN 82

int main()
{
    char line[MAX_LINE][MAX_LEN];
    char filename[256];
    int count = 0;
    FILE *f;

    printf("Enter filename: ");
    scanf("%255s", filename);

    f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Couldn't open file: %s\n", filename);
        return 1;
    }
    while (count < MAX_LINE && fgets(line[count], sizeof line[count], f) != NULL) {
        count++;
    }
    fclose(f);

    for (int i = 0; i < count; i++) {
        for (int j = 0; line[i][j] != '\0'; j++) {
            line[i][j] = toupper((unsigned)line[i][j]);
        }
    }

    f = fopen(filename, "w");
    if (f == NULL) {
        fprintf(stderr, "Couldn't open file %s\n", filename);
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fputs(line[i], f);
    }
    fclose(f);

    return 0;
}