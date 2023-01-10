/*
*****************************************************************************
                          Workshop - #6 (P1)
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
#define MAX_ITEMS 10
#define MIN_COST 100.00

int main(void)
{
    const float minIncome = 500;
    const float maxIncome = 400000;
    float netIncome;
    int fItems, items, i = 0;
    double cost[MAX_ITEMS] = {0};
    int priority[MAX_ITEMS] = {0};
    char finOptions[MAX_ITEMS] = {0};
    double totalCost = 0;


    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%f", &netIncome);
        if (netIncome < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (netIncome > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
    } while (netIncome < minIncome || netIncome > maxIncome);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &fItems);
        if (fItems <= 0 || fItems > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (fItems <= 0 || fItems > MAX_ITEMS);

    for (items = 1; items <= fItems; items++)
    {
        printf("\nItem-%d Details:\n", items);
        i++;
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < MIN_COST)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (cost[i] < MIN_COST);
        totalCost += cost[i];

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finOptions[i]);
            if (finOptions[i] != 'y' && finOptions[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (finOptions[i] != 'y' && finOptions[i] != 'n');



    }
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 1; i <= fItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i, priority[i], finOptions[i], cost[i]);
    }
    
    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n", totalCost);
    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}