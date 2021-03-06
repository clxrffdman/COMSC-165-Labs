// identification comments code block
// Calex Raffield
// Lab 4: Course Objects With Serializations
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

//struct for a course object
struct Course
{
  //properties of Course struct
  string name = "?";
  int year;
  int units;
  string grade = "?";

};

void SerializeDown(Course a[], int capacity);
//void SerializeDown(Course a[], int capacity);
void OutputTable(Course a[], int b);
//void OutputTable(Course a[]);
Course InputCourse();
//Course InputCourse();

void SerializeDown(Course a[], int capacity);

int main()
{

  // identification output code block
  cout << "Calex Raffield\n\n";
  cout << "Lab 4: Course Objects With Serializations\n";
  cout << "Editor(s) used: Microsoft Visual Studio\n";
  cout << "Compiler(s) used: Microsoft Visual Studio\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  //array of courses and current quantity of courses, which starts at 0.
  Course courseArray[100];
  int courseQuantity = 0;

  // serialize up
  ifstream fin; // declares an object fin
  fin.open("courses.txt");
  if (fin.good()) {
    fin >> courseQuantity;
    for (int i = 0; i < courseQuantity; i++) {
      Course subCourse;
      fin.ignore(1000, 10);
      getline(fin, subCourse.name);
      fin >> subCourse.year;
      fin.ignore(1000, 10);
      fin >> subCourse.units;
      fin.ignore(1000, 10);
      fin >> subCourse.grade;
      courseArray[i] = subCourse;
    }
  }
  
  fin.close(); // done with the fill

  //while loop which continues to run until user chooses to stop
  for(int i = 0; i < 100; i++){
    
    //outputs a table of the Course objects in courseArray and courseQuantity.
    OutputTable(courseArray,courseQuantity);

    Course input = InputCourse();
    //checks if user typed in Q to quit
    if (input.name == "q" || input.name == "Q") {
      i = 100;
    }
    else {
      //if user didn't type Q, add input to the courseArray and serialize down.
      courseArray[courseQuantity] = input;
      courseQuantity++;

      SerializeDown(courseArray, courseQuantity);
    }

  }

}

/**************************************************************************************************************************************************
* Purpose: Outputs the data of all courses taken as input in a table.
* Parameters:
*     Arguments: Course a[], int quantity.
*
*     Return: N/A (void function).
***************************************************************************************************************************************************/
void OutputTable(Course a[], int quantity) {
  //Column widths of 10, 5, 7, 5, and 11 with gaps of 1 before each column. 
  cout << "    Name     Year   Units   Grade \n";
  cout << " ---------- ------ ------- -------\n";

  for (int i = 0; i < quantity; i++) {

    //Begin appropriately spacing and outputting data of current Course i.
    cout.width(11);
    cout << a[i].name;
    cout << " ";

    cout.width(6);
    cout << a[i].year;
    cout << " ";

    cout.width(7);
    cout << a[i].units;
    cout << " ";

    cout.width(7);
    cout << a[i].grade;
    cout << " ";

    //Moves onto next line to output data for next Course.
    cout << "\n";
  }
  
}

/**************************************************************************************************************************************************
* Purpose: Returns a Course based on user input (name, year, units, grade).
* Parameters:
*     Arguments: N/A
*
*     Return: Course
***************************************************************************************************************************************************/
Course InputCourse() {

  //Course variable to be used as return value, and string buffer variable.
  Course returnValue;
  string buf;

  //prompt user for name of course
  cout << "\nEnter a name for this Course [Q or q to exit]:\n>";

  getline(cin, returnValue.name);

  //if user types in Q or q, skip the next couple questions
  if (returnValue.name == "q" || returnValue.name == "Q") {

    //prompt user to exit program
    cout << "Press ENTER or RETURN to continue...";
    cin.get();
    
    
  }
  else {

    //Under assumption of error/incorrect input check
    cout << "What year are you taking " << returnValue.name << "?: (enter as a single number, example: 2016)\n>";
    cin >> buf; returnValue.year = atoi(buf.c_str()); cin.ignore(1000, 10);

    cout << "How many units is " << returnValue.name << ": (enter as a single number, example: 10)\n>";
    cin >> buf; returnValue.units = atoi(buf.c_str()); cin.ignore(1000, 10);

    cout << "What was your letter grade for " << returnValue.name << ": (enter as a single letter, or nothing if course is in progress)\n>";
    getline(cin, returnValue.grade);
    if (returnValue.grade == "") {
      returnValue.grade = "?";
    }

    cout << "\nInput Recieved.\n";
  }

  //return the Course filled out with user input.
  return returnValue;
}

/**************************************************************************************************************************************************
* Purpose: Serialize down the size and Course array data into a .txt file called courses.txt.
* Parameters:
*     Arguments: Course a[], int capacity
*
*     Return: N/A (void).
***************************************************************************************************************************************************/
void SerializeDown(Course a[], int capacity) {

  // serialize down
  ofstream fout; // declares an object of type "ofstream"
  fout.open("courses.txt");
  //outputs the number of courses into the first line of the file.
  fout << capacity << "\n";
  for (int i = 0; i < capacity; i++) {
    
    //output to file the name, year, units, and grade of the Course i within Course[] a.
    fout << a[i].name << "\n" << a[i].year << "\n" << a[i].units << "\n" << a[i].grade << "\n";
  }

  fout.close(); // done with the file
}


