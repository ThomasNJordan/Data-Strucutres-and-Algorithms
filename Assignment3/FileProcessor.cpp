#include "FileProcessor.h"
#include "Translator.h"  // Since I create an object of the Translator class, I have to include the Translator header file here
#include <fstream>
#include <iostream>
using namespace std;

void FileProcessor::processFile(string inputName, string outputName){
  // use fstream objects to read and write to files
  Translator converter; // here you can use an object of the Translator class
  // for each line of the input file, call the Translator object's translateEnglishSentence function
}
