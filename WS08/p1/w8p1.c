/*
*****************************************************************************
                          Workshop - #8 (P1)
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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* n)
{
	int var;
	do
	{
		scanf("%d", &var);
		if (var <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (var <= 0);
	if (n != NULL)
	{
		*n = var;
	}

	return var;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* n)
{
	double var;
	do
	{
		scanf("%lf", &var);
		if (var <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (var <= 0);
	if (n != NULL)
	{
		*n = var;
	}

	return var;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int x, int y)
{

	printf("Cat Food Cost Analysis\n"
	"======================\n"
	"\nEnter the details for %d dry food bags of product data for analysis.\n"
	"NOTE: A 'serving' is %dg\n", x, y);
}

// 4. Get user input for the details of cat food product
void getCatFoodInfo(struct CatFoodInfo *data)
{
	int i, j = 1;
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		printf("\nCat Food Product #%d\n"
			"--------------------\n", j++);
			printf("SKU           : ");
			scanf("%d", &data[i].sku);
			do
			{
				if (data[i].sku <= 0)
				{
					printf("ERROR: Enter a positive value: ");
					scanf("%d", &data[i].sku);
				}
			} while (data[i].sku <= 0);

			printf("PRICE         : $");
			scanf("%lf", &data[i].price);
			do
			{
				if (data[i].price <= 0)
				{
					printf("ERROR: Enter a positive value: ");
					scanf("%lf", &data[i].price);
				}
			} while (data[i].price <= 0);

			printf("WEIGHT (LBS)  : ");
			scanf("%lf", &data[i].weight);
			do
			{
				if (data[i].weight <= 0)
				{
					printf("ERROR: Enter a positive value: ");
					scanf("%lf", &data[i].weight);
				}
			} while (data[i].weight <= 0);
			printf("CALORIES/SERV.: ");
			scanf("%d", &data[i].calories);
			do
			{
				if (data[i].calories <= 0)
				{
					printf("ERROR: Enter a positive value: ");
					scanf("%d", &data[i].calories);
				}
			} while (data[i].calories <= 0);
	}
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(struct CatFoodInfo *data)
{
	int i;
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		printf("%07d %10.2lf %10.1lf %8d\n", data[i].sku, data[i].price, data[i].weight, data[i].calories);
	}
}

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo data;
	openingMessage(MAX_NUM_PRODS, NUM_GRAMS_SUGGEST);
	getCatFoodInfo(&data);
	displayCatFoodHeader();
	displayCatFoodData(&data);
}