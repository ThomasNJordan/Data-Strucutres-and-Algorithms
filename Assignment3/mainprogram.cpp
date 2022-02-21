/*
* This is the main program for the Tutnese Language Programming Assignment
* (Assignment 3). This file drives the other classes. No functionality is
* implemented in this file.
*/

#include "FileProcessor.h"
#include <iostream>
using namespace std;

/*
* main
* This is the main program. It drives the other classes. It takes an input and
* output filename, and passes that to FileProcessor.
* @param N/A
* @return int 0
*/
int main(){
  FileProcessor f;
  string inputFile;
  string outputFile;
  cout << "Enter the name of the input file: " << endl;
  cin >> inputFile;
  cout << "Enter the name of the output file: " << endl;
  cin >> outputFile;
  f.processFile(inputFile, outputFile);
  return 0;
}
