#pragma once

struct Price {
    int grn = 0;
    short int kop = 0;
};

// Functions
Price addPrices(Price price1, Price price2);
Price multiplyPrice(Price price, int quantity);
Price roundPrice(Price price);
void printPrice(const char* label, Price price);

Price calculateTotalFromFile(const char* filename);

