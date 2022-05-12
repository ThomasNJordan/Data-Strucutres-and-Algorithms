Assignment 8: Implementing Three Sorting Algorithms

1. Thomas Jordan
   2400895
   thjordan@chapman.edu
   CPSC 350-02
   Assignment 8: Sorting Algorithms

2. CocktailShaker.cpp    
   CocktailShaker.h    
   Driver.cpp   
   Driver.h   
   Merge.cpp   
   Merge.h   
   SelectionSort.cpp   
   SelectionSort.h   
   setup.cpp   
   setup.h    
   mainprogram.cpp

3. https://en.wikipedia.org/wiki/Cocktail_shaker_sort to create a Cocktail
   Shaker sorting algorithm.   
   https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c to record how long the differnt algorithms ran
   https://en.wikipedia.org/wiki/Merge_sort to implement the merge sort algorithm   
   https://www.programiz.com/dsa/merge-sort to cross-reference the wikipedia article on merge sorting   
   https://www.geeksforgeeks.org/merge-sort/ to suppliment the merge sort article from programiz   
   https://www.programiz.com/dsa/selection-sort to implement the selection sorting algorithm   


4. I clarified how to implement the implementation of my timing function with Dr. Ali   

5. g++ -std=c++11 -o sort CocktailShaker.cpp Merge.cpp SelectionSort.cpp Driver.cpp setup.cpp mainprogram.cpp && ./sort 100k.txt
