/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 5
*/

#include "Delimiter.h"

/*
expectedValue() returns the opposite value of open delimiters
@param the open delimiter
@return the corresponding closed delimiter
*/
char Delimiter::expectedValue(char givenValue) {
  switch (givenValue) {
    case '{':
      return '}';
    case '[':
      return ']';
    case '(':
      return ')';
  }
}

/*
delimiter() parses the delimiters in a file.

Create a stack based on arrays, then push all open delimiters onto the stack.
Then iterate through the file, looking for closing delimiters, then popping the
matching values of the stack or breaking the program when an error is detected.

{ { } -> {    - Error
{ } } -> }    - Error
{ } { -> {    - Error
} { } -> }    - Error

{ ( [ { ] ) } -> { ( [ ] ) -> { [ ] -> {  - Error

Execution Flow:
- Push open delimeters onto a stack
- Iterate the line numebr
- If a break doesn't occur, prompt user for another file

@param filePath is the path to the file to be parsed
*/
void Delimiter::delimiter(string filePath) {
  AStack<char> openDelimieter;
  ifstream inFile;
  char tempVal;
  bool exitLoop = false;
  string str;
  int lineNum = 0;
  inFile.open(filePath);
  while (getline(inFile, str) && exitLoop == false) { // iterate through file
    if (exitLoop == false) {
      ++lineNum;
      for (char c : str) {
        if (c == '{' || c == '[' || c == '(') {
          openDelimieter.push(c);
        }
        if (c == '}' || c == ']' || c == ')') {
          tempVal = openDelimieter.pop();
          switch (c) {
            case '}':
              if (tempVal == '(' || tempVal == '[') {
                cout << "Line " << lineNum << ": Expected " << expectedValue(tempVal) << " found " << c << endl;
                exitLoop = true;
              }
              break;
            case ']':
              if (tempVal == '(' || tempVal == '{') {
                cout << "Line " << lineNum << ": Expected " << expectedValue(tempVal) << " found " << c << endl;
                exitLoop = true;
              }
              break;
            case ')':
              if (tempVal == '{' || tempVal == '[') {
                cout << "Line " << lineNum << ": Expected " << expectedValue(tempVal) << " found " << c << endl;
                exitLoop = true;
              }
              break;
          }
        }
      }
    }
  }
  if (exitLoop == false) {
    char userChoice;
    string newFilePath;
    cout << "Delimeter syntax is correct. Would you like to enter another file? (y/n)" << endl;
    cin >> userChoice;
    switch (userChoice) {
      case 'y':
        cout << "Enter the name of the file you want to analyize: " << endl;
        cin >> newFilePath;
        delimiter(newFilePath);
      case 'n':
        break;
    }
  }
  inFile.close();
}
