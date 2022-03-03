#ifndef CELL_H
#define CELL_H

class cell {
private:
  char m_value;
public:
  cell();
  ~cell();
  void setValue(char value);
  char getValue();
};

#endif
