#include "Price.h"
#include <stdio.h>

void addPrices(Price price1, Price price2, Price* result) {
    if (!result) return;
    int totalKop = price1.kop + price2.kop;
    result->grn = price1.grn + price2.grn + (totalKop / 100);
    result->kop = totalKop % 100;
}

void multiplyPrice(Price price, int quantity, Price* result) {
    if (!result) return;
    int totalKop = (price.grn * 100 + price.kop) * quantity;
    result->grn = totalKop / 100;
    result->kop = totalKop % 100;
}

void roundPrice(Price* price) {
    if (!price) return;
    short lastDigit = price->kop % 10;

    if (lastDigit < 5) {
        price->kop -= lastDigit;
    } else {
        price->kop += (10 - lastDigit);
    }

    if (price->kop >= 100) {
        price->grn += price->kop / 100;
        price->kop %= 100;
    }
}

void calculateTotalFromFile(const char* filename, Price* total) {
    if (!total) return;
    total->grn = 0;
    total->kop = 0;

    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        printf("Could not open file %s\n", filename);
        return;
    }

    int grn, kop, quantity;
    while (fscanf(file, "%d %d %d", &grn, &kop, &quantity) != EOF) {
        Price item = { grn, (short int)kop };
        Price subTotal;
        multiplyPrice(item, quantity, &subTotal);
        addPrices(*total, subTotal, total);
    }

    fclose(file);
}

void printPrice(const char* label, Price price) {
    printf("%s: %d grn %02d kop\n", label, price.grn, price.kop);
}