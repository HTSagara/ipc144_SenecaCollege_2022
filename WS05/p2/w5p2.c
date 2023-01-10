/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012 
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int jan = 1, dec = 12;
    int yearInput, monthInput, day, i = 0, ii = 0;
    double mRating[5] = {0};
    double eRating[5] = {0};
    double totalMorRating = 0, totalEveRating = 0;
    char month[13][5]= {"JAN\0", "FEB\0", "MAR\0", "JUN\0", "JUL\0", "AUG\0", "SEP\0", "OCT\0", "NOV\0", "DEC\0"};


    printf("General Well-being Log\n");
    printf("======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &yearInput, &monthInput);
        if ((yearInput < MIN_YEAR || yearInput > MAX_YEAR) && (monthInput >= jan && monthInput <= dec))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if ((yearInput >= MIN_YEAR && yearInput <= MAX_YEAR) && (monthInput <= jan || monthInput >= dec))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else if ((yearInput < MIN_YEAR || yearInput > MAX_YEAR) && (monthInput < jan || monthInput > dec))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }


    } while (yearInput < MIN_YEAR || yearInput > MAX_YEAR || monthInput < jan || monthInput > dec);

    printf("\n*** Log date set! ***\n");



    for (day = 1; day <= LOG_DAYS; day++)
    {
        printf("\n%d-%s-0%d\n", yearInput, month[monthInput - 1], day);

        i++;
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &mRating[i]);
            if (mRating[i] < 0.0 || mRating[i] > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (mRating[i] < 0.0 || mRating[i] > 5.0);
        totalMorRating += mRating[i];

        ii++;
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eRating[ii]);
            if (eRating[ii] < 0.0 || eRating[ii] > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eRating[ii] < 0.0 || eRating[ii] > 5.0);
        totalEveRating += eRating[ii];
        
    }
    
    printf("\nSummary\n");
    printf("=======\n");
    
    printf("Morning total rating: %.3lf\n", totalMorRating);
    printf("Evening total rating:  %.3lf\n", totalEveRating);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", totalMorRating + totalEveRating);

    printf("\nAverage morning rating:  %.1lf\n", totalMorRating / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", totalEveRating / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", ((totalMorRating / LOG_DAYS) + (totalEveRating / LOG_DAYS))/ 2);
    

    return 0;
}