/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 6: Calculating Metrics on Student Wait Times and Window Idle Times at the Registrar's Office
*/

/*
  This is a header file that lists out the private and public functions that will be used/included in Simulation.h and used/included in mainprogram.cpp indirectly.
*/

#include "Queue.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class simulation : public Queue<int> {
private:
  string filePath;
  int *windows;
  int numWindows;
  DLList<int> queueTime;
  DLList<int> finalTimes;
  Queue<int> studentQueue;
public:
  simulation(); // default constructor
  double calcMeanQueueTime();
  double calcMedianQueueTime();
  int getLongestQueueTime();
  int longestQueueTime();
  int waitingOverTenMinutes();
  double meanWindowIdleTime();
  int largestWaitTime();
  int windowsIdleOverFive();
  void prettyPrint();
  void simulate(string filePath);
};
