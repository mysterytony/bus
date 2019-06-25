#include <iostream>
#include "request.h"

int main() {
    Request request;
    std::string result = request.Call("hello world");
    std::cout << "server returned: " << result << std::endl;
}

