/*
*****************************************************************************
                          Workshop - #2 (P1)
Full Name  : Henrique Toshio Sagra
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
    const char patSize = 'S';
    float priceSmall, priceMedium, priceLarge, small, medium, large, sub_total, total, taxes;
    int numShirts, num_Shirts;

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
    scanf("%d", &numShirts);

    num_Shirts = numShirts;
 
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", num_Shirts);
    sub_total = small * num_Shirts;
    printf("Sub-total: $%.4f\n", sub_total);
    taxes = sub_total * TAX + 0.0016;
    printf("Taxes    : $ %.4f\n", taxes);
    total = sub_total + taxes;
    printf("Total    : $%.4f\n", total);


    return 0;
}