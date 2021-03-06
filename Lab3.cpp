// identification comments code block
// Calex Raffield
// Lab 3: Student Objects With Serializing Down
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

struct Student
{
  string name;
  int age;
  int grade;
  double gpa;
  double height;

};

void SerializeDown(Student inputOne, Student inputTwo, Student inputThree);
//void SerializeDown(Student input);
void OutputTable(Student inputOne, Student inputTwo, Student inputThree);
//void SerializeDown(Student input);
Student InputStudent();
//Student InputStudent();

int main()
{


  // identification output code block
  cout << "Calex Raffield\n\n";
  cout << "Lab 3: Student Objects With Serializing Down\n";
  cout << "Editor(s) used: Microsoft Visual Studio\n";
  cout << "Compiler(s) used: Microsoft Visual Studio\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  //Three students that will be filled with user input.
  Student a;
  Student b;
  Student c;

  //InputStudent() will return a student struct based on user input
  a = InputStudent();
  b = InputStudent();
  c = InputStudent();

  //OutputTable() will output an organized and aligned table based on three Student inputs. 
  OutputTable(a, b, c);

  //SerializeDown() will serialize the data of the three Students into a .txt file called input.txt.
  SerializeDown(a, b, c);
}

/**************************************************************************************************************************************************
* Purpose: Serializes the data of all students into a .txt file called input.txt.
* Parameters:
*     Arguments: Student inputOne, Student inputTwo, Student inputThree.
*
*     Return: N/A (void function).
***************************************************************************************************************************************************/
void SerializeDown(Student inputOne, Student inputTwo, Student inputThree) {



  
  ofstream fout; // declares an object of type "ofstream"
  //Opens a file called "input.txt".
  fout.open("input.txt");
  //Outputs the values from each Student one at a time.
  fout << inputOne.name << "\n" << inputOne.age << "\n" << inputOne.grade << "\n" << inputOne.gpa << "\n" << inputOne.height << "\n";
  fout << inputTwo.name << "\n" << inputTwo.age << "\n" << inputTwo.grade << "\n" << inputTwo.gpa << "\n" << inputTwo.height << "\n";
  fout << inputThree.name << "\n" << inputThree.age << "\n" << inputThree.grade << "\n" << inputThree.gpa << "\n" << inputThree.height << "\n";
  fout.close(); // Finished with the file.

}

/**************************************************************************************************************************************************
* Purpose: Outputs the data of three students taken as input in a table.
* Parameters:
*     Arguments: Student inputOne, Student inputTwo, Student inputThree.
*
*     Return: N/A (void function).
***************************************************************************************************************************************************/
void OutputTable(Student inputOne, Student inputTwo, Student inputThree) {

  //Column widths of 10, 5, 7, 5, and 11 with gaps of 1 before each column. 
  cout << "    Name     Age   Grade   GPA   Height(m)\n"; 
  cout << " ---------- ----- ------- ----- -----------\n";

  //Begin appropriately spacing and outputting data of Student inputOne.
  cout.width(11);
  cout << inputOne.name;
  cout << " ";

  cout.width(5);
  cout << inputOne.age;
  cout << " ";

  cout.width(7);
  cout << inputOne.grade;
  cout << " ";

  cout.width(5);
  cout << inputOne.gpa;
  cout << " ";

  cout.width(11);
  cout << inputOne.height;
  cout << " ";

  //Moves onto next line to output data for Student inputTwo.
  cout << "\n";

  cout.width(11);
  cout << inputTwo.name;
  cout << " ";

  cout.width(5);
  cout << inputTwo.age;
  cout << " ";

  cout.width(7);
  cout << inputTwo.grade;
  cout << " ";

  cout.width(5);
  cout << inputTwo.gpa;
  cout << " ";

  cout.width(11);
  cout << inputTwo.height;
  cout << " ";

  //Moves onto next line to output data for Student inputThree.
  cout << "\n";

  cout.width(11);
  cout << inputThree.name;
  cout << " ";

  cout.width(5);
  cout << inputThree.age;
  cout << " ";

  cout.width(7);
  cout << inputThree.grade;
  cout << " ";

  cout.width(5);
  cout << inputThree.gpa;
  cout << " ";

  cout.width(11);
  cout << inputThree.height;
  cout << " ";
}

/**************************************************************************************************************************************************
* Purpose: Takes in user input(name, age, grade level, gpa, and height) and assigns values to a Student struct.
* Parameters:
*     Arguments: N/A
*
*     Return: Student
***************************************************************************************************************************************************/
Student InputStudent() {

  Student returnValue;
  string buf;

  //prompt user for cost and paid amounts


  cout << "\nEnter a name for this student:\n>";

  getline(cin, returnValue.name);

  cout << "Enter " << returnValue.name << "'s age:\n>";
  cin >> buf; returnValue.age = atoi(buf.c_str()); cin.ignore(1000, 10);

  cout << "Enter " << returnValue.name << "'s grade level:\n>";
  cin >> buf; returnValue.grade = atoi(buf.c_str());

  cout << "Enter " << returnValue.name << "'s GPA:\n>";
  cin >> buf; returnValue.gpa = atof(buf.c_str());

  cout << "Enter " << returnValue.name << "'s height in meters:\n>";
  cin >> buf; returnValue.height = atof(buf.c_str()); cin.ignore(1000, 10);

  cout << "\nInput Recieved.\n";

  return returnValue;

}

