/*
  setup.cpp creates a dynamic array of values to sort, and reads all the values
  from a file and places them in the array. This setup for I/O is then used by
  the different sorting algorithms.
*/

#include "setup.h"

void setup::readFromeFile(std::string filePath) {
  std::ifstream file_obj;
  file_obj.open(filePath);
  file_obj >> arraySize;
  valuesToSort = new double[arraySize];

  for (int i = 0; i < arraySize; ++i) {
    file_obj >> valuesToSort[i];
  }
}

double* setup::copyArray() {
  double* newArray = new double[arraySize];
  for (int i = 0; i < arraySize; ++i) {
    newArray[i] = valuesToSort[i];
  }
  return newArray;
}

int setup::getArraySize() {
  return arraySize;
}

void setup::printArray(double* tempArray) {
  for (int i = 0; i < arraySize; ++i) {
    std::cout << tempArray[i] << std::endl;
  }
}
