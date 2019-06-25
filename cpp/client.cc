#include <iostream>
#include "request.h"

int main() {
    Request request;
    std::string result = request.Call("(2+6* 3+5- (3*14/7+2)*5)+3");
    std::cout << "server returned: " << result << std::endl;
}

