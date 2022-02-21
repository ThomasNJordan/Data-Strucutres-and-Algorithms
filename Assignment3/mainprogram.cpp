#include "FileProcessor.h"
#include <iostream>
using namespace std;

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
