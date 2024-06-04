#include <iostream>
#include "xlog.h"
#include "xthread.hpp"

int main() {
    std::cout << "test auto source header!!" << std::endl;
    xlog();
    xthread();

    return 0;
}