/*
Thomas Jordan
2400895
thjordan@chapman.edu
CPSC 350-02
Assignment 8: Sorting algorithms
*/

/*
  Driver.h is the header file for the Driver class. This class controls the
  timings, manages the algorithms, and is in charge of the output for the
  program.
*/

#include <chrono>
#include <thread>
#include "CocktailShaker.h"
#include "Merge.h"
#include "SelectionSort.h"
#include "setup.h"

class Driver {
  public:
    void Drive(std::string inFile);
};
