#include "cell.h"

using namespace std;

cell::cell() {
  m_value = '\0';
}

cell::~cell() {}

void cell::setValue(char value) {
  m_value = value;
}

char cell::getValue() {
  return m_value;
}
