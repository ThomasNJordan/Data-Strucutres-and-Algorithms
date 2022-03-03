#include "cell.h"

using namespace std;

cell::cell() {
  m_value = '-';
}

cell::~cell() {}

void cell::setValue(char value) {
  m_value = value;
}

char cell::getValue() {
  return m_value;
}
