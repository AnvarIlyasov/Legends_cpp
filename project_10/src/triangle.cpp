#include "triangle.h"

#include <algorithm>
#include <cmath>
#include <iostream>

Triangle::Triangle(double sideA, double sideB, double sideC)
    : sideA_(sideA), sideB_(sideB), sideC_(sideC) {
}

void Triangle::draw() const {
    std::cout << "Triangle(a=" << sideA_ << ", b=" << sideB_
              << ", c=" << sideC_ << ")\n";
}

double Triangle::area() const {
    const double semiPerimeter = perimeter() / 2.0;
    const double areaSquared =
        semiPerimeter * (semiPerimeter - sideA_) * (semiPerimeter - sideB_) *
        (semiPerimeter - sideC_);
    return std::sqrt(std::max(0.0, areaSquared));
}

double Triangle::perimeter() const {
    return sideA_ + sideB_ + sideC_;
}
