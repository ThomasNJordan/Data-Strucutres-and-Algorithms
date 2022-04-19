README Assignment 6: Simulating Registrar's Wait Times

1. Thomas Jordan & Jackie Vu
   2400895 & 2345574 (respectively)
   thjordan@chapman.edu & jacvu@chapman.edu
   CPSC 350-02
   Assignment 6: Calculating Metrics on Student Wait Times and Window Idle Times at the Registrar's Office

2. ListNode.h
   DLList.h
   Queue.h
   simulation.h
   simulation.cpp
   mainprogram.cpp

3. https://stackoverflow.com/questions/2340930/stray-342-in-c-program to help us figure out why our compilers are spitting out "error: stray -some number- in program" multiple times for our header files

4. Rao assured us that Input 2's median student wait time in the queue in his testcases.txt file  is 0 and explained to us why it's 0
   Rao realized that he mistyped his explanation about why Input 2's median student wait time in the queue is 0 and clarified to us again
   Rao ran the metrics again when we asked him if Input 2's longest window idle time should be 2 instead of 0 --> we were correct so Rao updated the testcases.txt file and reuploaded it to Canvas
   Rao explained to us why Input 1's longest window idle time is 9 since we got 10 on our end --> however, he said if we're one number above or below the number he's looking for, we won't lose points
   Rao told us that we didn't need to modify the rear element in the queue for this assignment, which led us to question on how we're supposed to store the student wait times --> Rao later gave us an explanation to go about this: getting out of queue time - arrival time = student's wait time

5. g++ -std=c++11 simulation.cpp mainprogram.cpp -o output
   ./output fileName.txt
   ** NOTE: any file can be passed into the command line argument in mainprogram.cpp; fileName.txt is just an example
