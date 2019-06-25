#include "busd.h"
#include <iostream>

int main () {
    std::cout << "starting daemon" << std::endl;
    BUSD busd;
    busd.Start();
}

