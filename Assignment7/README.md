Assignment 7: Creating a Simple Database System Using BSTs

1. Thomas Jordan & Jackie Vu
   2400895 & 2345574 (respectively)
   thjordan@chapman.edu & jacvu@chapman.edu
   CPSC 350-02
   Assignment 7: Creating a Simple Database System Using BSTs

2. ListNode.h
   DLList.h
   stack.h
   AStack.h
   TreeNode.h
   BST.h
   StudentRecords.h
   StudentRecords.cpp
   FacultyRecords.h
   FacultyRecords.cpp
   tableController.h
   tableController.cpp
   Simulate.h
   Simulate.cpp
   InputOutput.h
   InputOutput.cpp
   mainprogram.cpp

3. https://www.geeksforgeeks.org/sort-c-stl/ & https://www.cplusplus.com/reference/algorithm/sort/ to help us figure out how to sort our student BST based on the student's
   ID number
   https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/ to help us figure out how to write class objects from and to a file in C++
   https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm & https://www.geeksforgeeks.org/operator-overloading-c/ to help us figure out how to do method overloading for certain operators

4. Rao told us to convert the StudentRecords objects into tree nodes, we have to construct a tree node object first before passing that to the BST's insert function
   Rao pointed out that there's a typo in our tree node, saying that there should be k for the key value in our constructor because the complier didn't seem to like our tree node declaration in tableController.cpp --> not enough to get the tree node to work so Rao mentioned that our insert function should be taking a pointer to a tree node to insert, not a tree node object --> further debugged the issue by asking us the name of the object we have created for this tree node and told us that we can't use TreeNode as the name of our object, so we came up with a different object name --> issue has been resolved after some time of reformatting that line of code
   Got a core dump and segmentation fault for the function that handles option 7 of the menu --> however, due to time crunch, we weren't able to resolve this issue :(

5. g++ -std=c++11 StudentRecords.cpp FacultyRecords.cpp tableController.cpp Simulate.cpp InputOutput.cpp mainprogram.cpp -o output
   ./output
