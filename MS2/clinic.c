/*
*****************************************************************************
                        Assignment 1 - Milestone 2
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
#include<string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            //putchar('\n');
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("\nPatient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    displayPatientTableHeader();



    for (i = 0; i < MAX_PETS; i++)
    {
        if (patient[i].patientNumber > 0)
        {
            displayPatientData(&patient[i], fmt);
        }
    }
    putchar('\n');
    clearInputBuffer();
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection, i, j;
    char phoneNum[PHONE_LEN + 1];
    
    do
    {
        j = 0;
        clearInputBuffer();
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");

        //clearInputBuffer();

        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            //searchPatientByPatientNumber(&patient->patientNumber, MAX_PETS);
            searchPatientByPatientNumber(patient, MAX_PETS);
        }
        else if (selection == 2)
        {
            //searchPatientByPhoneNumber(&patient->phone, MAX_PETS);
            clearInputBuffer();
            printf("Search by phone number: ");
            scanf("%s", phoneNum);
            putchar('\n');
            displayPatientTableHeader();
            for (i = 0; i < MAX_PETS; i++)
            {
                if (strcmp(patient[i].phone.number, phoneNum) == 0)
                {
                    displayPatientData(&patient[i], FMT_TABLE);
                    j++;
                }
            }
            if (j <= 0)
            {
                printf("\n*** No records found ***\n");
            }
            putchar('\n');
            suspend();
        }

    } while (selection != 0);
    clearInputBuffer();
}


// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i, emptyID, length = 0;

    emptyID = 0;
    for (i = 0; i < MAX_PETS; i++)
    {
        if (patient[i].patientNumber > 0)
        {
            length++;
        }
    }

    for (i = 0; i < length + 1 && i < MAX_PETS; i++)
    {
        if (patient[i].patientNumber == '\0')
        {
            emptyID = i;
        }
    }
    if (emptyID == 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[emptyID].patientNumber = nextPatientNumber(patient, MAX_PETS);
        printf("Patient Data Input\n"
            "------------------\n");
        printf("Number: 0%d\n", patient[emptyID].patientNumber);
        inputPatient(&patient[emptyID]);
        putchar('\n');
    }

    clearInputBuffer();
}


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int patientNum, index = 0;

    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    index = findPatientIndexByPatientNum(patientNum, patient, MAX_PETS);

    if (index >= 0)
    {
        putchar('\n');
        menuPatientEdit(&patient[index]);
    }
    else
    {
        printf("ERROR: Patient record not found!");
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int patientNum, index = 0;
    char answer, rmvName[NAME_LEN + 1] = { "000000000000000" };
    char rmvPhone[PHONE_LEN + 1] = { "0000000000" };
    char rmvPDecrip[PHONE_DESC_LEN + 1] = {"0000"};
    

    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    index = findPatientIndexByPatientNum(patientNum, patient, MAX_PETS);
    if (index >= 0)
    {
        putchar('\n');
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &answer);
        clearInputBuffer();
        if (answer == 'y')
        {
            patient[index].patientNumber = 0;
            strcpy(patient[index].name, rmvName);
            strcpy(patient[index].phone.number, rmvPhone);
            strcpy(patient[index].phone.description, rmvPDecrip);
            printf("Patient record has been removed!\n\n");
            
        }
        else if (answer == 'n')
        {
            printf("Operation aborted.\n\n");
        }
    }
    else
    {
        clearInputBuffer();
        printf("\nERROR: Patient record not found!\n\n");

    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNum, i, j;

    clearInputBuffer();
    j = 0;
    printf("Search by patient number: ");
    scanf("%d", &patientNum);
    putchar('\n');
    for (i = 0; i < MAX_PETS; i++)
    {
        if (patientNum == patient[i].patientNumber)
        {
            displayPatientData(&patient[i], FMT_FORM);
            j++;
        }
    }
    if (j <= 0)
    {
        printf("*** No records found ***\n");
    }
    putchar('\n');
    suspend();
    

}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, j;
    char phoneNum[PHONE_LEN + 1];

    clearInputBuffer();
    j = 0;
    printf("Search by phone number: ");
    scanf("%s", phoneNum);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < MAX_PETS; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNum) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            j++;
        }
    }
    if (j <= 0)
    {
        printf("\n*** No records found ***\n");
    }
    putchar('\n');
    suspend();
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) 
{
    int result = 0, i;

    for (i = 0; i < MAX_PETS; i++)
    {
        if (patient[i].patientNumber > result)
        {
            result = patient[i].patientNumber;
        }
    }
    result = result + 1;

    return result;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max) 
{
    int result = -1, i;
    for (i = 0; i < MAX_PETS; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            result = i;
        }
    }

    return result;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    char newName[NAME_LEN];

    clearInputBuffer();
    printf("Name  : ");
    scanf("%[^\n]", newName);


    strcpy(patient->name, newName);
    putchar('\n');

    inputPhoneData(&patient->phone);
    printf("\n*** New patient record added ***\n");
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    char number[11];

    clearInputBuffer();
    printf("Phone Information\n"
        "-----------------\n"
    "How will the patient like to be contacted?\n");
    
    printf("1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
    "Selection: ");
    selection = inputIntRange(1, 4);

    if (selection == 4)
    {        
        strcpy(phone->description, "TBD");
    }
    else if (selection == 3)
    {
        strcpy(phone->description, "WORK");
        printf("\nContact: WORK\n");
        printf("Number : ");
        scanf("%s", number);
        strcpy(phone->number, number);
    }
    else if (selection == 2)
    {
        strcpy(phone->description, "HOME");
        printf("\nContact: HOME\n");
        printf("Number : ");
        scanf("%s", number);
        strcpy(phone->number, number);
    }
    else if (selection == 1)
    {
        strcpy(phone->description, "CELL");
        printf("\nContact: CELL\n");
        printf("Number : ");
        scanf("%s", number);
        strcpy(phone->number, number);
    }
    
}