#include <stdio.h>

#define MAX_ITEMS 40

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main (void) {
    menu_item items[MAX_ITEMS];
    char filename[256];
    char line[256];
    int count = 0;
    FILE *f;

    printf("Enter filename");
    scanf("%255s", filename);

    f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Couldn't open file: %s\n", filename);
        return 1;
    }

    while (count < MAX_ITEMS && fgets(line, sizeof(line), f) != NULL) {
        if (sscanf(line, "%49[^;];%lf", item[count].name, &items[count].price) == 2) {
            count++;
        }
    }
    fclose(f);

    for (int i = 0; i < count; i++) {
        printf("%8.2f %s\n", items[i].price ,items[i].name);
    }
    return 0;
}
