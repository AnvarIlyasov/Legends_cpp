#pragma once

#include <memory>
#include <span>
#include <vector>

#include "point.h"
#include "shape.h"

class Canvas {
private:
  Point minBound, maxBound;
  std::vector<std::unique_ptr<Shape>> shapes;

  void checkBounds(const Shape *shape) const;

public:
  explicit Canvas(std::span<const Point> bounds);

  void addShape(std::unique_ptr<Shape> shape);
  void drawAll() const;
};