/*
* This is a header file for a Parser class that parses user input looking for
* alphabetic matches, pairs, non-alphabet symbols, and the average of all nums.
*/

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Parser {
private:
  string m_userString;
  int m_a = 0;
  int m_b = 0;
  int m_c = 0;
  int m_d = 0;
  int m_e = 0;
  int m_f = 0;
  int m_g = 0;
  int m_h = 0;
  int m_i = 0;
  int m_j = 0;
  int m_k = 0;
  int m_l = 0;
  int m_m = 0;
  int m_n = 0;
  int m_o = 0;
  int m_p = 0;
  int m_q = 0;
  int m_r = 0;
  int m_s = 0;
  int m_t = 0;
  int m_u = 0;
  int m_v = 0;
  int m_w = 0;
  int m_x = 0;
  int m_y = 0;
  int m_z = 0;
public:
  void setUserInput();
  virtual void printToFile();
  string toString();

  string getNumOccurances();
  int getAlphabet();
  int getNonAlphabet();
  double getAverage();
  int getPairs();
};
#endif
