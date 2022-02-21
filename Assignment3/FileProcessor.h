/*
* This is the header file for the FileProcessor class.
*/

#include <fstream>
#include "Model.h"
#include "Translator.h"
using namespace std;

class FileProcessor {
public:
  FileProcessor();
  ~FileProcessor();
  void processFile(string inputfile, string outputfile);
};
