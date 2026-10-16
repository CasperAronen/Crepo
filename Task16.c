
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

typedef struct node {
    int number;
    struct node *next;
} nnode;

int main(void) {
    nnode *head = NULL;
    nnode *tail = NULL;
    char input[100];

    while (1) {
        printf("Enter a number (or type end to stop): ");

        if (scanf("%99s", input) != 1) {
            break;
        }

        if (strcmp(input, "end") == 0) {
            break;
        }

        char *endptr;
        errno = 0;
        long value = strtol(input, &endptr, 10);

        if (endptr == input || *endptr != '\0' ||
            errno == ERANGE || value < INT_MIN ||
            value > INT_MAX) {
            printf("Invalid input: %s\n", input);
            continue;
            }

        nnode *node = malloc(sizeof *node);

        if (node == NULL) {
            fprintf(stderr, "Out of memory\n");
            break;
        }

        node->number = (int)value;
        node->next = NULL;

        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }

        tail = node;
    }

    printf("Entered numbers: ");

    for (nnode *p = head; p != NULL; p = p->next) {
        printf("%d ", p->number);
    }

    printf("\n");

    while (head != NULL) {
        nnode *next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
