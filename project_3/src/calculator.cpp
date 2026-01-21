#include "calculator.h"
#include <stdexcept>

int rem(int a, int b){
    if (b == 0){
        return -1;
    }
    return a % b;
}