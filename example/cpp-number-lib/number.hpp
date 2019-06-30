#pragma once
#include <iostream>

class number
{
public:
  number(double r, double c);
  ~number();

  // other is constant, meaning, this function will not change other
  // this function is a constant member function, meaning this function will not change its member fields
  // TODO: how do we mimic this in Java? 
  number operator+(const number & other) const;
  void increment();
  double getLength();
  friend std::ostream& operator<< (std::ostream& os, number & other);
private:
  double r, c;
};

std::ostream& operator<< (std::ostream& os, number & other);
