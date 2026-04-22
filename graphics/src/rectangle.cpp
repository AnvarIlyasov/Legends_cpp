#include <iostream>

#include "exceptions.h"
#include "rectangle.h"

Rectangle::Rectangle(double width, double height)
    : width_(width), height_(height), topLeft(0, 0) {
  if (width < 0 || height < 0)
    throw InvalidDimensionsException(
        "Sides of the rectangle cannot be negative");
}

void Rectangle::setTopLeft(Point point) { topLeft = point; }

double Rectangle::getWidth() const { return width_; }
double Rectangle::getHeight() const { return height_; }

double Rectangle::area() const { return width_ * height_; }

void Rectangle::draw() const {
  std::cout << "Rectangle (width = " << width_ << ", height = " << height_
            << ")" << std::endl;
}

std::pair<Point, Point> Rectangle::getBounds() const {
  Point min = topLeft;
  Point max(topLeft.x + width_, topLeft.y + height_);
  return {min, max};
}