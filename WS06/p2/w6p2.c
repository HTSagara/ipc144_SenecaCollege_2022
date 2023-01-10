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
    const double minIncome = 500;
    const double maxIncome = 400000;
    const int months = 12;
    double totalCost = 0, netIncome, cost2 = 0, yearFcst, monthFcst, roundup = 0.5;
    int fItems, items, i = 0, selection, priorityInput, x = 0;
    double cost[MAX_ITEMS] = { 0 };
    int priority[MAX_ITEMS] = { 0 };
    char finOptions[MAX_ITEMS] = { 0 };



    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do
    {
        printf("\nEnter your monthly NET income: $");
        scanf("%lf", &netIncome);
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
    printf("                      $ %.2f\n", totalCost);
    
    /*******************************************************************************************************************************************/

    do 
    {
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n 2. By priority\n 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);

        if (selection == 1) 
        {
            x = 0;
            yearFcst = 0;
            monthFcst = 0;
            x = 0;
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);
            yearFcst = totalCost / netIncome / months;
            monthFcst = (((totalCost / netIncome / months)-(int)yearFcst)*months);
            printf("Forecast: %d years, %.0lf months\n", (int)yearFcst, monthFcst);
            for (i = 0; i < fItems; i++)
            {
                if (finOptions[i] == 'y')
                {
                    x++;
                }
            }
            if (x > 0) 
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");
        }
        else if (selection == 2)
        {
            x = 0;
            yearFcst = 0 ;
            monthFcst = 0;
            cost2 = 0;
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityInput);
            if (priorityInput == 1 || priorityInput == 2 || priorityInput == 3)
            {
                printf("\n====================================================\n");
                printf("Filter:   by priority (%d)\n", priorityInput);
                for (i = 0; i <= fItems; i++)
                {
                    if (priority[i] == priorityInput)
                    {
                        cost2 += cost[i];
                    }
                }
                printf("Amount:   $%.2lf\n", cost2);
                yearFcst = cost2 / netIncome / months;
                monthFcst = (((((float)cost2 / (float)netIncome / months)-(int)yearFcst)*months))+roundup;
                printf("Forecast: %d years, %.0lf months\n", (int)yearFcst, monthFcst);
                for (i = 0; i < fItems; i++)
                {
                    if (priority[i] == priorityInput && finOptions[i] == 'y')
                    {
                        x++;
                    }
                }
                if (x > 0)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                printf("====================================================\n");
            }
            else
            {
                printf("\nERROR: Value must be between 1 and 3\n");
            }
        }
        else if (selection == 0)
        {
            printf("\nBest of luck in all your future endeavours!\n");
        }
        else
        {
            printf("\nERROR: Invalid menu selection.\n");
        }
    } while (selection != 0);


    return 0;
}
