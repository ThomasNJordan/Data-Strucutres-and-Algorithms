/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 8: Sorting algorithms
*/

/*
  The merge class is responsible for sorting the array by splitting it into
  smaller subsections and sorting those.
*/
class Merge {
  public:
    void merge(double Unsorted[], int startingIndex, int midpint, int endIndex);
    void mergeSort(double arr[], int startingIndex, int endIndex);
};
