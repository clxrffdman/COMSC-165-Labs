// identification comments code block
// Calex Raffield
// Lab 6: Movies Linked List
// Editor(s) used: Microsoft Visual Studio
// Compiler(s) used: Microsoft Visual Studio

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <iomanip>

#include <algorithm>
using std::swap;

#include <string>
using std::getline;
using std::string;

#include <cstdlib>

//struct for a Movie object
struct Movie
{
  //properties of Movie struct
  string name;
  int year;
  int rating;
  Movie* next = 0;

};

//FUNCTION PROTOTYPES
string DisplayMenu();
//string DisplayMenu();
string toLowerCase(string input);
//string toLowerCase(string input);
Movie AddMovie();
//Movie AddMovie();
void DisplayAllMovies(Movie* firstMovie, int nodeQuantity);
//void DisplayAllMovies(Movie* firstMovie, int nodeQuantity);
int TakeInNumber();
//int TakeInNumber();
void EditMovieList(Movie* firstMovie, int intInput, bool isEdit);
//void EditMovieList(Movie* firstMovie, int intInput, bool isEdit);
void SortMovies(Movie* firstMovie, int type);
//void SortMovies(Movie* firstMovie, int type);

int main()
{
  // identification output code block
  cout << "Calex Raffield\n\n";
  cout << "Lab 6: Movies Linked List\n";
  cout << "Editor(s) used: Microsoft Visual Studio\n";
  cout << "Compiler(s) used: Microsoft Visual Studio\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  bool active = true;
  //empty linked list node
  Movie* firstMovie = NULL;
  //quantity of nodes
  int nodeQuantity = 0;

  //Repeatedly displays options menu and asks for user input for options until user quits program. (while active == true)
  while (active) {

    string input = DisplayMenu();
    input = toLowerCase(input);

    if (input == "a") {
      //add a new movie

      Movie *mov = new Movie{ "",0,0 };
      Movie inputMov = AddMovie();
      mov->name = inputMov.name;
      mov->year = inputMov.year;
      mov->rating = inputMov.rating;
      mov->next = firstMovie;
      firstMovie = mov;
      nodeQuantity++;

    }
    else if (input == "u") {
      //edit movie
      if (nodeQuantity <= 0) {
        cout << "\nInvalid Input: No nodes available.\n";
      }
      else {
        cout << "\nWhich movie do you want to update (1-" << nodeQuantity << ")?\n>";
        bool validInput = false;
        int intInput = -1;

        while (!validInput) {
          validInput = true;
          intInput = TakeInNumber();
          if (intInput > nodeQuantity || intInput < 1) {
            validInput = false;
            cout << "\nINVALID INPUT: MOVIE INDEX OUT OF BOUNDS, TRY AGAIN.\n";
          }
        }
        

        EditMovieList(firstMovie, intInput, true);

      }
    }
    else if (input == "e") {
      //remove movie
      if (nodeQuantity <= 0) {
        cout << "\nInvalid Input: No nodes available.\n";
      }
      else {
        cout << "\nWhich movie do you want to remove (1-" << nodeQuantity << ")?\n>";
        int intInput = TakeInNumber();

        EditMovieList(firstMovie, intInput, false);
        nodeQuantity--;
        if (nodeQuantity == 0) {
          firstMovie = NULL;
        }
      }

    }
    else if (input == "l") {
      //List all movies
      DisplayAllMovies(firstMovie, nodeQuantity);


    }
    else if (input == "t") {
      //arrange movies by title
      if (nodeQuantity <= 1) {
        cout << "\nInvalid Input: Not enough nodes available to edit arrangement.\n";
      }
      else {
        SortMovies(firstMovie, 1);
      }
      
    }
    else if (input == "v") {
      //arrange movies by year viewed
      if (nodeQuantity <= 1) {
        cout << "\nInvalid Input: Not enough nodes available to edit arrangement.\n";
      }
      else {
        SortMovies(firstMovie, 2);
      }
    }
    else if (input == "r") {
      //arrange by rating
      if (nodeQuantity <= 1) {
        cout << "\nInvalid Input: Not enough nodes available to edit arrangement.\n";
      }
      else {
        SortMovies(firstMovie, 3);
      }
    }
    else if (input == "q") {
      //quit program
      active = false;
    }
    else {
      //Invalid input notification if input is none of the listed options
      cout << "\nINVALID INPUT: TRY AGAIN.\n";
    }

  }

  




  //exit prompt
  cout << "\nPress ENTER or RETURN to continue...";
  cin.get();

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
* Purpose: Displays a formatted table of all movies
* Parameters:
*     Arguments: Movie* firstMovie, int nodeQuantity
*
*     Return: N/A (void)
***************************************************************************************************************************************************/
void DisplayAllMovies(Movie* firstMovie, int nodeQuantity) {

  cout << "\n # Title                                   Viewed Rating\n-- --------------------------------------- ------ ------\n";

  if (nodeQuantity > 0) {
    int index = 1;

    //Displays each movie's data one by one
    for (Movie* p = firstMovie; p; p = p->next, index++) {

      cout.width(2);
      cout << index;
      cout.width(40);
      cout << p->name;
      cout.width(7);
      cout << p->year;
      cout.width(7);
      cout << p->rating << endl;

    }
  }

  

}

/**************************************************************************************************************************************************
* Purpose: DIsplays menu options and takes in user input of an option.
* Parameters:
*     Arguments: N/A
*
*     Return: string
***************************************************************************************************************************************************/
string DisplayMenu() {

  int returnValue = -1;
  string input = "";

  cout << "\nMENU\nA: Add a movie\nU: Update a movie\nE: Remove a movie\nL: List all movies\nT: Arrange by title\nV: Arrange by year Viewed\nR: Arrange by Rating\nQ: Quit\nType your option letter here:\n>";
  getline(cin, input);
  return input;
  
}

/**************************************************************************************************************************************************
* Purpose: Returns a Movie based on user input
* Parameters:
*     Arguments: N/A
*
*     Return: Movie
***************************************************************************************************************************************************/
Movie AddMovie() {

  //Movie variable to be used as return value, and string buffer variable.
  Movie returnValue = {"",0,0};
  string buf;

  //bool check for valid inputs
  bool validInput = false;

  //prompt user for name of movie
  while (!validInput) {

    cout << "\nEnter a name for this Movie:\n>";

    getline(cin, returnValue.name);

    //displays error message if input is not valid.
    if (returnValue.name == "") {
      cout << "\nInvalid Input, try again.\n";
    }
    else {
      validInput = true;
    }

  }

  validInput = false;

  //prompt user for year watched of movie until input is valid.
  while (!validInput) {
    cout << "What year did this movie release? (Example: 2018)\n>";
    cin >> buf; returnValue.year = atoi(buf.c_str()); cin.ignore(1000, 10);
    if (returnValue.year <= 0) {
      cout << "\nInvalid Input, try again.\n";
    }
    else {
      validInput = true;
    }

  }

  validInput = false;

  //prompt user for rating of movie until input is valid.
  while (!validInput) {
    cout << "What rating would you give this movie (1-10)?\n>";
    cin >> buf; returnValue.rating = atoi(buf.c_str()); cin.ignore(1000, 10);
    if (returnValue.rating <= 0 || returnValue.rating > 10) {
      cout << "\nInvalid Input, try again.\n";
    }
    else {
      validInput = true;
    }

  }

  //input verification prompt
  cout << "\nInput Recieved.\n";

  return returnValue;
  //return the Movie filled out with user input.


}

/**************************************************************************************************************************************************
* Purpose: Returns an integer based on user input.
* Parameters:
*     Arguments: N/A
*
*     Return: int
***************************************************************************************************************************************************/
int TakeInNumber() {

  string buf;
  bool validInput;
  int returnValue = -1;

  validInput = false;

  //prompt user for valid integer input until valid input is recieved.
  while (!validInput) {
    cin >> buf; returnValue = atoi(buf.c_str()); cin.ignore(1000, 10);
    if (returnValue < 1) {
      cout << "\nINVALID INPUT: MOVIE INDEX OUT OF BOUNDS, TRY AGAIN.\n";
    }
    else {
      validInput = true;
    }

  }

  return returnValue;
}

/**************************************************************************************************************************************************
* Purpose: Edits or removes Movies from the linked list based on int intInput and bool isEdit.
* Parameters:
*     Arguments: Movie* firstMovie, int intInput, bool isEdit
*
*     Return: N/A (void)
***************************************************************************************************************************************************/
void EditMovieList(Movie* firstMovie, int intInput, bool isEdit) {

  int index = 0;
  Movie* target;

  //finds target ptr for movie based on intInput.
  for (target = firstMovie; index < intInput - 1; target = target->next, index++) {

  }

  if (isEdit) {

    cout << "Editing Movie[" << target->name << "]\n";

    Movie inputMov = AddMovie();
    target->name = inputMov.name;
    target->year = inputMov.year;
    target->rating = inputMov.rating;

    cout << "\nEdits Complete.\n";

  }
  else {

    int indexB = 0;

    if (intInput == 1) {
      Movie* initial = firstMovie;
      firstMovie = firstMovie->next;
      delete initial;
      //cout << firstMovie->name;
    }
    else {
      Movie* prev;
      for (prev = firstMovie; indexB < intInput - 2; prev = prev->next, indexB++) {

      }

      prev->next = target->next;
      delete target;
    }
    cout << "Movie Removed.";
  }


}

/**************************************************************************************************************************************************
* Purpose: Rearranges the linked list of Movies based on int type.
* Parameters:
*     Arguments: Movie* firstMovie, int type
*
*     Return: N/A (void)
***************************************************************************************************************************************************/
void SortMovies(Movie* firstMovie, int type) {

  //bubble sort through all movies
  for (Movie *p = firstMovie; p; p = p->next) {
    for(Movie* q = p->next; q; q = q->next){
      
      if (type == 1) {
        if (toLowerCase(q->name) < toLowerCase(p->name)) {
          //swaps values content and ptrs of p and q
          swap(*p, *q);
          swap(p->next, q->next);

        }

      }

      if (type == 2) {
        if (q->year < p->year) {
          //swaps values content and ptrs of p and q
          swap(*p, *q);
          swap(p->next, q->next);

        }

      }

      if (type == 3) {

        if (q->rating < p->rating) {
          //swaps values content and ptrs of p and q
          swap(*p, *q);
          swap(p->next, q->next);

        }
      }
    }
  }

  //task completion prompt
  cout << "\nMovies arranged.\n";

}