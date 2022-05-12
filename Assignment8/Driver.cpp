/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 8: Sorting algorithms
*/

/*
  Driver.cpp is the implementation of the Driver class. This class is
  responsible for managing all the sorting algorithms, the timings, and the
  output.
*/

#include "Driver.h"

/*
  Drive() is the driver function. It starts each sorting algorithm and times
  how long they take to exewcute. It also is responsible for outputting the
  results of the timer.
  @param a string of the filepath of the input file
*/
void Driver::Drive(std::string inFile) {
  setup s;
  s.readFromeFile(inFile);

  using std::chrono::high_resolution_clock;
  using std::chrono::duration_cast;
  using std::chrono::duration;
  using std::chrono::milliseconds;

  CocktailShaker m_CocktailShaker;
  SelectionSort m_SelectionSort;
  Merge m_Merge;

  double* CocktailShakerArray = new double[s.getArraySize()];
  double* SelectionSortArray = new double[s.getArraySize()];
  double* MergeArray = new double[s.getArraySize()];
  CocktailShakerArray = s.copyArray();
  SelectionSortArray = s.copyArray();
  MergeArray = s.copyArray();

  auto CocktailSortTimeInit = high_resolution_clock::now();
  m_CocktailShaker.cocktailShakerSort(CocktailShakerArray, s.getArraySize());
  auto CocktailSortTimeEnd = high_resolution_clock::now();

  auto SelectionSortTimeInit = high_resolution_clock::now();
  m_SelectionSort.sortValues(SelectionSortArray, s.getArraySize());
  auto SelectionSortTimeEnd = high_resolution_clock::now();

  auto MergeSortTimeInit = high_resolution_clock::now();
  m_Merge.mergeSort(MergeArray, 0, s.getArraySize());
  auto MergeSortTimeEnd = high_resolution_clock::now();

  duration<double, std::milli> cocktailShakerSortTime = CocktailSortTimeEnd - CocktailSortTimeInit;
  duration<double, std::milli> SelectionSortsTime = SelectionSortTimeEnd - SelectionSortTimeInit;
  duration<double, std::milli> MergeSortTime = MergeSortTimeEnd - MergeSortTimeInit;

  std::cout << "Cocktail Shaker Sort: " << cocktailShakerSortTime.count() << "ms." << std::endl;
  std::cout << "Selection Sort: " << SelectionSortsTime.count() << "ms." << std::endl;
  std::cout << "Merge Sort: " << MergeSortTime.count() << "ms." << std::endl;
}
