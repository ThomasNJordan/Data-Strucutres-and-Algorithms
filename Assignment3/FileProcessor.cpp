#include "FileProcessor.h"

FileProcessor::FileProcessor() {}
FileProcessor::~FileProcessor() {}

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
