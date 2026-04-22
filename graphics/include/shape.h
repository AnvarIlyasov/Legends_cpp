#pragma once
#include "point.h"
#include <utility>


class Shape {
public:
  virtual ~Shape() = default;

  virtual void draw() const = 0;
  virtual double area() const = 0;

  virtual std::pair<Point, Point> getBounds() const = 0;
};