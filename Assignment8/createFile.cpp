#include <iostream>
#include <fstream>
#include <string>
#include <random>

int main() {
  std::cout << "Enter the name of the outfile: " << std::endl;
  std::string filePath;
  std::getline (std::cin,filePath);
  std::ofstream ofile;
  ofile.open(filePath, std::ofstream::out | std::ofstream::trunc);
  std::cout << "Enter number of doubles to put in file: " << std::endl;
  int numDoubles;
  std::cin >> numDoubles;
  ofile << numDoubles << "\n";
  for (int i = 0; i < numDoubles; ++i) {
    double f = (double)rand() / RAND_MAX;
    double random = 0.0 + f * (1000.0 - 0.0);
    ofile << random << "\n";
  }
  ofile.close();
  return 0;
}
