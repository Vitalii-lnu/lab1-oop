#include <stdio.h>
#include "Price.h"

int main() {
    const char* filename = "input.txt";

    Price totalSum;
    calculateTotalFromFile(filename, &totalSum);

    Price roundedSum = totalSum; 
    roundPrice(&roundedSum);

    printf("--- РЕЗУЛЬТАТ ОБЧИСЛЕНЬ ---\n");
    printPrice("Загальна сума       ", totalSum);
    printPrice("Сума до оплати, хліб", roundedSum);
    printf("---------------------------\n");

    return 0;
}