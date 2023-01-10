/*
*****************************************************************************
                          Workshop - #4 (P2)
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
    int apples, oranges, pears, tomatoes, cabbages, repeat;
    int applesPicked, orangesPicked, pearsPicked, tomatoesPicked, cabbagesPicked;


  do
  {
    printf("Grocery Shopping\n");
    printf("================\n");

    do //Apples loop
    {
        apples = 0;
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples);
        if (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        else
        {
            printf("\n");
        }
    } while (apples < 0);

    do //Organges loop
    {
        oranges = 0;
        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges);
        if (oranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        else
        {
            printf("\n");
        }
    } while (oranges < 0);

    do //Pears loop
    {
        pears = 0;
        printf("How many PEARS do you need? : ");
        scanf("%d", &pears);
        if (pears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
        }
        else
        {
            printf("\n");
        }
    } while (pears < 0);

    do //Tomatoes loop
    {
        tomatoes = 0;
        printf("How many TOMATOES do you need? : ");
        scanf("%d",&tomatoes);
        if (tomatoes < 0)
        {
          printf("ERROR: Value must be 0 or more.\n");
        }
        else
        {
          printf("\n");
        }
    } while (tomatoes < 0);

      do //Cabbages loop
      {
         cabbages = 0;
        printf("How many CABBAGES do you need? : ");
        scanf("%d",&cabbages);
        if (cabbages < 0)
        {
          printf("ERROR: Value must be 0 or more.\n");
        }
        else
        {
          printf("\n");
        }
      } while (cabbages < 0);

    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n");

    //Pick apples 
    if (apples > 0)
    {
        do {
            printf("\nPick some APPLES... how many did you pick? : ");
            scanf("%d", &applesPicked);

            if (applesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (applesPicked <= apples && applesPicked > 0)
            {
                apples -= applesPicked;
                if (apples != 0)
                {
                    printf("Looks like we still need some APPLES...");
                }
                else
                {
                    printf("Great, that's the apples done!\n");
                }
            }
            else
            {
                printf("You picked too many... only %d more APPLE(S) are needed.", apples);
            }

        } while (apples > 0);
            
    }  

    //Pick oranges 
    if (oranges > 0)
    {
        do {
            printf("\nPick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangesPicked);

            if (orangesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (orangesPicked <= oranges && orangesPicked > 0)
            {
                oranges -= orangesPicked;
                if (oranges != 0)
                {
                    printf("Looks like we still need some ORANGES...");
                }
                else
                {
                    printf("Great, that's the oranges done!\n");
                }
            }
            else
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.", oranges);
            }

        } while (oranges > 0);

    }


    //Pick pears 
    if (pears > 0)
    {
        do {
            printf("\nPick some PEARS... how many did you pick? : ");
            scanf("%d", &pearsPicked);

            if (pearsPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (pearsPicked <= pears && pearsPicked > 0)
            {
                pears -= pearsPicked;
                if (pears != 0)
                {
                    printf("Looks like we still need some PEARS...");
                }
                else
                {
                    printf("Great, that's the pears done!\n");
                }
            }
            else
            {
                printf("You picked too many... only %d more PEAR(S) are needed.", pears);
            }

        } while (pears > 0);

    }

    //Pick tomatoes
    if (tomatoes > 0)
    {
        do {
            printf("\nPick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoesPicked);

            if (tomatoesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (tomatoesPicked <= tomatoes && tomatoesPicked > 0)
            {
                tomatoes -= tomatoesPicked;
                if (tomatoes != 0)
                {
                    printf("Looks like we still need some TOMATOES...");
                }
                else
                {
                    printf("Great, that's the tomatoes done!\n");
                }
            }
            else
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.", tomatoes);
            }

        } while (tomatoes > 0);

    }

    //Pick cabbages
    if (cabbages > 0)
    {
        do {
            printf("\nPick some CABBAGES... how many did you pick? : ");
            scanf("%d", &cabbagesPicked);

            if (cabbagesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!");
            }
            else if (cabbagesPicked <= cabbages && cabbagesPicked > 0)
            {
                cabbages -= cabbagesPicked;
                if (cabbages != 0)
                {
                    printf("Looks like we still need some CABBAGES...");
                }
                else
                {
                    printf("Great, that's the cabbages done!\n");
                }
            }
            else
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.", cabbages);
            }

        } while (cabbages > 0);

    }

    printf("\nAll the items are picked!\n");
    printf("\nDo another shopping? (0=NO): ");
    scanf("%d", &repeat);
    printf("\n");
  } while (repeat != 0);
  printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}