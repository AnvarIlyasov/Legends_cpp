#define _USE_MATH_DEFINES
#include <iostream>

#include "circle.h"
#include "exceptions.h"

Circle::Circle(double radius) : radius_(radius), center_(0, 0) {
  if (radius < 0)
    throw InvalidDimensionsException("Radius cannot be negative");
}

void Circle::setCenter(Point center) { center_ = center; }

Point Circle::getCenter() const { return center_; }
double Circle::getRadius() const { return radius_; }

double Circle::area() const { return M_PI * radius_ * radius_; }

void Circle::draw() const {
  std::cout << "Circle(radius=" << radius_ << ")" << std::endl;
}

std::pair<Point, Point> Circle::getBounds() const {
  Point min(center_.x - radius_, center_.y - radius_);
  Point max(center_.x + radius_, center_.y + radius_);
  return {min, max};
}