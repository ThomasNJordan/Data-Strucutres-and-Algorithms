/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 8: Sorting algorithms
*/

/*
  SelectionSort.cpp is responsible for implementing a Selection Sort. A
  Selection Sort is a method of sorting values by iterating through the array,
  finding the lowest value, then placing it in the lowest available position.
*/

#include "SelectionSort.h"
#include <iostream>

/*
  swapValues swaps the contents of two arrays of doubles.
  @param two double arrays you wish to switch
*/
void SelectionSort::swapValues(double *num1, double *num2) {
  double tempPlacement = *num1;
  *num1 = *num2;
  *num2 = tempPlacement;
}

/*
  sortVales is a selection sort algorithm that iterates through an array of
  values and places the lowest current value in the current lowest index.
  @param the double array of values to sort, and the number of values in the array
*/
void SelectionSort::sortValues(double valuesToSort[], int numValuesToSort) {
  for (int i = 0; i < numValuesToSort; i++) {
    int min_index = i;
    for (int j = i + 1; j < numValuesToSort; j++) {
      if (valuesToSort[j] < valuesToSort[min_index]) {
        min_index = j;
      }
    }
    swapValues(&valuesToSort[min_index], &valuesToSort[i]);
  }
}
