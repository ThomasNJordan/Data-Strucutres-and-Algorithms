/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 8: Sorting algorithms
*/

/*
  setup.h is the header file for the setup class, which has functions that all
  algorithms use to create and use different arrays.
*/

#include <fstream>
#include <string>
#include <iostream>

class setup {
  public:
    void readFromeFile(std::string filePath);
    int getArraySize();
    double* copyArray();
    void printArray(double* tempArray);
  private:
    double* valuesToSort;
    int arraySize;
};
