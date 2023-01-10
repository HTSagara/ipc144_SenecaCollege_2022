/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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
// (Do not copy the below)
// ----------------------------------------------------------------------------

// ############################################################################
//
//  Assignment:  1 
//  Milestone:   1
//  Description: Main tester
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |    
// +---------------------------------------------------------+
//
//                         HOWEVER....
//
// In the development of your solution, you can...
// -----------------------------------------------
// - Comment the lines of code which call a function you have not yet developed
//   (See each tester function definition to see where you can do this)
// - Uncomment the lines of code previously commented to return the file to its
//   original state so you may fully test your solution.
// 
// #############################################################################pragma once

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// Check if the input is an integer
int inputInt();

// Check if the number is positive
int inputIntPositive();

// Check if the number is between the range
int inputIntRange(int min, int max);

//Verify if the character is in the array
char inputCharOption(char arr[]);

// Check the string's size
void inputCString(char arr[], int min, int max);

// Verify the phone number's format
void displayFormattedPhone(char phone[]);