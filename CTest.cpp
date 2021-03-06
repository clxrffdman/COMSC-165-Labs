// identification comments code block
// Calex Raffield
// Lab 1, Console Programming Basics
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
  int age;
  string name;
  double temp;
  string city;

  // identification output code block
  cout << "Calex Raffield\n\n";
  cout << "Lab 1, Console Programming Basics\n";
  cout << "Editor(s) used: Microsoft Visual Studio\n";
  cout << "Compiler(s) used: Microsoft Visual Studio\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  // output questions to the console and request/accept answers
  //age request and input
  string buf;
  cout << "Enter your age: ";
  cin >> buf; age = atoi(buf.c_str());
  cin.ignore(200, '\n');

  //name request and input
  cout << "Enter your name: ";
  getline(cin, name);
  
  //temperature request and input
  cout << "Enter the temperature outside right now (degrees F): ";
  cin >> buf; temp = atof(buf.c_str());
  cin.ignore(200, '\n');

  //city request and input
  cout << "What city are you in right now? ";
  getline(cin, city);

  //output paragraph containing answers that depend on inputs
  cout << name << " is " << age << " years old now, and will be " << age + 2 << " two years from now.\n";
  cout << "It's " << temp << " degrees in " << city << " -- that's ";

  //changing precision of float values
  cout.setf(ios::fixed);
  cout.precision(1); 

  //outputting temperature in degrees celcius
  cout << (temp - 32.0)*(5.0 / 9.0) << " degrees C.\n\n";

  //prompt user to exit program
  cout << "Press ENTER or RETURN to continue...";
  cin.get();
}