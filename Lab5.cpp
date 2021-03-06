// identification comments code block
// Calex Raffield
// Lab 5: Tracking Expenses with Arrays
// Editor(s) used: Microsoft Visual Studio
// Compiler(s) used: Microsoft Visual Studio

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <string>
using std::getline;
using std::string;

#include <cstdlib>

//struct for a Expense object
struct Expense
{
  //properties of Expense struct
  string description = "?";
  double amount;

};

void DisplayExpenses(Expense expenses[], int quantity);
//void DisplayExpenses(Expense expenses[], int quantity);
int DisplayOptions();
//int DisplayOptions();
Expense InputExpense();
//Expense InputExpense();
string toLowerCase(string input);
//string toLowerCase(string input);
void SearchWordDisplay(Expense expenses[], int quantity);
//void SearchWordDisplay(Expense expenses[], int quantity);
void SearchAmountDisplay(Expense expenses[], int quantity);
//void SearchAmountDisplay(Expense expenses[], int quantity);

int main()
{

  // identification output code block
  cout << "Calex Raffield\n\n";
  cout << "Lab 5: Tracking Expenses with Arrays\n";
  cout << "Editor(s) used: Microsoft Visual Studio\n";
  cout << "Compiler(s) used: Microsoft Visual Studio\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  //contains all expenses.
  Expense expenseArray[100];
  //quantity of total expenses. 
  int expenseQuantity = 0;

  //Prompts menu and takes in input 100 times maximum.
  for (int i = 0; i < 100; ) {
    
    //Displays menu options to user and recieves their option as an integer.
    int inputNumber = DisplayOptions();

    if (inputNumber == 1) {
      //Displays all expenses.
      DisplayExpenses(expenseArray, expenseQuantity);
    }
    else if (inputNumber == 2) {
      //Adds an expense to the array of expenses, based on user input.
      expenseArray[expenseQuantity] = InputExpense();
      expenseQuantity++;
      i++;
    }
    else if (inputNumber == 3) {
      //Prompts a string user input and prints a table based on input.
      SearchWordDisplay(expenseArray, expenseQuantity);
    }
    else if (inputNumber == 4) {
      //Prompts a double user input and prints a table based on input.
      SearchAmountDisplay(expenseArray, expenseQuantity);
    }
    else if (inputNumber == 5) {
      //exits program and ends for loop.
      cout << "\nProgram Exiting.\n";
      i = 100;
    }
    else {
      cout << "\nERROR: INVALID INPUT.";
    }

  }

  //exit prompt
  cout << "Press ENTER or RETURN to continue...";
  cin.get();

}

/**************************************************************************************************************************************************
* Purpose: Displays all Expenses in the array provided as input.
* Parameters:
*     Arguments: Expense expenses[], int quantity
*
*     Return: N/A (void function).
***************************************************************************************************************************************************/
void DisplayExpenses(Expense expenses[], int quantity) {

  cout << "Expenses:\n";

  if (quantity <= 0) {
    //shows error message if there is no expenses available.
    cout << "\nThere are no expenses available.\n";
  }
  else {
    //Displays data for all Expenses in expenses[] one at a time.
    for (int i = 0; i < quantity; i++) {
      cout << "Amount(" << expenses[i].amount << ")  Description: (" << expenses[i].description << ")\n";
    }
  }
}

/**************************************************************************************************************************************************
* Purpose: Displays menu options to the user and returns an integer based on user input.
* Parameters:
*     Arguments: N/A
*
*     Return: int
***************************************************************************************************************************************************/
int DisplayOptions() {

  int returnValue = -1;
  string buf;

  cout << "\n1. Show All\n2. Spend\n3. Search expenses containing this string\n4. Search expenses with greater than or equal to this amount\n5. Exit\n>";
  cin >> buf; returnValue = atoi(buf.c_str()); cin.ignore(1000, 10);
  return returnValue;

}

/**************************************************************************************************************************************************
* Purpose: Returns an Expense based on user input.
* Parameters:
*     Arguments: N/A
*
*     Return: Expense
***************************************************************************************************************************************************/
Expense InputExpense() {

  //Course variable to be used as return value, and string buffer variable.
  Expense returnValue;
  string buf;
  bool validInput = false;

  //prompt user for name of course
  while (!validInput) {

    cout << "\nEnter a description for this Expense:\n>";

    getline(cin, returnValue.description);

    //displays error message if input is not valid.
    if (returnValue.description == "") {
      cout << "\nInvalid Input, try again.\n";
    }
    else {
      validInput = true;
    }

  }
  
  validInput = false;

  //prompt user for cost of expense until input is valid.
  while (!validInput) {
    cout << "What amount?: (enter as a decimal, example: 20.50)\n>";
    cin >> buf; returnValue.amount = atof(buf.c_str()); cin.ignore(1000, 10);
    if (returnValue.amount <= 0) {
      cout << "\nInvalid Input, try again.\n";
    }
    else {
      validInput = true;
    }

  }

  //input verification prompt
  cout << "\nInput Recieved.\n";
  
  //return the Course filled out with user input.
  return returnValue;
}

/**************************************************************************************************************************************************
* Purpose: Returns a version of the string input in lowercase.
* Parameters:
*     Arguments: string aCppString
*
*     Return: string
***************************************************************************************************************************************************/
string toLowerCase(string aCppString)
{
  int n = aCppString.length();
  //changes every character to lowercase one at a time
  for (int i = 0; i < n; i++)
    aCppString[i] = tolower(aCppString[i]);
  //returns new string with all letters lowercase
  return aCppString;
}

/**************************************************************************************************************************************************
* Purpose: Searches and displays Expenses based on a string user input.
* Parameters:
*     Arguments: Expense expenses[], int quantity
*
*     Return: N/A (void function).
***************************************************************************************************************************************************/
void SearchWordDisplay(Expense expenses[], int quantity) {

  //array of matching expenses and quantity
  Expense matchArray[100];
  int matchQuantity = 0;

  string input;
  bool validInput = false;

  //Prompts for a search word until the string provided is valid (not empty)
  while (!validInput) {

    cout << "\nInput search word:\n>";
    getline(cin, input);

    if (input == "") {
      cout << "\nInvalid Input, try again.\n";
    }
    else {
      //stops the while-loop
      validInput = true;
    }

  }
  
  //converts the string input to lower case
  input = toLowerCase(input);

  //checks every expense description in expenses[] for the input word and adds all matching expenses from expenses[] into matchArray[]
  for (int i = 0; i < quantity; i++) {

    int index;
    index = toLowerCase(expenses[i].description).find(input);
    
    if (index != string::npos) {
      matchArray[matchQuantity] = expenses[i];
      matchQuantity++;
    }
  }

  //displays all matching expenses.
  DisplayExpenses(matchArray, matchQuantity);

}

/**************************************************************************************************************************************************
* Purpose: Searches and displays Expenses based on a double user input.
* Parameters:
*     Arguments: Expense expenses[], int quantity
*
*     Return: N/A (void function).
***************************************************************************************************************************************************/
void SearchAmountDisplay(Expense expenses[], int quantity) {

  //array of matching expenses and quantity
  Expense matchArray[100];
  int matchQuantity = 0;

  string buf;
  double input;
  bool validInput = false;

  //Prompts for a search word until the double provided is valid (not less than or = to 0)
  while (!validInput) {

    cout << "\nInput search amount: (Will return expenses greater thanor equal to this amount)\n>";
    cin >> buf; input = atof(buf.c_str()); cin.ignore(1000, 10);

    if (input <= 0) {
      cout << "\nInvalid Input, try again.\n";
    }
    else {
      //stops the while-loop
      validInput = true;
    }
  }

  //adds all matching expenses from expenses[] into matchArray[]
  for (int i = 0; i < quantity; i++) {

    if (expenses[i].amount >= input) {
      matchArray[matchQuantity] = expenses[i];
      matchQuantity++;
    }
  }

  //displays all matching expenses
  DisplayExpenses(matchArray, matchQuantity);

}