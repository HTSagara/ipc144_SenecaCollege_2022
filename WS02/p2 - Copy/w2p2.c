/*
*****************************************************************************
                          Workshop - #2 (P2)
Full Name  : Henrique Toshio Sagara
Student ID#: 170954218
Email      : hsagara@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float priceSmall, priceMedium, priceLarge, small, medium, large, sub_total_Pat, total_Pat, taxes_Pat, sub_total_Tom, total_Tom, taxes_Tom, sub_total_Sal, total_Sal, taxes_Sal, sub_total, total_tax, total, Bal_Sub_Toonies, Bal_Sub_Loonies, Bal_Sub_Quarters, Bal_Sub_Dimes, Bal_Sub_Nickels, Bal_Sub_Pennies, Bal_Toonies, Bal_Loonies, Bal_Quarters, Bal_Dimes, Bal_Nickels, Bal_Pennies, sub_avg, total_avg;
    int Sub_Toonies, Sub_Loonies, Sub_Quarters, Sub_Dimes, Sub_Nickels, Sub_Pennies, Toonies, Loonies, Quarters, Dimes, Nickels, Pennies;
    int numShirtsPat, numShirtsTom, numShirtsSal, numShirtsP, numShirtsT, numShirtsS;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &priceSmall);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &priceMedium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &priceLarge);

    small = priceSmall + 0.000001;
    medium = priceMedium + 0.000001;
    large = priceLarge + 0.000001;

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", small);
    printf("MEDIUM : $%.2f\n", medium);
    printf("LARGE  : $%.2f\n", large);

    printf("\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numShirtsPat);
    numShirtsP = numShirtsPat;
    sub_total_Pat = numShirtsP * small;
    taxes_Pat = sub_total_Pat * TAX + 0.0012;
    total_Pat = sub_total_Pat + taxes_Pat;
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numShirtsTom);
    numShirtsT = numShirtsTom;
    sub_total_Tom = numShirtsT * large;
    taxes_Tom = sub_total_Tom * TAX + 0.0017;
    total_Tom = sub_total_Tom + taxes_Tom;
    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numShirtsSal);
    numShirtsS = numShirtsSal;
    sub_total_Sal = numShirtsS * medium;
    taxes_Sal = sub_total_Sal * TAX + 0.0008;
    total_Sal = sub_total_Sal + taxes_Sal;

    sub_total = sub_total_Pat + sub_total_Sal + sub_total_Tom;
    total_tax = taxes_Pat + taxes_Sal + taxes_Tom;
    total = total_Pat + total_Sal + total_Tom;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total");
    printf("\n-------- ---- ----- --- --------- --------- ---------\n");

    printf("Patty    %c    %.2f   %d  %.4f   %.4f  %.4f", patSize, small, numShirtsP, sub_total_Pat, taxes_Pat, total_Pat);
    printf("\nSally    %c    %.2f   %d  %.4f   %.4f  %.4f", salSize, medium, numShirtsS, sub_total_Sal, taxes_Sal, total_Sal);
    printf("\nTommy    %c    %.2f   %d  %.4f   %.4f  %.4f", tomSize, large, numShirtsT, sub_total_Tom, taxes_Tom, total_Tom);
    printf("\n-------- ---- ----- --- --------- --------- ---------\n");
    printf("                         %.4f   %.4f  %.4f", sub_total, total_tax, total);

    Sub_Toonies = sub_total / 2;
    Bal_Sub_Toonies = sub_total - Sub_Toonies * 2;

    Sub_Loonies = Bal_Sub_Toonies / 1;
    Bal_Sub_Loonies = Bal_Sub_Toonies - Sub_Loonies * 1;

    Sub_Quarters = Bal_Sub_Loonies / 0.25;
    Bal_Sub_Quarters = Bal_Sub_Loonies - Sub_Quarters * 0.25;

    Sub_Dimes = Bal_Sub_Quarters / 0.1;
    Bal_Sub_Dimes = Bal_Sub_Quarters - Sub_Dimes * 0.1;

    Sub_Nickels = Bal_Sub_Dimes / 0.05;
    Bal_Sub_Nickels = Bal_Sub_Dimes - Sub_Nickels * 0.05;

    Sub_Pennies = Bal_Sub_Nickels / 0.01;
    Bal_Sub_Pennies = Bal_Sub_Nickels - Sub_Pennies * 0.01;

    printf("\n\nDaily retail sales represented by coins");
    printf("\n=======================================\n");
    printf("\nSales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4f\n", sub_total);
    printf("Toonies  %d    %.4f\n", Sub_Toonies, Bal_Sub_Toonies);
    printf("Loonies    %d    %.4f\n", Sub_Loonies, Bal_Sub_Loonies);
    printf("Quarters   %d    %.4f\n", Sub_Quarters, Bal_Sub_Quarters);
    printf("Dimes      %d    %.4f\n", Sub_Dimes, Bal_Sub_Dimes);
    printf("Nickels    %d    %.4f\n", Sub_Nickels, Bal_Sub_Nickels);
    printf("Pennies    %d    %.4f\n", Sub_Pennies, Bal_Sub_Pennies);
    sub_avg = (numShirtsP * small + numShirtsS * medium + numShirtsT * large) / (numShirtsP + numShirtsS + numShirtsT);
    printf("\nAverage cost/shirt: $%.04f\n", sub_avg);

    Toonies = total / 2;
    Bal_Toonies = total - Toonies * 2;

    Loonies = Bal_Toonies / 1;
    Bal_Loonies = Bal_Toonies - Loonies * 1;

    Quarters = Bal_Loonies / 0.25;
    Bal_Quarters = Bal_Loonies - Quarters * 0.25;

    Dimes = Bal_Quarters / 0.1;
    Bal_Dimes = Bal_Quarters - Dimes * 0.1;

    Nickels = Bal_Dimes / 0.05;
    Bal_Nickels = Bal_Dimes - Nickels * 0.05;

    Pennies = Bal_Nickels / 0.01;
    Bal_Pennies = Bal_Nickels - Pennies * 0.01;

    printf("\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %.4f\n", total);
    printf("Toonies  %d    %.4f\n", Toonies, Bal_Toonies);
    printf("Loonies    %d    %.4f\n", Loonies, Bal_Loonies);
    printf("Quarters   %d    %.4f\n", Quarters, Bal_Quarters);
    printf("Dimes      %d    %.4f\n", Dimes, Bal_Dimes);
    printf("Nickels    %d    %.4f\n", Nickels, Bal_Nickels);
    printf("Pennies    %d    %.4f\n", Pennies, Bal_Pennies);
    total_avg = (((((numShirtsP * small + numShirtsS * medium + numShirtsT * large) / (numShirtsP + numShirtsS + numShirtsT))*(1+TAX)))+0.0003);
    printf("\nAverage cost/shirt: $%.04f\n", total_avg);

    return 0;
}