#include "Merge.h"
/*
  Merge sort is a sorting algorithm with time complexity of O(n log n).
  It works by dividing numbers into "groups", then sorting those groups
  and combining them.
  https://en.wikipedia.org/wiki/Merge_sort
  https://www.programiz.com/dsa/merge-sort
*/

/*
1. Split items into two arrays
2. Sort and combine adjacent array
3. Recombine sorted array
*/
void Merge::merge(double Unsorted[], int startingIndex, int midpint, int endIndex) {
  // Get size of new arrays
  int tempArraySize1 = midpint - startingIndex + 1;
  int tempArraySize2 = endIndex - midpint;

  double tempArray1[tempArraySize1];
  double tempArray2[tempArraySize2];

  // Fill in values
  for (int i = 0; i < tempArraySize1; ++i) {
    tempArray1[i] = Unsorted[startingIndex + i];
  }
  for (int j = 0; j < tempArraySize2; ++j) {
    tempArray2[j] = Unsorted[(midpint + 1) + j];
  }

  // Create indices of the two arrays
  int indexTempArray1 = 0;
  int indexTempArray2 = 0;
  int indexOfMergedArray = startingIndex;

  // Insert the values in correct order
  // https://www.geeksforgeeks.org/merge-sort/
  while (indexTempArray1 < tempArraySize1 && indexTempArray2 < tempArraySize2) {
    if (tempArray1[indexTempArray1] <= tempArray2[indexTempArray2]) {
      Unsorted[indexOfMergedArray] = tempArray1[indexTempArray1];
      indexTempArray1++;
    }
    else {
      Unsorted[indexOfMergedArray] = tempArray2[indexTempArray2];
      indexTempArray2++;
    }
    indexOfMergedArray++;
  }

  // Fill in the remaining values of tempArray1
  while (indexTempArray1 < tempArraySize1) {
    Unsorted[indexOfMergedArray] = tempArray1[indexTempArray1];
    indexTempArray1++;
    indexOfMergedArray++;
  }

  // Fill in remaining values of tempArray2
  while (indexTempArray2 < tempArraySize2) {
    Unsorted[indexOfMergedArray] = tempArray2[indexTempArray2];
    indexTempArray2++;
    indexOfMergedArray++;
  }
}

void Merge::mergeSort(double arr[], int startingIndex, int endIndex) {
  if (startingIndex < endIndex) {
    int midpint = startingIndex + (endIndex - startingIndex) / 2;
    mergeSort(arr, startingIndex, midpint);
    mergeSort(arr, midpint + 1, endIndex);
    merge(arr, startingIndex, midpint, endIndex);
  }
}
