#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int menu() {
    printf("\n");
    printf("1. Roll D6\n");
    printf("2. Roll D10\n");
    printf("3. Quit\n");
    printf("Select: ");
}

int Rchoice() {
    int choice;

    while (scanf("%d", &choice) != 1) {
        printf("Invalid input enter(1-3)");

        while (getchar() != '\n');
    }
    return choice;
}

int rollD6() {
    return rand() % 6 + 1;
}

int rollD10 (){
    return rand() % 10 + 1;
}

int main(void){
    int choice;

    srand(time(NULL));

    do {
        menu();
        choice = Rchoice();

        switch (choice) {
            case 1:
                printf("D6 roll %d\n" , rollD6());
                break;
            case 2:
                printf("D10 roll %d\n" , rollD10());
                break;
            case 3:
                printf("bye\n");
                break;
            default:
                printf("Invalid input enter(1-3)");
        }
    }while (choice != 3);
    return 0;
}