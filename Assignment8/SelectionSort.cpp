#include "SelectionSort.h"
#include <iostream>

void SelectionSort::swapValues(double *num1, double *num2) {
  double tempPlacement = *num1;
  *num1 = *num2;
  *num2 = tempPlacement;
}

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
