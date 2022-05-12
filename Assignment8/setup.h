#include <fstream>
#include <string>
#include <iostream>

class setup {
  public:
    void readFromeFile(std::string filePath);
    int getArraySize();
    double* copyArray();
    void printArray(double* tempArray);
  private:
    double* valuesToSort;
    int arraySize;
};
