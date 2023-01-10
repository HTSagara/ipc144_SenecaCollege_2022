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
    float priceSmall, priceMedium, priceLarge;
    int numShirtsPat, numShirtsTom, numShirtsSal;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &priceSmall);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &priceMedium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &priceLarge);

    float small = priceSmall + 0.000001;
    float medium = priceMedium + 0.000001;
    float large = priceLarge + 0.000001;

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", small);
    printf("MEDIUM : $%.2f\n", medium);
    printf("LARGE  : $%.2f\n", large);

    printf("\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numShirtsPat);
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numShirtsTom);
    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numShirtsSal);

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total");
    printf("\n-------- ---- ----- --- --------- --------- ---------\n");

    printf("Patty    %c    %.2f   %d  %.4f   %.4f  %.4f", patSize, small, numShirtsPat, (small * numShirtsPat), (small * numShirtsPat * TAX), ((small * (numShirtsPat) + (small * numShirtsPat * TAX))));

    return 0;
}