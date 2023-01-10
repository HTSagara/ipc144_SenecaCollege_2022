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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NUM_PRODS 3
#define NUM_GRAMS_SUGGEST 64
#define LBS 2.20462

// ----------------------------------------------------------------------------
// structures

struct ReportData
{
    int sku;
    double price;
    int calories;
    double lbsWeight;
    double kgWeight;
    int gWeight;
    double totalServings;
    double costServings;
    double costCalServings;
};
// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// // 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* n);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* n);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int, int);

// 4. Get user input for the details of cat food product
void getCatFoodInfo(struct ReportData* data);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(struct ReportData* data);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(double* lbs, double* kg);

// 9. convert lbs: g
double convertLbsG(double* lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(double* lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(int* g, int n);

// 12. calculate: cost per serving
double calculateCostPerServing(double* price, double* servings);

// 13. calculate: cost per calorie
double calculateCostPerCal(double* price, int* calServings, double* servings);

// 14. Derive a reporting detail record based on the cat food product data
double calculateReportData(struct ReportData* data);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(struct ReportData* data);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct ReportData* data);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
