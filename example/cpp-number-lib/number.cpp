#include "number.hpp"
#include <cmath>

number::number(double r, double c)
    : r(r), c(c)
{
}

number::~number() {}

number number::operator+(const number &other) const
{
  number newNumber(this->r, this->c);
  newNumber.r += other.r;
  newNumber.c += other.c;
  return newNumber;
}

void number::increment()
{
  this->r++;
  this->c++;
}

double number::getLength()
{
  return sqrt(this->r  * this->r + this->c * this->c);
}

std::ostream &operator<<(std::ostream &os, number &n)
{
  os << n.r << "+" << n.c << "i";
  return os;
}
