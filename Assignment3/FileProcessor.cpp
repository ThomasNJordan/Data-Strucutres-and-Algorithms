/*
* FileProcessor.cpp parses an input file, translates its contents, then outputs
* the result.
*/

#include "FileProcessor.h"

/*
* Default constructor
*/
FileProcessor::FileProcessor() {}

/*
* Destructor
*/
FileProcessor::~FileProcessor() {}

/*
* processFile
* This function takes an input and an output file. It parses the strings from
* the input file, then passes those strings to the translateEnglishSentence
* function. It then writes taht output into the output file.
* @param string inputfile, string outputfile
* @return N/A
*/
void FileProcessor::processFile(string inputfile, string outputfile) {
  string transText = "";
  string line;
  Translator t;
  ifstream myFile;
  myFile.open(inputfile);
  if (myFile.is_open()) {
    while (getline (myFile,line)) {
      transText += t.translateEnglishSentence(line) + "\n";
    }
    myFile.close();
  }
  ofstream newFile;
  newFile.open(outputfile);
  newFile << transText;
  newFile.close();
}
