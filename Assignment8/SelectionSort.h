/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 8: Sorting algorithms
*/

/*
  SelectionSort.h is the header file for the selection sort algorithm. It
  defines the behavior of the swap function, and the Selection Sort algorithm.
*/

class SelectionSort {
  public:
    void swapValues(double *num1, double *num2);
    void sortValues(double valuesToSort[], int numValuesToSort);
};
