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
#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define MULT 5

char* rmv_gaps(char* str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}

int main(void)
{
    int numLives, pathLength, limitMoves, numMoves, i = 0, p = MULT;
    char bombs[MAX_PATH_LENGTH][MULT * 2] = { {0} };
    char treasures[MAX_PATH_LENGTH][MULT * 2] = { {0} };
    char playerChar;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");

    printf("\nPLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &playerChar);
    do 
    {
        printf("Set the number of lives: ");
        scanf("%d", &numLives);
        if (numLives < 1 || numLives > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }
        else
        {
            printf("Player configuration set-up is complete\n");
        }

    } while (numLives < 1 || numLives > 10);
   

    printf("\nGAME Configuration\n");
    printf("------------------\n");
    
    do 
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &pathLength);
        if (pathLength < MIN_PATH_LENGTH || pathLength > MAX_PATH_LENGTH || pathLength % MULT != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (pathLength < MIN_PATH_LENGTH || pathLength > MAX_PATH_LENGTH || pathLength % MULT != 0);
    limitMoves = pathLength * 0.75; //define as MACRO

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &numMoves);
        if (numMoves < numLives || numMoves > limitMoves)
        {
            printf("    Value must be between %d and %d\n", numLives, limitMoves);
        }
    } while (numMoves < numLives || numMoves > limitMoves);

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n"
                 "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
                 "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",MULT, pathLength);

    do
    {
        printf("   Positions [%2d-%2d]: ", p - 4, p);
        scanf(" %[^\n]%*c", bombs[i]);
        i++;
        p += 5;
    } while (i < (pathLength / MULT));
    i = 0;
    p = 5;

    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULT, pathLength);

    do
    {
        printf("   Positions [%2d-%2d]: ", p - 4, p);
        scanf(" %[^\n]%*c", treasures[i]);
        i++;
        p += 5;
    } while (i < (pathLength / MULT));
    i = 0;
    p = 5;

    printf("TREASURE placement set\n");

    printf("\nGAME configuration set-up is complete...\n");
    printf("\n------------------------------------"
        "\nTREASURE HUNT Configuration Settings"
        "\n------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", playerChar);
    printf("   Lives      : %d\n", numLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    printf("\nGame:\n");
    printf("   Path Length: %d\n", pathLength);
    printf("   Bombs      : ");
    do
    {
        rmv_gaps(bombs[i]);
        printf("%s", bombs[i]);
        i++;
    } while (i < (pathLength / MULT));
    i = 0;

    printf("\n   Treasure   : ");
    do
    {
        rmv_gaps(treasures[i]);
        printf("%s", treasures[i]);
        i++;
    } while (i < (pathLength / MULT));
 
    printf("\n\n====================================\n"
    "~ Get ready to play TREASURE HUNT! ~\n"
    "====================================\n");

    return 0;
}
