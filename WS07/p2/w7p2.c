/*
*****************************************************************************
                          Workshop - #7 (P2)
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

void line0(int nextMove, int pathLength, char playerChar)
{
    int i;
    printf("\n");
    if (nextMove > 0 && nextMove <= pathLength)
    {
        for (i = 1; i < nextMove + 2; i++)
        {
            printf(" ");
        }
        do
        {
            printf("%c\n", playerChar);
        } while (i < nextMove+2);

    }
}

void line2(int pathLength)
{
    int i;
    int dozens = 1;

    for (i = 0; i < pathLength; i++)
    {
        if (i % 10 == 9)
        {
            printf("%d", (dozens / 10));
        }
        else
        {
            printf("|");
        }
        dozens++;
    }
    printf("\n");

}
void line3(int pathLength)
{
    int i;

    for (i = 0; i < pathLength; i++)
    {
        if (i % 10 >= 0 && i % 10 < 9)
        {
            printf("%d", i % 10 + 1);
        }
        else
        {
            printf("%d", 0);
        }
        
    }
}

struct Status
{
    int livesLeft;
    int treasureFound;
    int movesRemaining;
};

int main(void)
{
    int numLives, pathLength, limitMoves, numMoves, i = 0, p = MULT, nextMove = 0, j = 0, h = 0;
    int bombs[MAX_PATH_LENGTH] = {0};
    int treasures[MAX_PATH_LENGTH] = {0};
    char playerChar;
    char displayArray[MAX_PATH_LENGTH] = {0};
    char tempstr[MAX_PATH_LENGTH] = {0};
    int previousMoves[MAX_PATH_LENGTH] = { 0 };


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
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULT, pathLength);

    do
    {
        printf("   Positions [%2d-%2d]: ", p - 4, p);
        scanf(" %[^\n]%*c", tempstr);
        j++;
        for (i = 0; i <= pathLength; i++)
        {
            if (tempstr[i] != ' ' && i < 9)
            {
                bombs[(p - 5) + (i / 2)] = tempstr[i] - 48; //ASCII FOR '0'
            }

        }
        p += 5;
    } while (j < (pathLength / MULT));

    j = 0;
    p = 5;
    i = 0;
    

    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULT, pathLength);
    j = 0;
    do
    {
        printf("   Positions [%2d-%2d]: ", p - 4, p);
        scanf(" %[^\n]%*c", tempstr);
        j++;
        for (i = 0; i <= pathLength; i++)
        {
            if (tempstr[i] != ' ' && i < 9)
            {
                treasures[(p - 5) + (i / 2)] = tempstr[i] - 48; //ASCII FOR '0'
            }

        }
        p += 5;
    } while (j < (pathLength / MULT));

    j = 0;
    p = 5;
    i = 0;

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
    for (i = 0; i < pathLength; i++)
    {
        printf("%d", bombs[i]);
    }

    printf("\n   Treasure   : ");
    for (i = 0; i < pathLength; i++)
    {
        printf("%d", treasures[i]);
    }

    printf("\n\n====================================\n"
        "~ Get ready to play TREASURE HUNT! ~\n"
        "====================================\n");


    struct Status status1 = {
        numLives, 0, numMoves
    };

    for (i = 0; i < pathLength; i++)
    {
        displayArray[i] = '-';
    }
    printf("\n");


    do
    {

        if (nextMove > 0)
        {
            line0(nextMove, pathLength, playerChar);
            printf("  ");
            for (i = 0; i < pathLength; i++)
            {
                printf("%c", displayArray[i]);
            }
            printf("\n");
            printf("  ");
            line2(pathLength);
            printf("  ");
            line3(pathLength);
        }

   
        else
        {
            printf("  ");
            for (i = 0; i < pathLength; i++)
            {
                printf("%c", displayArray[i]);
            }
            printf("\n");
            printf("  ");
            line2(pathLength);
            printf("  ");
            line3(pathLength);
        }

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", status1.livesLeft, status1.treasureFound, status1.movesRemaining);
        printf("+---------------------------------------------------+\n");
        do
        {
            printf("Next Move [1-%d]: ", pathLength);
            scanf("%d", &nextMove);
            if (nextMove < 1 || nextMove > pathLength)
            {
                printf("  Out of Range!!!\n");
            }
        } while (nextMove < 1 || nextMove > pathLength);
        for (i = 0; i < pathLength; i++)
        {
            if (previousMoves[i] == nextMove)
            {
                printf("\n===============> Dope! You've been here before!\n");
                j = 1; //boolean, to check it latter if the variable already exists
                status1.movesRemaining++;
            }
        }
        previousMoves[h] = nextMove;
        h++;

        if (bombs[nextMove - 1] == 1 && treasures[nextMove - 1] == 0)
        {
            displayArray[nextMove - 1] = '!';
            status1.livesLeft--;
            printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
        }
        else if (treasures[nextMove - 1] == 1 && bombs[nextMove - 1] == 0)
        {
            displayArray[nextMove - 1] = '$';
            status1.treasureFound++;
            printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
        }
        else if (bombs[nextMove - 1] == 1 && treasures[nextMove - 1] == 1)
        {
            displayArray[nextMove - 1] = '&';
            status1.treasureFound++;
            status1.livesLeft--;
            printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
        }
        else if (bombs[nextMove - 1] == 0 && treasures[nextMove - 1] == 0 && j != 1)
        {
            displayArray[nextMove - 1] = '.';

            printf("\n===============> [.] ...Nothing found here... [.]\n");
        }
        status1.movesRemaining--;

     } while (status1.movesRemaining > 0 && status1.livesLeft > 0);
     printf("\nNo more LIVES remaining!\n");

     line0(nextMove, pathLength, playerChar);
     printf("  ");
     for (i = 0; i < pathLength; i++)
     {
         printf("%c", displayArray[i]);
     }
     printf("\n");
     printf("  ");
     line2(pathLength);
     printf("  ");
     line3(pathLength);


     printf("\n+---------------------------------------------------+\n");
     printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", status1.livesLeft, status1.treasureFound, status1.movesRemaining);
     printf("+---------------------------------------------------+\n");

    printf("\n##################\n"
        "#   Game over!   #\n"
        "##################\n");
    printf("\nYou should play again and try to beat your score!\n");











    return 0;
}



