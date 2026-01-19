#include <iostream>
#include "calculator.h"

int main() {
    int a = 10;
    int b = 3;

    std::cout << "Остаток от деления " << a << " на " << b << " = " << remainder(a, b) << std::endl;
    return 0;
}
