/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include <string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
// Check if the number is positive
int inputIntPositive()
{
    int value, keeptrying = 1, rc;


    do
    {
        rc = scanf("%d", &value);
        if (rc == 0)
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (value < 0)
        {
            printf("ERROR! Value must be > 0: ");
            clearInputBuffer();
        }
        else
        {
            keeptrying = 0;
        }
    } while (keeptrying == 1);

    return value;
}

// Check if the number is between the range
int inputIntRange(int min, int max)
{
    int value, keeptrying = 1, rc;

    do
    {
        rc = scanf("%d", &value);
        if (rc == 0)
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (value < min || value > max)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
            clearInputBuffer();
        }
        else
        {
            keeptrying = 0;
        }
    } while (keeptrying == 1);

    return value;
}

// Check if a Char exists inside the Str, use an array
char inputCharOption(char arr[])
{
    int i, rc, j = 0;
    char input;
    do
    {
        rc = scanf(" %c", &input);
        if (rc == 1)
        {
            for (i = 0; i < strlen(arr); i++)
            {
                if (input == arr[i])
                {
                    j++;
                }
            }
            if (j <= 0)
            {
                printf("ERROR: Character must be one of [");         //print the error message
                for (i = 0; i < strlen(arr); i++)                      //for each item in the array, print the character
                {
                    printf("%c", arr[i]);
                }
                printf("]: ");                                     //end of the message
            }
        }

    } while (j <= 0);

    return input;
}



void inputCString(char arr[], int min, int max)
{
    int n;

    clearInputBuffer();
    if (min == max)
    {
        do
        {

            scanf("%[^\n]", arr);
            n = strlen(arr);
            if (n != max)
            {
                printf("ERROR: String length must be exactly %d chars: ", max);
                clearInputBuffer();
            }
        } while (n != max);
        //clearInputBuffer();
    }
    else if (min != max)
    {
        do
        {

            scanf("%[^\n]", arr);
            n = strlen(arr);
            if (n < min || n > max)
            {
                if (max - min == 1)
                {
                    printf("ERROR: String length must be between %d and %d chars: ", min, max);
                    clearInputBuffer();
                }
                else
                {
                    printf("ERROR: String length must be no more than %d chars: ", max);
                    clearInputBuffer();
                }

            }
        } while (n < min || n > max);
        //clearInputBuffer();
    }

}

void displayFormattedPhone(const char* phone)
{
    int i, j = 0, n, intArr[100], sum = 0;


    if (phone == NULL || strlen(phone) != 10)
    {
        printf("(___)___-____");
    }
    else
    {
        for (i = 0; i < strlen(phone); i++)
        {
            n = phone[i] - 48;
            if (n >= 0 && n <= 9)
            {
                intArr[j] = n;
                j++;
                sum++;
            }
            else
            {
                for (j = 0; j < strlen(phone); j++)
                {
                    intArr[j] = 0;
                }
            }

        }


        if (sum >= 10)
        {
            printf("(%d%d%d)%d%d%d-%d%d%d%d", intArr[0], intArr[1], intArr[2], intArr[3], intArr[4], intArr[5], intArr[6], intArr[7], intArr[8], intArr[9]);
        }
        else
        {
            printf("(___)___-____");
        }
    }


}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

