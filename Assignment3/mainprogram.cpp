#include "FileProcessor.h"
#include <iostream>
using namespace std;

// this should be everything needed in the main function
int main(){
  FileProcessor f; // using default constructor, you can overload
  // ask the user for input and output file names
  f.processFile("user provided input file name","user provided output file name");
  return 0;
}
