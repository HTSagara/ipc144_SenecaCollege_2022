/*
*****************************************************************************
                          Workshop - #8 (P2)
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
#include "w8p2.h"


// ----------------------------------------------------------------------------
// PART-1

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
void getCatFoodInfo(struct ReportData* data)
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
		scanf("%lf", &data[i].lbsWeight);
		do
		{
			if (data[i].lbsWeight <= 0)
			{
				printf("ERROR: Enter a positive value: ");
				scanf("%lf", &data[i].lbsWeight);
			}
		} while (data[i].lbsWeight <= 0);
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
	printf("\n");
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(struct ReportData* data)
{
	int i;
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		printf("%07d %10.2lf %10.1lf %8d\n", data[i].sku, data[i].price, data[i].lbsWeight, data[i].calories);
	}
}



// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(double* lbs, double* kg)
{
	double result;
	if (kg != NULL && lbs != NULL)
	{
		result = *lbs / LBS;
		*kg = result;
	}
	else
	{
		result = *lbs / LBS;
	}

	return result;

}

// 9. convert lbs: g (call convertKG, then * 1000)
double convertLbsG(double* lbs, int* g)
{
	double result;

	if (g != NULL && lbs != NULL)
	{
		result = (*lbs / LBS) * 1000;
		*g = result;
	}
	else
	{
		result = (*lbs / LBS) * 1000;
	}

	return result;

}

// 10. convert lbs: kg and g
void convertLbs(double *lbs, double *kg, int *g)
{
  *kg = *lbs / LBS;
  *g = (*lbs / LBS)*1000;
}

// 11. calculate: servings based on gPerServ
double calculateServings(int* g, int n)
{
	double result;

	result = (double) * g / (double) n;

	return result;
}

// 12. calculate: cost per serving
double calculateCostPerServing(double* price, double* servings)
{
	double result;

	result = *price / *servings;

	return result;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(double* price, int* calServings, double* servings)
{
	double result;

	result = *price / *calServings / *servings;

	return result;
}

// 14. Derive a reporting detail record based on the cat food product data
 double calculateReportData(struct ReportData *data)
{
	int i;
	//Bag-kg
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		data[i].kgWeight = convertLbsKg(&data[i].lbsWeight, &data[i].kgWeight);
	}
	
	//Bag-g
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		data[i].gWeight = convertLbsG(&data[i].lbsWeight, &data[i].gWeight);
	}

	//Servings
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		data[i].totalServings = calculateServings(&data[i].gWeight, NUM_GRAMS_SUGGEST);
	}

	// $/Serv
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		data[i].costServings = calculateCostPerServing(&data[i].price, &data[i].totalServings);
	}

	//$/Cal
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		data[i].costCalServings = calculateCostPerCal(&data[i].price, &data[i].calories, &data[i].totalServings);
	}

	return 0;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", NUM_GRAMS_SUGGEST);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(struct ReportData* data)
{
	int i, min, position;

	min = data[0].costServings;
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		if (data[i].costServings < min)
		{
			min = data[i].costServings;
			position = i;
		}
	}

	for ( i = 0; i < MAX_NUM_PRODS; i++)
	{
		if (i == position)
		{
			printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n",
				data[i].sku, data[i].price, data[i].lbsWeight, data[i].kgWeight, data[i].gWeight, data[i].calories, data[i].totalServings, data[i].costServings, data[i].costCalServings);
		}
		else
		{
			printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n",
				data[i].sku, data[i].price, data[i].lbsWeight, data[i].kgWeight, data[i].gWeight, data[i].calories, data[i].totalServings, data[i].costServings, data[i].costCalServings);
		}
	}

}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct ReportData* data)
{
	int i, min, position;

	min = data[0].costServings;
	for (i = 0; i < MAX_NUM_PRODS; i++)
	{
		if (data[i].costServings < min)
		{
			min = data[i].costServings;
			position = i;
		}
	}

	printf("\nFinal Analysis\n--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", data[position].sku, data[position].price);
	printf("\nHappy shopping!\n");

}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct ReportData data;
	// 3. 
	openingMessage(MAX_NUM_PRODS, NUM_GRAMS_SUGGEST);
	// 4.
	getCatFoodInfo(&data);
	// 5.
	displayCatFoodHeader();
	// 6.
	displayCatFoodData(&data);
	// 14.
	calculateReportData(&data);
	// 15.
	displayReportHeader();
	//16.
	displayReportData(&data);
	// 17.
	displayFinalAnalysis(&data);
}
