#include "number.hpp"
#include <iostream>

int main() {
  number n1(1,2);
  number n2(3,4);
  number n3 = n1 + n2;
  n3.increment();
  std::cout << n3 << " with length " << n3.getLength() << std::endl;
  return 0;
}
