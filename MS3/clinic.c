/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
#include <string.h>

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    displayPatientTableHeader();



    for (i = 0; i < max; i++)
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
// (Copy your code from MS#2)
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


        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, MAX_PETS);
        }
        else if (selection == 2)
        {
            clearInputBuffer();
            printf("Search by phone number: ");
            scanf("%s", phoneNum);
            putchar('\n');
            displayPatientTableHeader();
            for (i = 0; i < max; i++)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i, emptyID, length = 0;

    emptyID = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > 0)
        {
            length++;
        }
    }

    for (i = 0; i < length + 1 && i < max; i++)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patientNum, index = 0;
    char answer, rmvName[NAME_LEN + 1] = { "000000000000000" };
    char rmvPhone[PHONE_LEN + 1] = { "0000000000" };
    char rmvPDecrip[PHONE_DESC_LEN + 1] = { "0000" };


    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    index = findPatientIndexByPatientNum(patientNum, patient, MAX_PETS);
    if (index >= 0)
    {
        putchar('\n');
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        do
        {
        scanf("%c", &answer);
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
        else
        {
            printf("ERROR: Character must be one of [yn]: ");
        }
        } while (answer != 'y' || answer != 'n');
    }
    else
    {
        clearInputBuffer();
        printf("\nERROR: Patient record not found!\n\n");

    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(const struct ClinicData data[])
{
    int i;
 

    displayScheduleTableHeader(&data, 1);
    sortedList(data->appointments, MAX_APPOINMENTS);
    for (i = 0; i < MAX_APPOINMENTS; i++)
    {
        displayScheduleData(&data->patients[i], &data->appointments[i], 1);
    }
    putchar('\n');
    clearInputBuffer();

}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(const struct ClinicData data[])
{
    int i, yearMin = 2024, yearMax = 2027, dayMin = 1, dayMax,
        yearInput = 0, monthInput = 0, dayInput = 0, index = 0,
        dateIndex;

    printf("Year        : ");
    yearInput = inputIntRange(yearMin, yearMax);
    printf("Month (1-12): ");
    monthInput = inputIntRange(1, 12);
    if (yearInput == 2025)
    {
        do
        {
            dayMax = 28;
            printf("Day (1-%d)  : ", dayMax);
            dayInput = inputIntRange(dayMin, dayMax);
        } while (dayInput < 1 || dayInput > dayMax);      
    }
    else
    {
        do
        {
            dayMax = 29;
            printf("Day (1-%d)  : ", dayMax);
            dayInput = inputIntRange(dayMin, dayMax);
        } while (dayInput < 1 || dayInput > dayMax);

    }
    clearInputBuffer();
    putchar('\n');

    for (i = 1; i < MAX_APPOINMENTS; i++)
    {
        if (data[i].appointments->date.year == yearInput && data[i].appointments->date.month == monthInput && data[i].appointments->date.day == dayInput)
        {
            dateIndex = i;
        }
    }
    
    displayScheduleTableHeader(&data[dateIndex].appointments->date, 0);
    for (i = 0; i < MAX_APPOINMENTS; i++)
    {
        if (data[i].appointments->date.year == yearInput && data[i].appointments->date.month == monthInput && data[i].appointments->date.day == dayInput)
        {
            displayScheduleData(data[i].patients, data[i].appointments, 0);
        }
        
    }
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct ClinicData* appointments, struct ClinicData* maxAppointments,
    struct ClinicData* patients, struct ClinicData* maxPatients)
{
    int i, numAppointments = 0, emptySpot = 0, inputPatient,
        yearInput = 0, monthInput = 0, dayInput = 0, yearMin = 2024, yearMax = 2027, dayMin = 1, dayMax = 31,
        hours, min, checkSlot;

    for (i = 0; i < MAX_APPOINMENTS; i++)
    {
        if (&appointments[i] > 0)
        {
            numAppointments++;
        }
    }
    if (numAppointments < MAX_APPOINMENTS)
    {
        for (i = 0; i < numAppointments + 1 && i < MAX_APPOINMENTS; i++)
        {
            if (patients->patients[i].patientNumber == '\0')
            {
                emptySpot = i;
            }
        }
        printf("Patient Number: ");
        scanf("%d", &inputPatient);
        printf("Year        : ");
        yearInput = inputIntRange(yearMin, yearMax);
        printf("Month (1-12): ");
        monthInput = inputIntRange(1, 12);
        printf("Day (1-31)  : ");
        dayInput = inputIntRange(dayMin, dayMax);
        do
        {
            printf("Hour (0-23)  : ");
            scanf("%d", &hours);
            printf("Minute (0-59): ");
            scanf("%d", &min);
            if (hours < FIRST_APPOINTMENT || hours > LAST_APPOINMENT)
            {
                printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", 
                    FIRST_APPOINTMENT, LAST_APPOINMENT, CONSULT_LENGTH);
            }
        } while (hours < FIRST_APPOINTMENT || hours > LAST_APPOINMENT);
        checkSlot = checkTimeSlot(hours, min, dayInput, monthInput, yearInput, appointments);
        if (checkSlot == 2)
        {
            printf("ERROR: Appointment timeslot is not available!");
        }
        else
        {
            printf("*** Appointment scheduled! ***");
        }
        clearInputBuffer();

    }
    else
    {
        printf("Full Schedule!!!");
        clearInputBuffer();
    }

}


// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct ClinicData* appointments, struct ClinicData* maxAppointments,
    struct ClinicData* patients, struct ClinicData* maxPatients)
{
    int index = 0, patientNum, inputYear, inputMonth, inputDay;
    int rmvDate[10] = {0000000000}, rmvTime[5] = {00000}, rmvPatientNumber = {0000};
    char answer;
    char rmvName[NAME_LEN + 1] = { "000000000000000" };
    char rmvPhone[PHONE_LEN + 1] = { "0000000000" };
    char rmvPDecrip[PHONE_DESC_LEN + 1] = { "0000" };

    printf("Patient Number: ");
    scanf("%d", &patientNum);
    index = findAppointmentIndexByPatientNum(patients, patientNum);
    if (index >= 0)
    {
        printf("Year        : ");
        scanf("%d", &inputYear);
        printf("Month (1-12): ");
        scanf("%d", &inputMonth);
        printf("Day (1-29)  : ");
        scanf("%d", &inputDay);
        clearInputBuffer();

        printf("Name  : %s", appointments[index].patients->name);
        printf("Number: %d", appointments[index].patients->patientNumber);
        printf("Phone : %s", appointments[index].patients->phone);
        printf("Are you sure you want to remove this appointment (y,n): ");
        scanf("%c", &answer);
        if (answer == 'y');
        {
            appointments[index].patients->patientNumber = 0;
            strcpy(appointments[index].appointments->patient.name, rmvName);
            strcpy(appointments[index].appointments->patient.phone.number, rmvPhone);
            strcpy(appointments[index].appointments->patient.phone.description, rmvPDecrip);
            strcpy(appointments[index].appointments->date.year, 0000);
            strcpy(appointments[index].appointments->date.month, 00);
            strcpy(appointments[index].appointments->date.day, 00);
            strcpy(appointments[index].appointments->time.hour, 00);
            strcpy(appointments[index].appointments->time.min, 00);
            printf("\nAppointment record has been removed!\n\n");
        }

    }
    else
    {
        printf("ERROR: Patient record not found!");
    }
    clearInputBuffer();
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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

//Find the appointment array index by patient number-----------------------------------------------------------------------------------------------------------------------------
int findAppointmentIndexByPatientNum(struct ClinicData data[], int patientNumber)
{
    int result = -1, i;
    for (i = 0; i < MAX_APPOINMENTS; i++)
    {
        if (patientNumber == data[i].appointments->patient.patientNumber)
        {
            result = i;
        }
    }

    return result;
}

//Find date index------------------------------------------------------------------------------------------------------------------------------------------------------------------
int findAppointmentIndexByDate(struct Appointment appoint[], int year, int month, int day)
{
    int i, result = 0;
    for (i = 0; i < MAX_APPOINMENTS; i++)
    {
        printf("%d-%d-%d\n", appoint[i].date.year, appoint[i].date.month, appoint[i].date.day);
        if (appoint[i].date.year == year && appoint[i].date.month == month && appoint[i].date.day == day)
        {
            result = i;
        }
    }

    return result;
}

//Sort the Appointments for the Date and Time -----------------------------------------------------------------------------------------------------------------------------------
void sortedList(struct Appointment appoint[], int itemCount)
{
    int i, j, minIdx;
    struct Appointment temp;

    for (i = 0; i < itemCount; i++)
    {
        minIdx = i;

        for (j = i + 1; j < itemCount; j++)
        {
            if (compareAppoint(appoint[j], appoint[minIdx]) == -1)
            {
                minIdx = j;
            }
        }

        if (minIdx != i)
        {
            temp = appoint[i];
            appoint[i] = appoint[minIdx];
            appoint[minIdx] = temp;
        }
    }
    
}

int compareAppoint(struct Appointment appoint, struct Appointment appoint1)
{
 
        if (appoint.date.year == appoint1.date.year)
        {
            if (appoint.date.month == appoint1.date.month)
            {
                if (appoint.date.day == appoint1.date.day)
                {
                    if (appoint.time.hour == appoint1.time.hour)
                    {
                        if (appoint.time.min == appoint1.time.min)
                        {
                            return 0;
                        }
                        else if (appoint.time.min > appoint1.time.min)
                        {
                            return 1;
                        }
                        else
                        {
                            return -1;
                        }
                        return 0;
                    }
                    else if (appoint.time.hour > appoint1.time.hour)
                    {
                        return 1;
                    }
                    else
                    {
                        return -1;
                    }
                }
                else if (appoint.date.day > appoint1.date.day)
                {
                    return 1;
                }
                else
                {
                    return -1;
                }
            }
            else if (appoint.date.month > appoint1.date.month)
            {
                return 1;
            }
            else
            {
                return -1;
            }
            return 0;
        }
        else if (appoint.date.year > appoint1.date.year)
        {
            return 1;
        }
        else
        {
            return -1;
        }
}


//Check if the time slot is free-----------------------------------------------------------------------------------------------------------------------------------------------
int checkTimeSlot(int inputHours, int inputMin, int inputDay, int inputMonth, int inputYear,
    struct ClinicData data[])
{
    int i, result = 0;

    for (i = 0; i < MAX_APPOINMENTS; i++)
    {
        if (inputYear == data[i].appointments->date.year && 
            inputMonth == data[i].appointments->date.month &&
            inputDay == data[i].appointments->date.day)
        {
            result++;
        }
        if (inputHours == data[i].appointments->time.hour && 
            inputMin == data[i].appointments->time.min)
        {
            result++;
        }
    }

    return result;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int nrecs = 0, i;

    FILE* fp = fopen(datafile, "r");

    if (fp != NULL)
    {

        for (i = 0; i < max; i++) // %[^|] --> used to assign the string until the char '|' in the array
        {
            fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
                &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);
            nrecs++;
        }

        fclose(fp);
        fp = NULL;
    }
    else
    {
        printf("ERROR: Unable to open file for reading.\n");
    }
    return nrecs;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i = 0;
    char ch;

    FILE* fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d\n", 
            &appoints[i].patient.patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) == 6)
        {
           i++;
        }

        fclose(fp);
        fp = NULL;
    }
    else
    {
        printf("ERROR: Unable to open file for reading.\n");
    }

    return i;
}

//Sort date