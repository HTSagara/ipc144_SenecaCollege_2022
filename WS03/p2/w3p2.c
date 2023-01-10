/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name  : Henrique Toshio Sagara
Student ID#: 170954218
Email      : hsagara@senecacollege.ca
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    // Note:
    // You can convert Celsius to Fahrenheit given the following formula:
    // fahrenheit = (celsius * 1.8) + 32.0);

    char cream_01, cream_02, coffeeStrength_1, coffeeType_1, coffeeEquipment_1, coffeeSize_1, cream_1, coffeeStrength_2, coffeeType_2, coffeeEquipment_2, coffeeSize_2, cream_2, coffeeType_3, coffeeSize_3, cream_3;
    int dailyServings_1, packageWeight_1, dailyServings_2, packageWeight_2, packageWeight_3;
    float temperature_1, temperature_2, temperature_3;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\nEnter the coffee product information being sold today...\n");

    printf("\nCOFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf("%c", &coffeeType_1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffeeSize_1);
    printf("Bag weight (g): ");
    scanf(" %d", &packageWeight_1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream_1);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%f", &temperature_1);
    
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType_2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffeeSize_2);
    printf("Bag weight (g): ");
    scanf(" %d", &packageWeight_2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream_2);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%f", &temperature_2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType_3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &coffeeSize_3);
    printf("Bag weight (g): ");
    scanf(" %d", &packageWeight_3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream_3);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%f", &temperature_3);
    
    printf("\n---+---------------+---------------+---------------+-------+--------------");
    printf("\n   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------");

    printf("\n 1 |");

    if (coffeeType_1 == 'l' || coffeeType_1 == 'L')
    {
        printf("   1   |   0   |");
    }
    else if (coffeeType_1 == 'b' || coffeeType_1 == 'B')
    {
        printf("   0   |   1   |");
    }
    else
    {
        printf(" Error | Error |");
    }

    if (coffeeSize_1 == 'c' || coffeeSize_1 == 'C')
    {
        printf("    1   |   0  |");
    }
    else if (coffeeSize_1 == 'f' || coffeeSize_1 == 'F')
    {
        printf("    0   |   1  |");
    }
    else
    {
        printf(" Error  |Error |");
    }

    printf("  %d |  %.3lf |", packageWeight_1, packageWeight_1 / GRAMS_IN_LBS);

    if (cream_1 == 'y' || cream_1 == 'Y')
    {
        printf("   1   |");
    }
    else if (cream_1 == 'n' || cream_1 == 'N')
    {
        printf("   0   |");
    }
    else
    {
        printf(" Error |");
    }

    printf("  %.1f | %.1f", temperature_1, temperature_1 * 1.8 + 32.0);
    
    printf("\n 2 |");
    if (coffeeType_2 == 'l' || coffeeType_2 == 'L')
    {
        printf("   1   |   0   |");
    }
    else if (coffeeType_2 == 'b' || coffeeType_2 == 'B')
    {
        printf("   0   |   1   |");
    }
    else
    {
        printf(" Error | Error |");
    }

    if (coffeeSize_2 == 'c' || coffeeSize_2 == 'C')
    {
        printf("    1   |   0  |");
    }
    else if (coffeeSize_2 == 'f' || coffeeSize_2 == 'F')
    {
        printf("    0   |   1  |");
    }
    else
    {
        printf(" Error  | Error|");
    }


    printf("  %d |  %.3lf |", packageWeight_2, packageWeight_2 / GRAMS_IN_LBS);

    if (cream_2 == 'y' || cream_2 == 'Y')
    {
        printf("   1   |");
    }
    else if (cream_2 == 'n' || cream_2 == 'N')
    {
        printf("   0   |");
    }
    else
    {
        printf(" Error |");
    }
    printf("  %.1f | %.1f", temperature_2, temperature_2 * 1.8 + 32.0);

    printf("\n 3 |");
    if (coffeeType_3 == 'l' || coffeeType_3 == 'L')
    {
        printf("   1   |   0   |");
    }
    else if (coffeeType_3 == 'b' || coffeeType_3 == 'B')
    {
        printf("   0   |   1   |");
    }
    else
    {
        printf(" Error | Error |");
    }

    if (coffeeSize_3 == 'c' || coffeeSize_3 == 'C')
    {
        printf("    1   |   0  |");
    }
    else if (coffeeSize_3 == 'f' || coffeeSize_3 == 'F')
    {
        printf("    0   |   1  |");
    }
    else
    {
        printf(" Error  | Error|");
    }

    printf(" %d |  %.3lf |", packageWeight_3, packageWeight_3 / GRAMS_IN_LBS);

    if (cream_3 == 'y' || cream_3 == 'Y')
    {
        printf("   1   |");
    }
    else if (cream_3 == 'n' || cream_3 == 'N')
    {
        printf("   0   |");
    }
    else
    {
        printf("   x   |");
    }

    printf("  %.1f | %.1f", temperature_3, temperature_3 * 1.8 + 32.0);
    
    printf("\n\nEnter how you like your coffee and the coffee maker equipment you use...\n");

    printf("\nCoffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength_1);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream_01);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyServings_1);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &coffeeEquipment_1);

    printf("\nThe below table shows how your preferences align to the available products:\n");

    printf("\n--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------");
    /*--------------------------------------------------------------------------------------------------------------------*/

    printf("\n 1|");
    if (coffeeStrength_1 == 'M' || coffeeStrength_1 == 'm')
    {
        if (coffeeType_1 == 'L' || coffeeType_1 == 'l')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }

    }

    else if (coffeeStrength_1 == 'R' || coffeeStrength_1 == 'r')
    {
        if (coffeeType_1 == 'B' || coffeeType_1 == 'b')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }
    }
    else
    {
        printf("       0         |");
    }

    if (coffeeEquipment_1 == 'C' || coffeeEquipment_1 == 'c')
    {
        if (coffeeSize_1 == 'F' || coffeeSize_1 == 'f')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else if (coffeeEquipment_1 == 'R' || coffeeEquipment_1 == 'r')
    {
        if (coffeeSize_1 == 'C' || coffeeSize_1 == 'c')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else
    {
        printf("         0          |");
    }

    if (dailyServings_1 < 5)
    {
        if (packageWeight_1 < 251)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_1 < 10)
    {
        if (packageWeight_1 == 500)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_1 > 9)
    {
        if (packageWeight_1 == 1000)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else
    {
        printf("      0      |");
    }

    if (cream_01 == 'y' || cream_01 == 'Y')
    {
        if (cream_1 == 'y' || cream_1 == 'Y')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else if (cream_01 == 'n' || cream_01 == 'N')
    {
        if (cream_1 == 'n' || cream_1 == 'N')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else
    {
        printf("   0   |");
    }

    if (coffeeEquipment_1 == 'R' || coffeeEquipment_1 == 'r')
    {
        if (temperature_1 > 59.9 && temperature_1 < 70.0)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else if (coffeeEquipment_1 == 'C' || coffeeEquipment_1 == 'c')
    {
        if (temperature_1 > 69.9)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else
    {
        printf("      0");
    }
    /*--------------------------------------------------------------------------------------------------------------------*/
    printf("\n 2|");
    if (coffeeStrength_1 == 'M' || coffeeStrength_1 == 'm')
    {
        if (coffeeType_2 == 'L' || coffeeType_2 == 'l')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }

    }

    else if (coffeeStrength_1 == 'R' || coffeeStrength_1 == 'r')
    {
        if (coffeeType_2 == 'B' || coffeeType_2 == 'b')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }
    }
    else
    {
        printf("       0         |");
    }

    if (coffeeEquipment_1 == 'C' || coffeeEquipment_1 == 'c')
    {
        if (coffeeSize_2 == 'F' || coffeeSize_2 == 'f')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else if (coffeeEquipment_1 == 'R' || coffeeEquipment_1 == 'r')
    {
        if (coffeeSize_2 == 'C' || coffeeSize_2 == 'c')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else
    {
        printf("         0          |");
    }

    if (dailyServings_1 < 5)
    {
        if (packageWeight_2 < 251)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_1 < 10)
    {
        if (packageWeight_2 == 500)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_1 > 9)
    {
        if (packageWeight_2 == 1000)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else
    {
        printf("      0      |");
    }

    if (cream_01 == 'y' || cream_01 == 'Y')
    {
        if (cream_2 == 'y' || cream_2 == 'Y')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else if (cream_01 == 'n' || cream_01 == 'N')
    {
        if (cream_2 == 'n' || cream_2 == 'N')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else
    {
        printf("   0   |");
    }

    if (coffeeEquipment_1 == 'R' || coffeeEquipment_1 == 'r')
    {
        if (temperature_2 > 59.9 && temperature_2 < 70.0)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else if (coffeeEquipment_1 == 'C' || coffeeEquipment_1 == 'c')
    {
        if (temperature_2 > 69.9)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else
    {
        printf("      0");
    }
    /*--------------------------------------------------------------------------------------------------------------------*/
    printf("\n 3|");
    if (coffeeStrength_1 == 'M' || coffeeStrength_1 == 'm')
    {
        if (coffeeType_3 == 'L' || coffeeType_3 == 'l')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }

    }

    else if (coffeeStrength_1 == 'R' || coffeeStrength_1 == 'r')
    {
        if (coffeeType_3 == 'B' || coffeeType_3 == 'b')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }
    }
    else
    {
        printf("       0         |");
    }

    if (coffeeEquipment_1 == 'C' || coffeeEquipment_1 == 'c')
    {
        if (coffeeSize_3 == 'F' || coffeeSize_3 == 'f')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else if (coffeeEquipment_1 == 'R' || coffeeEquipment_1 == 'r')
    {
        if (coffeeSize_3 == 'C' || coffeeSize_3 == 'c')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else
    {
        printf("         0          |");
    }

    if (dailyServings_1 < 5)
    {
        if (packageWeight_3 < 251)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_1 < 10)
    {
        if (packageWeight_3 == 500)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_1 > 9)
    {
        if (packageWeight_3 == 1000)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else
    {
        printf("      0      |");
    }

    if (cream_01 == 'y' || cream_01 == 'Y')
    {
        if (cream_3 == 'y' || cream_3 == 'Y')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else if (cream_01 == 'n' || cream_01 == 'N')
    {
        if (cream_3 == 'n' || cream_3 == 'N')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else
    {
        printf("   0   |");
    }

    if (coffeeEquipment_1 == 'R' || coffeeEquipment_1 == 'r')
    {
        if (temperature_3 > 59.9 && temperature_3 < 70.0)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else if (coffeeEquipment_1 == 'C' || coffeeEquipment_1 == 'c')
    {
        if (temperature_3 > 69.9)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else
    {
        printf("      0");
    }

    
    printf("\n\nEnter how you like your coffee and the coffee maker equipment you use...\n");

    printf("\nCoffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength_2);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream_02);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyServings_2);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &coffeeEquipment_2);

    printf("\nThe below table shows how your preferences align to the available products:\n");

    printf("\n--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------");
    /*--------------------------------------------------------------------------------------------------------------------*/
    printf("\n 1|");
    if (coffeeStrength_2 == 'M' || coffeeStrength_2 == 'm')
    {
        if (coffeeType_1 == 'L' || coffeeType_1 == 'l')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }

    }
    
    else if (coffeeStrength_2 == 'R' || coffeeStrength_2 == 'r')
    {
        if (coffeeType_1 == 'B' || coffeeType_1 == 'b')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }
    }
    else
    {
        printf("       0         |");
    }

    if (coffeeEquipment_2 == 'C' || coffeeEquipment_2 == 'c')
    {
        if (coffeeSize_1 == 'F' || coffeeSize_1 == 'f')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else if (coffeeEquipment_2 == 'R' || coffeeEquipment_2 == 'r')
    {
        if (coffeeSize_1 == 'C' || coffeeSize_1 == 'c')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else
    {
        printf("         0          |");
    }

    if (dailyServings_2 < 5)
    {
        if (packageWeight_1 < 251)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_2 < 10)
    {
        if (packageWeight_1 == 500)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_2 > 9)
    {
        if (packageWeight_1 == 1000)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else
    {
        printf("      0      |");
    }

    if (cream_02 == 'y' || cream_02 == 'Y')
    {
        if (cream_1 == 'y' || cream_1 == 'Y')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else if (cream_02 == 'n' || cream_02 == 'N')
    {
        if (cream_1 == 'n' || cream_1 == 'N')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else
    {
        printf("   0   |");
    }

    if (coffeeEquipment_2 == 'R' || coffeeEquipment_2 == 'r')
    {
        if (temperature_1 > 59.9 && temperature_1 < 70.0)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else if (coffeeEquipment_2 == 'C' || coffeeEquipment_2 == 'c')
    {
        if (temperature_1 > 69.9)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else
    {
        printf("      0");
    }
    /*--------------------------------------------------------------------------------------------------------------------*/
    printf("\n 2|");
    if (coffeeStrength_2 == 'M' || coffeeStrength_2 == 'm')
    {
        if (coffeeType_2 == 'L' || coffeeType_2 == 'l')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }

    }

    else if (coffeeStrength_2 == 'R' || coffeeStrength_2 == 'r')
    {
        if (coffeeType_2 == 'B' || coffeeType_2 == 'b')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }
    }
    else
    {
        printf("       0         |");
    }

    if (coffeeEquipment_2 == 'C' || coffeeEquipment_2 == 'c')
    {
        if (coffeeSize_2 == 'F' || coffeeSize_2 == 'f')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else if (coffeeEquipment_2 == 'R' || coffeeEquipment_2 == 'r')
    {
        if (coffeeSize_2 == 'C' || coffeeSize_2 == 'c')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else
    {
        printf("         0          |");
    }

    if (dailyServings_2 < 5)
    {
        if (packageWeight_2 < 251)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_2 < 10)
    {
        if (packageWeight_2 == 500)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_2 > 9)
    {
        if (packageWeight_2 == 1000)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else
    {
        printf("      0      |");
    }

    if (cream_02 == 'y' || cream_02 == 'Y')
    {
        if (cream_2 == 'y' || cream_2 == 'Y')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else if (cream_02 == 'n' || cream_02 == 'N')
    {
        if (cream_2 == 'n' || cream_2 == 'N')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else
    {
        printf("   0   |");
    }

    if (coffeeEquipment_2 == 'R' || coffeeEquipment_2 == 'r')
    {
        if (temperature_2 > 59.9 && temperature_2 < 70.0)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else if (coffeeEquipment_2 == 'C' || coffeeEquipment_2 == 'c')
    {
        if (temperature_2 > 69.9)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else
    {
        printf("      0");
    }
    /*--------------------------------------------------------------------------------------------------------------------*/
    printf("\n 3|");
    if (coffeeStrength_2 == 'M' || coffeeStrength_2 == 'm')
    {
        if (coffeeType_3 == 'L' || coffeeType_3 == 'l')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }

    }

    else if (coffeeStrength_2 == 'R' || coffeeStrength_2 == 'r')
    {
        if (coffeeType_3 == 'B' || coffeeType_3 == 'b')
        {
            printf("       1         |");
        }
        else
        {
            printf("       0         |");
        }
    }
    else
    {
        printf("       0         |");
    }

    if (coffeeEquipment_2 == 'C' || coffeeEquipment_2 == 'c')
    {
        if (coffeeSize_3 == 'F' || coffeeSize_3 == 'f')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else if (coffeeEquipment_2 == 'R' || coffeeEquipment_2 == 'r')
    {
        if (coffeeSize_3 == 'C' || coffeeSize_3 == 'c')
        {
            printf("         1          |");
        }
        else
        {
            printf("         0          |");
        }
    }
    else
    {
        printf("         0          |");
    }

    if (dailyServings_2 < 5)
    {
        if (packageWeight_3 < 251)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_2 < 10)
    {
        if (packageWeight_3 == 500)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else if (dailyServings_2 > 9)
    {
        if (packageWeight_3 == 1000)
        {
            printf("      1      |");
        }
        else
        {
            printf("      0      |");
        }
    }
    else
    {
        printf("      0      |");
    }

    if (cream_02 == 'y' || cream_02 == 'Y')
    {
        if (cream_3 == 'y' || cream_3 == 'Y')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else if (cream_02 == 'n' || cream_02 == 'N')
    {
        if (cream_3 == 'n' || cream_3 == 'N')
        {
            printf("   1   |");
        }
        else
        {
            printf("   0   |");
        }
    }
    else
    {
        printf("   0   |");
    }

    if (coffeeEquipment_2 == 'R' || coffeeEquipment_2 == 'r')
    {
        if (temperature_3 > 59.9 && temperature_3 < 70.0)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else if (coffeeEquipment_2 == 'C' || coffeeEquipment_2 == 'c')
    {
        if (temperature_3 > 69.9)
        {
            printf("      1");
        }
        else
        {
            printf("      0");
        }
    }
    else
    {
        printf("      0");
    }
    
    return 0;
}
