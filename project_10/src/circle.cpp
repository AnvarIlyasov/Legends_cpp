#include "circle.h"

#include <iostream>

namespace {

constexpr double kPi = 3.14159265358979323846;

}  // namespace

Circle::Circle(double radius) : radius_(radius) {
}

void Circle::draw() const {
    std::cout << "Circle(radius=" << radius_ << ")\n";
}

double Circle::area() const {
    return kPi * radius_ * radius_;
}

double Circle::perimeter() const {
    return 2.0 * kPi * radius_;
}
