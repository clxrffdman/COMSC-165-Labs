// identification comments code block
// Calex Raffield
// Lab 2: Making Exact Change
// Editor(s) used: Microsoft Visual Studio
// Compiler(s) used: Microsoft Visual Studio

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <string>
using std::getline;
using std::string;

#include <cstdlib>


int main()
{
  //variable declaration
  double cost;
  double paid;
  double change;
  bool properInput = false;

  //variables storing amount of money denominations to return as change. 
  int hundred = 0;
  int fifty = 0;
  int twenty = 0;
  int ten = 0;
  int five = 0;
  int one = 0;
  int fiftyCent = 0;
  int twentyFiveCent = 0;
  int tenCent = 0;
  int fiveCent = 0;
  int oneCent = 0;

  // identification output code block
  cout << "Calex Raffield\n\n";
  cout << "Lab 2: Making Exact Change\n";
  cout << "Editor(s) used: Microsoft Visual Studio\n";
  cout << "Compiler(s) used: Microsoft Visual Studio\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  // output request to user for purchase amount and amount tendered. Only progresses further when input is valid.
  while (!properInput) {

    string buf;
    cout << "Enter the purchase amount, and the amount tendered, seperated by a space.\n(Example: For a purchase of $1.50 and tendering of $3.00, input '1.50 3.00' without the quote marks.): ";
    //assign inputs to their respective variables.
    cin >> buf; cost = atof(buf.c_str());
    cin >> buf; paid = atof(buf.c_str());

    if (cost < paid && cost > 0 && paid > 0) {
      properInput = true;
    }
    else
    {
      if (cost > paid) {
        cout << "\nInvalid input: Full purchase amount not paid, try again.\n\n";
      }
      else {
        cout << "\nInvalid input: try again.\n\n";
      }
      
      properInput = false;
    }
  }

  //the change is set to being the amount tendered minus the cost of the item.
  change = paid - cost;

  //changing precision of float values for change output.
  cout.setf(ios::fixed);
  cout.precision(2);

  cout << "\nYour change was $" << change << "\n";

  //while loops to divide the change from highest denomination to lowest (to minimize number of bills/coins provided)
  while (change > 99.999) {
    change -= 100;
    hundred++;
  }

  while (change > 49.999) {
    change -= 50;
    fifty++;
  }

  while (change > 19.999) {
    change -= 20;
    twenty++;
  }

  while (change > 9.999) {
    change -= 10;
    ten++;
  }

  while (change > 4.999) {
    change -= 5;
    five++;
  }

  while (change > 0.999) {
    change -= 1;
    one++;
  }
  
  while (change > 0.499) {
    change -= 0.5;
    fiftyCent++;
  }

  while (change > 0.249) {
    change -= 0.25;
    twentyFiveCent++;
  }

  while (change > 0.099) {
    change -= 0.1;
    tenCent++;
  }

  while (change > 0.049) {
    change -= 0.05;
    fiveCent++;
  }

  while (change > 0.009) {
    change -= 0.01;
    oneCent++;
  }

  //outputting list of bill/coin quantities that add up to change. 
  if (hundred > 0) {
    cout << hundred << " $100 bill";
    if (hundred > 1)
      cout << "s";
    cout << "\n";
  }

  if (fifty > 0) {
    cout << fifty << " $50 bill";
    if (fifty > 1)
      cout << "s";
    cout << "\n";
  }

  if (twenty > 0) {
    cout << twenty << " $20 bill";
    if (twenty > 1)
      cout << "s";
    cout << "\n";
  }

  if (ten > 0) {
    cout << ten << " $10 bill";
    if (ten > 1)
      cout << "s";
    cout << "\n";
  }

  if (five > 0) {
    cout << five << " $5 bill";
    if (five > 1)
      cout << "s";
    cout << "\n";
  }

  if (one > 0) {
    cout << one << " $1 bill";
    if (one > 1)
      cout << "s";
    cout << "\n";
  }

  if (fiftyCent > 0) {
    cout << fiftyCent << " 50-cent coin";
    if (fiftyCent > 1)
      cout << "s";
    cout << "\n";
  }

  if (twentyFiveCent > 0) {
    cout << twentyFiveCent << " 25-cent coin";
    if (twentyFiveCent > 1)
      cout << "s";
    cout << "\n";
  }

  if (tenCent > 0) {
    cout << tenCent << " 10-cent coin";
    if (tenCent > 1)
      cout << "s";
    cout << "\n";
  }

  if (fiveCent > 0) {
    cout << fiveCent << " 5-cent coin";
    if (fiveCent > 1)
      cout << "s";
    cout << "\n";
  }

  if (oneCent > 0) {
    cout << oneCent << " 1-cent coin";
    if (oneCent > 1)
      cout << "s";
    cout << "\n";
  }
  cout << "\n";

  cin.ignore(200, '\n');
  //prompt user to exit program
  cout << "Press ENTER or RETURN to continue...";
  cin.get();
}