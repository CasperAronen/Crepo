#include <stdio.h>

int main() {
    float Bprice, Tprice, YourMoney;
    int choice;

    printf("Enter the price of bus ticket: ");
    scanf("%f", &Bprice);

    printf("Enter the price of taxi: ");
    scanf("%f", &Tprice);

    printf("Enter how much money you have: ");
    scanf("%f", &YourMoney);

    while (YourMoney >= Bprice || YourMoney >= Tprice) {
        printf("Do you want to take\n");
        printf("1) Bus\n", Bprice);
        printf("2) Taxi\n", Tprice);
        printf("Enter Your selection: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (YourMoney >= Bprice) {
                YourMoney -= Bprice;
                printf("You chose bus\n");
                printf("You have $%.2f Euro Left \n", YourMoney);
            } else {
                printf("You dont have enough money for the bus\n");
            }
        }
        else if (choice == 2) {
            if (YourMoney >= Tprice) {
                YourMoney -= Tprice;
                printf("You chose taxi\n");
                printf("You have %.2f Euro Left\n ", YourMoney);
            } else {
                printf("You dont have enough money for the taxi\n");
            }
        } else {
            printf("Invalid Choice Please Press 1 or 2\n");
        }
    }
    printf("You need to walk. Bye\n");

    return 0;
}

