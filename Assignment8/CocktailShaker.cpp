/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 8: Sorting algorithms
*/

/*
  A Cocktail Shaker Sort is a method of sorting that uses a Bubble Sort, but in
  both directions. Instead of just repeating from bottom to top, the Cocktail
  Shaker Sort passes from Bottom to Top, and then from Top to Bottom - much like
  the ice in a cocktail shaker.

  The Cocktail Shaker code is based off the Pseudocode on Wikipedia.
  https://en.wikipedia.org/wiki/Cocktail_shaker_sort
*/


/*
                    ==== Pseudocode ====

procedure cocktailShakerSort(A : list of sortable items) is
    do
        swapped := false
        for each i in 0 to length(A) − 2 do:
            if A[i] > A[i + 1] then // test whether the two elements are in the wrong order
                swap(A[i], A[i + 1]) // let the two elements change places
                swapped := true
            end if
        end for
        if not swapped then
            // we can exit the outer loop here if no swaps occurred.
            break do-while loop
        end if
        swapped := false
        for each i in length(A) − 2 to 0 do:
            if A[i] > A[i + 1] then
                swap(A[i], A[i + 1])
                swapped := true
            end if
        end for
    while swapped // if no elements have been swapped, then the list is sorted
end procedure
*/

#include "CocktailShaker.h"

/*
  Cocktail Shaker Sort is a sorting algorithm that sorts the elements in
  the array by first iterating from the front to the back, then from the back
  to the front.
  @param the array to be sorted, and the size of the array
*/
void CocktailShaker::cocktailShakerSort(double UnsortedArray[], int arraySize) {
  bool swapped = false;
  do {
    for (int i = 0; i < arraySize - 2; ++i) {
      if (UnsortedArray[i] > UnsortedArray[i + 1]) {
        double temp = UnsortedArray[i];
        UnsortedArray[i] = UnsortedArray[i+1];
        UnsortedArray[i+1] = temp;
        swapped = true;
      }
    }
    if (swapped == false) {
      break;
    }
    swapped = false;
    for (int i = arraySize - 2; i >= 0; --i) {
      if (UnsortedArray[i] > UnsortedArray[i + 1]) {
        double temp = 0;
        temp = UnsortedArray[i];
        UnsortedArray[i] = UnsortedArray[i+1];
        UnsortedArray[i+1] = temp;
        swapped = true;
      }
    }
  } while (swapped == true);
}
