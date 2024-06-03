/*
* Class: CMSC140 CRN 22867
* Instructor: Professor Grigoriy A. Grinberg
* Project 5
* Computer/Platform/Compiler: Macbook, Xcode.
* Description: "Write a program that simulates a magic square using 3 one dimensional parallel arrays of integer type."
* Due Date: 12/06/2021
* I pledge that I have completed the programming assignment independently.
  I have not copied the code from a student or any source.
  I have not given my code to any student.
  Print your Name here: Dolev Peleg
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// *Global constants*
const int ROWS = 3;  // The number of rows in the array
const int COLS = 3;  // The number of columns in the array
const int MIN = 1;  // The value of the smallest number
const int MAX = 9;  // The value of the largest number
const int FIRST_COL = 0; // The first column
const int SECOND_COL = 1; // The second colmun
const int THIRD_COL = 2; // The third column
const int FIRST_ROW = 0; // The first row
const int SECOND_ROW = 1; // The second row
const int THIRD_ROW = 2; // The third row
const string PROGRAMMER_NAME = "Dolev Peleg", DUE_DATE = "12/06/2021"; // My name and the due date
const int PROJECT_NUMBER = 5;

// * Function prototypes *
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); // Displays wheather the user's input is a magic square, based on the
                                                                                //  functions: checkRange, checkUnique, checkRowSum, checkColSum, and checkDiagSum
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max); // Checks if the user's numbers are in the range of 1-9
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); // Checks if each one of the user's numbers are unique
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); // Checks if all the rows of the square made by the user's numbers are equal
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); // Checks if all the columns of the square made by the user's numbers are equal
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); // Checks if all the diagonals of the square made by the user's numbers are equal
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); // Fills each array with 3 of the user's numbers
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size); // Displays the user's arrays as a sqaure made of 3 rows

// * The main function*
int main()
{
    string userTryAgain; // A variable that will test if the user wants to try again
    int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS]; //  The arrays that correspond to the rows of the Magic Square *

    do // A loop that will repeat as long as the user input is "y" or "yes". It will iterate at least once
    {
        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS); // Filling the arrays
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS); // Displaying the arrays as 3 rows
        cout << endl;

        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS) == true) // Using the function isMagicSquare to test if the user input is a magic square
        {
            cout << "This is a Lo Shu magic square";
        }
        else
        {
            cout << "This is not a Lo Shu magic square";
        }
        cout << endl << endl << endl;
        cout << "Do you want to try again? "; // Prompting the user to try again
        cin >> userTryAgain;
    } while (userTryAgain == "y" || userTryAgain == "yes");

    cout << endl << endl << endl;
    cout << "Name: " << PROGRAMMER_NAME << endl; // Displaying my name
    cout << "Project #: " << PROJECT_NUMBER << endl; // Displaying the project number
    cout << "Due Date: " << DUE_DATE << endl; // Displaying the due date
    return 0;
}
// Function definitions
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) // explained in the function's prototype above
{
    // * Creating a loop to prompt and get the numbers for each row from the user *
    for (int rowNumber = FIRST_ROW; rowNumber < size; rowNumber++)
    {
        for (int colNumber = FIRST_COL; colNumber < size; colNumber++)
        {
            cout << "Enter the number for row " << rowNumber << " and column " << colNumber << " : ";
            if (rowNumber == FIRST_ROW)
            {
                cin >> arrayRow1[colNumber]; // filling the first row
            }
            else if (rowNumber == SECOND_ROW)
            {
                cin >> arrayRow2[colNumber]; // filling the second row
            }
            else if (rowNumber == THIRD_ROW)
            {
                cin >> arrayRow3[colNumber]; // filling the third row
            }
        }

    }
}

void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) // explained in the function's prototype above
{
    // * Creating a loop to display the numbers entered by the user as 3 rows *
    for (int rowNumber = FIRST_ROW; rowNumber < size; rowNumber++)
    {
        for (int colNumber = FIRST_COL; colNumber < size; colNumber++)
        {
            switch (rowNumber)
            {
            case FIRST_ROW: cout << arrayRow1[colNumber] << " "; // displaying the first row
                if (colNumber == THIRD_COL)
                {
                    cout << endl;
                }
                break;
            case SECOND_ROW: cout << arrayRow2[colNumber] << " "; // displaying the second row
                if (colNumber == THIRD_COL)
                {
                    cout << endl;
                }
                break;
            case THIRD_ROW: cout << arrayRow3[colNumber] << " "; // displaying the third row
                break;
            }
        }
    }
}

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) // explained in the function's prototype above
{
    bool magicSquare;
    if (checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) == false ||
        checkUnique(arrayRow1, arrayRow2, arrayRow3, size) == false ||
        checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) == false ||
        checkColSum(arrayRow1, arrayRow2, arrayRow3, size) == false ||
        checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size) == false)
    {
        magicSquare = false; // If any one of the boolean functions return false, this function will return false
    }
    else
    {
        magicSquare = true;
    }
    return magicSquare;
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) // explained in the function's prototype above
{
    for (int colNumber = FIRST_COL; colNumber < size; colNumber++)
    {
        if (arrayRow1[colNumber] < MIN || arrayRow1[colNumber] > MAX || // Checking if the first row numbers are in range
            arrayRow2[colNumber] < MIN || arrayRow2[colNumber] > MAX || // Checking if the second row numbers are in range
            arrayRow3[colNumber] < MIN || arrayRow3[colNumber] > MAX) // Checking if the third row numbers are in range
        {
            return false; // If any of the number are not in the range, returns false
        }
    }
    return true;
}

bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) // explained in the function's prototype above
{
    const int ARRAYS_SIZES_SUM = COLS + COLS + COLS; // A constant that holds the sizes of all 3 arrays combined
    int allNumbers[ARRAYS_SIZES_SUM]; // creating an array to hold all the numbers, can hold values fromm all three arrays
    for (int counter = 0; counter < size; counter++)
    {
        allNumbers[counter] = arrayRow1[counter]; // adding the values of the first array
        allNumbers[counter + size] = arrayRow2[counter]; // adding the values of the second array
        allNumbers[counter + size + size] = arrayRow3[counter]; // adding the values of the third array
    }

    for (int counter2 = 0; counter2 < MAX; counter2++)
    {
        for (int counter = counter2 + 1; counter < MAX; counter++) // checking for each number if it is equal to any of the numbers that are after it in the array
        {
            if (allNumbers[(counter2)] == allNumbers[counter])
            {
                return false; // if a number is equal to any of the numbers after it, returns false
            }
        }
    }
    return true;
}

bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) // explained in the function's prototype above
{
    int firstRowSum = 0, secondRowSum = 0, thirdRowSum = 0; // Variables that hold the sum of each row
    for (int colNumber = FIRST_COL; colNumber < size; colNumber++) // A loop that store the value of each row in the variables
    {
        firstRowSum += arrayRow1[colNumber]; // First row sum
        secondRowSum += arrayRow2[colNumber]; // Second row sum
        thirdRowSum += arrayRow3[colNumber]; // Third row sum
    }

    // * If any of the rows' sums are not equal, this function returns false *
    if (firstRowSum != secondRowSum ||
        secondRowSum != thirdRowSum ||
        firstRowSum != thirdRowSum)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) // explained in the function's prototype above
{
    int firstColSum = 0, secondColSum = 0, thirdColSum = 0; // Variables that hold the sum of each column
    for (int colNumber = FIRST_COL; colNumber < size; colNumber++) // A loop that store the value of each column in the variables
    {
        switch (colNumber)
        {
        case FIRST_COL:  firstColSum += arrayRow1[colNumber] + arrayRow2[colNumber] + arrayRow3[colNumber]; // First column sum
            break;
        case SECOND_COL: secondColSum += arrayRow1[colNumber] + arrayRow2[colNumber] + arrayRow3[colNumber]; // Second column sum
            break;
        case THIRD_COL: thirdColSum += arrayRow1[colNumber] + arrayRow2[colNumber] + arrayRow3[colNumber]; // Third column sum
        }
    }

    // * If any of the columns' sums are not equal, this function returns false *
    if (firstColSum != secondColSum ||
        secondColSum != thirdColSum ||
        firstColSum != thirdColSum)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) // explained in the function's prototype above
{
    int firstDiagSum = 0, secondDiagSum = 0; // Variables that hold the sum of each diagonal
    for (int colNumber = 0; colNumber < size; colNumber++) // A loop that store the value of each diagonal in the variables
    {
        switch (colNumber)
        {
        case FIRST_COL: firstDiagSum += arrayRow1[colNumber];
            secondDiagSum += arrayRow3[colNumber];
            break;
        case SECOND_COL: firstDiagSum += arrayRow2[colNumber];
            secondDiagSum += arrayRow2[colNumber];
            break;
        case THIRD_COL: firstDiagSum += arrayRow3[colNumber];
            secondDiagSum += arrayRow1[colNumber];
            break;
        }
    }

    // * If the diagonals' sums are not equal, this function returns false *
    if (firstDiagSum != secondDiagSum)
    {
        return false;
    }
    else
    {
        return true;
    }
}