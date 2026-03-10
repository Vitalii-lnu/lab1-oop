#include "Price.h"
#include <stdio.h>
#include <iostream>


Price addPrices(Price price1, Price price2) {
    Price result;
    result.kop = price1.kop + price2.kop;
    result.grn = price1.grn + price2.grn + (result.kop / 100);
    result.kop %= 100;
    return result;
}

Price multiplyPrice(Price price, int quantity) {
    Price result;
    int totalKop = (price.grn * 100 + price.kop) * quantity;
    result.grn = totalKop / 100;
    result.kop = totalKop % 100;
    return result;
}

Price roundPrice(Price price) {
    short lastDigit = price.kop % 10;

    if (lastDigit < 5) {
        price.kop -= lastDigit;

    }
    else {
        price.kop += (10 - lastDigit);
    }

    if (price.kop >= 100) {
        price.grn += price.kop / 100;
        price.kop = price.kop % 100;
    }
    return price;
}

Price calculateTotalFromFile(const char* filename) {
    FILE* file = nullptr;

    file = fopen(filename, "r");

    Price total = { 0, 0 };

    if (file == nullptr) {
        printf("Could not open file %s\n", filename);
        return total;
    }

    int grn, kop, quantity;

    while (fscanf(file, "%d %d %d", &grn, &kop, &quantity) != EOF) {
        Price item = { grn, (short int)kop };
        Price subTotal = multiplyPrice(item, quantity);
        total = addPrices(total, subTotal);
    }

    fclose(file);
    return total;
}

void printPrice(const char* label, Price price) {
    printf("%s: %d grn %02d kop\n", label, price.grn, price.kop);
}