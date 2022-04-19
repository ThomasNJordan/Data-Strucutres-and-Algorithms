/*
Thomas Jordan & Jackie Vu
2400895 & 2345574 (respectively)
thjordan@chapman.edu & jacvu@chapman.edu
CPSC 350-02
Assignment 6: Calculating Metrics on Student Wait Times and Window Idle Times at the Registrar's Office
*/

/*
  This is the simulation class that provides the functionality of calculating the metrics on student wait times and window idle times based on the number of students entering the queue and getting their assistance at the registrar's windows.
*/

#include "simulation.h"

/*
  Default Constructor
  The default constructor initializes my private variable to "".
*/
simulation::simulation() {
  filePath = "";
}

/*
  Calc Mean Queue Time Function
  The calc mean queue time function calculates the mean student wait time in the queue and refills the final times doubly linked list.
  @return double meanTime
*/
double simulation::calcMeanQueueTime() {
  double meanTime = 0.0;
  int final_length = finalTimes.length();
  DLList<int> meanList;

  for (int i = 0; i < final_length; ++i) {
    meanList.insertFront(finalTimes.peekFront());
    meanTime += finalTimes.peekFront();
    finalTimes.removeFront();
  }
  meanTime = meanTime / final_length;

  // refill final list
  for (int i = 0; i < final_length; ++i) {
    int temp = meanList.peekFront();
    finalTimes.insertFront(temp);
    meanList.removeFront();
  }

  return meanTime;
}

/*
  Calc Median Queue Time Function
  The calc median queue time function calculates the median student wait time in the queue and refills the final times doubly linked list.
  @return double ret
*/
double simulation::calcMedianQueueTime() {
  DLList<int> medianList;
  int final_length = finalTimes.length();
  double median = 0;
  double ret = 0;
  if (final_length % 2 != 0) { // if the final length of the final times doubly linked list is odd...
    median = ((final_length - 1) / 2) + 1;
    for (int i = 0; i < median - 1; ++i) { // because we're looking at the next value, we go one less
      medianList.insertFront(finalTimes.peekFront());
      finalTimes.removeFront();
    }
    ret = finalTimes.peekFront();
  }
  else { // if the final length of the final times doubly linked list is even...
    int lowerVal = finalTimes.length() / 2;
    for (int i = 0; i < lowerVal - 1; ++i) {
      medianList.insertFront(finalTimes.peekFront());
      finalTimes.removeFront();
    }
    double val1 = finalTimes.peekFront();
    medianList.insertFront(finalTimes.peekFront());
    finalTimes.removeFront();
    double val2 = finalTimes.peekFront();
    ret = (val1 + val2) / 2;
  }

  // refill final times list
  for (int i = 0; i < (final_length - finalTimes.length()); ++i) {
    int temp = medianList.peekFront();
    finalTimes.insertFront(temp);
    medianList.removeFront();
  }

  return ret;
}

/*
  Longest Queue Time Function
  The longest queue time function calculates the longest student wait time in the queue and refills the final times doubly linked list.
  @return int longestQueueTime
*/
int simulation::longestQueueTime() {
  int final_length = finalTimes.length();
  DLList<int> longestList;
  int longestQueueTime = 0;
  for (int i = 0; i < final_length; ++i) {
    if (finalTimes.peekFront() > longestQueueTime) {
      longestQueueTime = finalTimes.peekFront();
    }
    longestList.insertFront(finalTimes.peekFront());
    finalTimes.removeFront();
  }

  // refill final times list
  for (int i = 0; i < final_length; ++i) {
    int temp = longestList.peekFront();
    finalTimes.insertFront(temp);
    longestList.removeFront();
  }

  return longestQueueTime;
}

/*
  Waiting Over Ten Minutes Function
  The waiting over ten minutes function calculates the number of students waiting in the queue for over ten minutes and refills the final times doubly linked list.
  @return int numWaitingOverTen
*/
int simulation::waitingOverTenMinutes() {
  int final_length = finalTimes.length();
  DLList<int> tenList;
  int numWaitingOverTen = 0;
  for (int i = 0; i < final_length; ++i) {
    if (finalTimes.peekFront() > 10) {
      numWaitingOverTen++;
    }
    tenList.insertFront(finalTimes.peekFront());
    finalTimes.removeFront();
  }

  // refill final times list
  for (int i = 0; i < final_length; ++i) {
    int temp = tenList.peekFront();
    finalTimes.insertFront(temp);
    tenList.removeFront();
  }

  return numWaitingOverTen;
}

/*
  Mean Window Idle Time Function
  The mean window idle time function calculates the mean time for windows (displayed as a doubly linked list) to be vacant.
  @return double meanWait / numWindows
*/
double simulation::meanWindowIdleTime() {
  double meanWait = 0;
  for (int i = 0; i < numWindows; ++i) {
    if (windows[i] <= 0) {
      meanWait += ((windows[i] * -1)-1);
    }
  }
  return meanWait / numWindows;
}

/*
  Largest Wait Time Function
  The largest wait time function calculates the longest amount of time for a window (displayed as a doubly linked list) to be vacant.
  @return int largestWaitTime
*/
int simulation::largestWaitTime() {
  int largestWaitTime = 0;
  for (int i = 0; i < numWindows; ++i) {
    if (windows[i] <= 0 && windows[i] < largestWaitTime) {
      largestWaitTime = windows[i];
    }
  }
  largestWaitTime = (largestWaitTime * -1)-1;
  return largestWaitTime;
}

/*
  Windows Idle Over Five Function
  The windows idle over five function calculates the number of windows (displayed as a doubly linked list) to be vacant for over five minutes.
  @return int windowsOpenFive
*/
int simulation::windowsIdleOverFive() {
  int windowsOpenFive = 0;
  for (int i = 0; i < numWindows; ++i) {
    if (windows[i] < -6) {
      windowsOpenFive++;
    }
  }
  return windowsOpenFive;
}

/*
  Pretty Print Function
  The pretty print function prints all of the metrics that were calculated in the other functions into the terminal.
*/
void simulation::prettyPrint() {
  cout << "Mean student wait time in queue: " << calcMeanQueueTime() << endl;
  cout << "Median student wait time in queue: " << calcMedianQueueTime() << endl;
  cout << "Longest student wait time in queue: " << longestQueueTime() << endl;
  cout << "Number of students waiting over 10 minutes: " << waitingOverTenMinutes() << endl;
  cout << "Mean window idle time: " << meanWindowIdleTime() << endl;
  cout << "Longest window idle time: " << largestWaitTime() << endl; // -2 since -1 normally, then -1 when converting
  cout << "Number of windows idle for over 5 minutes: " << windowsIdleOverFive() << endl;
}

/*
  Simulate Function
  The simulate function sets up the registrar's office: windows for students to get assistance froms and a queue for students to wait in.
  - It starts off with reading a file that has been passed into the parameters.
  - Based on that file, it grabs the first number to create a specific sized windows doubly linked list.
  - Then, it grabs the next number to figure out the time number (or tick counter).
  - After that, it goes through a while loop to check if the time matches the tick counter, and if that's the case there are some conditions it needs to check for:
    - It grabs the third number from the file to determine the number of students.
    - Based on the number of students, it will iterate through a for loop to get these students lined up in the queue.
    - If the windows are vacant and if there are students waiting in the queue, students will be moved to the windows to get their assistance.
      - However, not all students can be moved to the windows because it's based on how many windows are available, so some students end up waiting for a longer period of time in the queue.
        - In that case, students' wait times in the queue will be incremented.
    - If a window is vacant and no students are moved to that window, the window idle time will continue to decrement past 0 (so into the negatives).
    - Then, increment the tick number to repeat the while loop.
    - Now, check to see if the while loop needs to continue running:
      - If the while loop can be terminated, then it's done reading the file and now closes the file.
      - If the while loop can't be terminated, then it will repeat itself.
  - Finally, it calls the pretty print functions to print out all of the metrics that will be displayed in the terminal.
  @param string filePath
*/
void simulation::simulate(string filePath) {
  // numStudents is the number of students in the array
  int numStudents = 0;

  // take in user values from file
  ifstream inFile;
  inFile.open(filePath);
  // makes a window of specified size
  inFile >> numWindows;
  windows = new int[numWindows];

  // parse time chunks, assume every value is pushed into the queue
  int tick = 0; // tick counter -- each tick is a unit time
  int tempTick;
  inFile >> tempTick;

  bool endCondition = false;
  while (endCondition != true) { // checks if array is empty
    int student = 0;
    // in loop, check if time matches next time (have some conditions to update time)

    if (tempTick == tick) {
      inFile >> numStudents;
      // get num in loop, then loop that time and add values in queue
      for (int i = 0; i < numStudents; ++i) {
        inFile >> student;
        studentQueue.enqueue(student);
        queueTime.insertFront(tick);
      }
      inFile >> tempTick;
    }

    for (int i = 0; i < numWindows; ++i) {
      if (windows[i] <= 0 && numStudents != 0) { // if empty
        student = studentQueue.peek();
        windows[i] = student;
        studentQueue.dequeue();
        numStudents--;

        int ret = tick - queueTime.peekFront(); // departure - arrival = time in queue
        finalTimes.insertBack(ret);
        queueTime.removeFront();
      }
    }

    if (tick != 0) { // make sure it's not initial run
      // then decrement each value in array, and increment tick
      for (int i = 0; i < numWindows; ++i) {
        windows[i] = (windows[i] - 1);
      }
    }
    tick++;

    // check if we can stop running loop
    // use comparable as a value since multiple pieces of information are stored in one integer, thus need to check if the integer falls within certain bounds
    int comparable = 0;
    for (int i = 0; i < numWindows; ++i) {
      if (windows[i] >= 0) {
        comparable++;
      }
    }

    if (comparable == 0 && numStudents == 0) {
      endCondition = true;
    }
  }
  inFile.close();
  prettyPrint();
}
