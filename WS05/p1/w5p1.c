/*
*****************************************************************************
                          Workshop - #5 (P1)
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

int main(void)
{
    const int jan = 1, dec = 12;
    int yearInput, monthInput;


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

    if (monthInput == 1)
    {
        printf("\nLog starting date: %d-JAN-01\n", yearInput);
    }
    else if (monthInput == 2)
    {
        printf("\nLog starting date: %d-FEB-01\n", yearInput);
    }
    else if (monthInput == 3)
    {
        printf("\nLog starting date: %d-MAR-01\n", yearInput);
    }
    else if (monthInput == 4)
    {
        printf("\nLog starting date: %d-APR-01\n", yearInput);
    }
    else if (monthInput == 5)
    {
        printf("\nLog starting date: %d-MAY-01\n", yearInput);
    }
    else if (monthInput == 6)
    {
        printf("\nLog starting date: %d-JUN-01\n", yearInput);
    }
    else if (monthInput == 7)
    {
        printf("\nLog starting date: %d-JUL-01\n", yearInput);
    }
    else if (monthInput == 8)
    {
        printf("\nLog starting date: %d-AUG-01\n", yearInput);
    }
    else if (monthInput == 9)
    {
        printf("\nLog starting date: %d-SEP-01\n", yearInput);
    }
    else if (monthInput == 10)
    {
        printf("\nLog starting date: %d-OCT-01\n", yearInput);
    }
    else if (monthInput == 11)
    {
        printf("\nLog starting date: %d-NOV-01\n", yearInput);
    }
    else if (monthInput == 12)
    {
        printf("\nLog starting date: %d-DEC-01\n", yearInput);
    }




    return 0;
}