#include "rectangle.h"

#include <iostream>

Rectangle::Rectangle(double width, double height)
    : width_(width), height_(height) {
}

void Rectangle::draw() const {
    std::cout << "Rectangle(width=" << width_ << ", height=" << height_
              << ")\n";
}

double Rectangle::area() const {
    return width_ * height_;
}

double Rectangle::perimeter() const {
    return 2.0 * (width_ + height_);
}
