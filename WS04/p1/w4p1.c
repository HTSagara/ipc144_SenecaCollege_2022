/*
*****************************************************************************
                          Workshop - #4 (P1)
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

int main(void) {
    char inputLetter;
    int inputNumber, q;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+");

    do
    {
        q = 0;
        printf("\n\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &inputLetter, &inputNumber);
        if ((inputLetter == 'D' || inputLetter == 'W' || inputLetter == 'F') && (inputNumber > 2 && inputNumber < 21))
        {
            if (inputLetter == 'D')
            {
                printf("DO-WHILE: ");
                do
                {
                    printf("%c", inputLetter);
                    q++;
                } while (q < inputNumber);
            }
            else if (inputLetter == 'W')
            {
                printf("WHILE   : ");
                while (q < inputNumber)
                {
                    printf("%c", inputLetter);
                    q++;
                }
            }
            else if (inputLetter == 'F')
            {
                printf("FOR     : ");
                for (q = 0; q < inputNumber; q++)
                {
                    printf("%c", inputLetter);
                }
            }
        }
        else if ((inputLetter == 'D' || inputLetter == 'W' || inputLetter == 'F') && (inputNumber < 3 || inputNumber > 20))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!");
        }
        else if (inputLetter == 'Q' && inputNumber != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!");
        }
        else if (inputLetter == 'Q' && inputNumber == 0)
        {
            printf("\n");
        }
        else if ((inputLetter != 'D' || inputLetter != 'W' || inputLetter != 'F') && (inputNumber > 2 || inputNumber < 21))
        {
            printf("ERROR: Invalid entered value(s)!");
        }
        else
        {
            printf("ERROR: Invalid entered value(s)!");
        }

    } while (inputLetter != 'Q' || inputNumber != 0);


    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}
