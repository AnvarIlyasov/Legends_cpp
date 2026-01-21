#include <iostream>
#include "calculator.h"

int main(){
    int a, b;
    
    std::cout << "Enter two numbers: ";
    
    if (!(std::cin >> a >> b)) {
        std::cerr << "Error: invalid input!" << std::endl;
        return -1;
    }

    std::cout << sum(a,b) <<std::endl;
}