/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 6: Calculating Metrics on Student Wait Times and Window Idle Times at the Registrar's Office
*/

/*
  This is a main program class file that runs the simulation class and indirectly runs the rest of the header files.
  It is the driver class for this assignment by converting the file that's being passed into the command line argument to a string so that it can be used to calculate the metrics on student wait times and window idle times in the registrar's office in the simulation class.
*/

#include "simulation.h"

int main(int argc, char** argv) { // the code to get the file passed into the command line argument
  simulation s;
  s.simulate(argv[1]);
  return 0;
}
