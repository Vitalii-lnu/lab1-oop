#pragma once

struct Price {
    int grn = 0;
    short int kop = 0;
};

void addPrices(Price price1, Price price2, Price* result);
void multiplyPrice(Price price, int quantity, Price* result);
void roundPrice(Price* price);
void printPrice(const char* label, Price price);

void calculateTotalFromFile(const char* filename, Price* total);