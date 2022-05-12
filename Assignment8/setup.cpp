/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 8: Sorting algorithms
*/

/*
  setup.cpp creates a dynamic array of values to sort, and reads all the values
  from a file and places them in the array. This setup for I/O is then used by
  the different sorting algorithms.
*/

#include "setup.h"

/*
  readFromeFile() is a function that creates an array from a specified input
  file.
  @param string filepath of the input file
*/
void setup::readFromeFile(std::string filePath) {
  std::ifstream file_obj;
  file_obj.open(filePath);
  file_obj >> arraySize;
  valuesToSort = new double[arraySize];

  for (int i = 0; i < arraySize; ++i) {
    file_obj >> valuesToSort[i];
  }
}

/*
  copyArray() makes a copy of the input array and returns it
  @returns a double array copy of the array of values from the input file
*/
double* setup::copyArray() {
  double* newArray = new double[arraySize];
  for (int i = 0; i < arraySize; ++i) {
    newArray[i] = valuesToSort[i];
  }
  return newArray;
}

/*
  getArraySize() returns the size of the input array
  @returns the size of the array
*/
int setup::getArraySize() {
  return arraySize;
}

/*
  printArray() iterates through an array and prints each value
  @param the array to print
*/
void setup::printArray(double* tempArray) {
  for (int i = 0; i < arraySize; ++i) {
    std::cout << tempArray[i] << std::endl;
  }
}
