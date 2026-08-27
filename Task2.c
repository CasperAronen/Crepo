#include <stdio.h>
int main() {
    float Income[12];
    float Tax[12];

    float TaxRate;
    float Limit;
    float HighTaxRate;
    float Total = 0.0f;

    printf("Enter tax rate: ");
    scanf("%f", &TaxRate);
    printf("Enter Income limit: ");
    scanf("%f", &Limit);
    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &HighTaxRate);

    for (int i=0; i < 12; i++) {
        printf("Enter Income for month %d: ", i+1);
        scanf("%f", &Income[i]);
    }

    for (int i = 0; i < 12; i++) {
        float LastIncome = Total;
        Total += Income [i];

        if (Total <= Limit) {
            Tax[i] = Income[i] * TaxRate/100.0f;
        }
        else if (LastIncome>Limit) {
            Tax[i] = Income[i] * HighTaxRate/100.0f;
        }
        else {
            float Low = Limit-LastIncome;
            float High = Income[i] - Low;

            Tax[i] = Low*TaxRate/100.0f + High*HighTaxRate/100.0f;
        }
    }
    printf("\nmonth income tax\n");
    for (int i = 0; i < 12; i++) {
        printf("%5d %8.2f %8.2f\n",  i+1, Income[i], Tax[i]);
    }
    return 0;
}