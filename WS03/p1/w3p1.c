/*
*****************************************************************************
						  Workshop - #3 (P1)
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

#include <stdio.h>

int main(void)
{
	// You must use this variable in #3 data analysis section!
	const double testValue = 330.99;
	const int ID1 = 111, ID2 = 222, ID3 = ID1;
	const float Price1 = 111.49, Price2 = 222.99, Price3 = 334.49;
	const char Taxed1 = 'Y', Taxed2 = 'N', Taxed3 = 'N';
	double avgPrice = (Price1 + Price2 + Price3) / 3;

	printf("Product Information\n");
	printf("===================\n");
	printf("Product-1 (ID:%d)\n", ID1);
	printf("  Taxed: %c\n", Taxed1);
	printf("  Price: $%.4f\n", Price1);

	printf("\nProduct-2 (ID:%d)\n", ID2);
	printf("  Taxed: %c\n", Taxed2);
	printf("  Price: $%.4f\n", Price2);

	printf("\nProduct-3 (ID:%d)\n", ID3);
	printf("  Taxed: %c\n", Taxed3);
	printf("  Price: $%.4f\n", Price3);

	printf("\nThe average of all prices is: $%.4f\n", avgPrice);

	printf("\nAbout Relational and Logical Expressions!");
	printf("\n========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("2. FALSE: is always represented by integer value 0");
	printf("\n3. TRUE : is represented by any integer value other than 0\n");
	printf("\nSome Data Analysis...\n");
	printf("=====================\n");

	printf("1. Is product 1 taxable? -> ");
	if (Taxed1 == 'Y')
	{
		printf("1\n");
	}
	else { printf("0\n"); }

	printf("\n2. Are products 2 and 3 both NOT taxable (N)? -> ");
	if (Taxed2 && Taxed3 == 'N')
	{
		printf("1\n");
	}
	else { printf("0\n"); }

	printf("\n3. Is product 3 less than testValue ($%.2lf)? -> ", testValue);
	if (Price3 < testValue)
	{
		printf("1\n");
	}
	else { printf("0\n"); }

	printf("\n4. Is the price of product 3 more than both product 1 and 2 combined? -> ");
	if (Price3 > Price1 + Price2)
	{
		printf("1\n");
	}
	else { printf("0\n"); }

	printf("\n5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  ");
	if (Price1 >= Price3 - Price2)
	{
		printf("1 ");
	}
	else { printf("0 "); }
	printf("(price difference: $%.2f)\n", Price3 - Price2);

	printf("\n6. Is the price of product 2 equal to or more than the average price? -> ");
	if (Price2 >= avgPrice)
	{
		printf("1\n");
	}
	else { printf("0\n"); }

	printf("\n7. Based on product ID, product 1 is unique -> ");
	if (ID1 != !ID2 && !ID3)
	{
		printf("1\n");
	}
	else { printf("0\n"); }

	printf("\n8. Based on product ID, product 2 is unique -> ");
	if (ID2 != ID1 && ID3)
	{
		printf("1\n");
	}
	else { printf("0\n"); }

	printf("\n9. Based on product ID, product 3 is unique -> ");
	if (ID3 != !ID1 && !ID2)
	{
		printf("1\n");
	}
	else { printf("0\n"); }


	return 0;
}