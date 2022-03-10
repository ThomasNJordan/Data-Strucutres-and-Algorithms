README Assignment 4: Game of Life

1. Thomas Jordan & Jacqueline Vu
   2400895 & 2345574 (respectively)
   thjordan@chapman.edu & jacvu@chapman.edu
   CPSC 350-02
   Assignment 4: Game of Life

2. cell.h
   cell.cpp
   board.h
   board.cpp
   classic.h
   classic.cpp
   donut.h
   donut.cpp
   mirror.h
   mirror.cpp
   config.c
   config.cpp
   mainprogram.cpp

3. https://www.cplusplus.com/reference/fstream/ifstream/ We used this to read
   from a file.
   https://stackoverflow.com/questions/9878965/rand-between-0-and-1 We used
   this to generate a random number between 0 and 1.

4. Rao helped me to create a copy constructor.
   Rao helped me figure out how to parse the 2d array.
   Rao checked our mainprogram.cpp on whether we cam declare a variable outside
   of main.

5. g++ -std=c++11 -o life cell.cpp board.cpp classic.cpp donut.cpp mirror.cpp config.cpp mainprogram.cpp
   ./life
