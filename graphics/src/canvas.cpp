#include <algorithm>
#include <iostream>
#include <memory>

#include "canvas.h"
#include "exceptions.h"

Canvas::Canvas(std::span<const Point> bounds) {
  if (bounds.size() < 2)
    throw std::invalid_argument("Please, enter at least 2 points for canvas");
  minBound = bounds[0];
  maxBound = bounds[1];
  if (minBound.x > maxBound.x)
    std::swap(minBound.x, maxBound.x);
  if (minBound.y > maxBound.y)
    std::swap(minBound.y, maxBound.y);
}

void Canvas::checkBounds(const Shape *shape) const {
  auto [shapeMin, shapeMax] = shape->getBounds();

  if (shapeMin.x < minBound.x || shapeMin.y < minBound.y ||
      shapeMax.x > maxBound.x || shapeMax.y > maxBound.y) {
    throw OutOfCanvasBoundsException("Shape is out of canvas");
  };
}

void Canvas::addShape(std::unique_ptr<Shape> shape) {
  if (!shape)
    return;
  checkBounds(shape.get());
  shapes.push_back(std::move(shape));
}

void Canvas::drawAll() const {
  std::cout << "Start of the canvas" << std::endl;
  for (const auto &shape : shapes)
    shape->draw();
  std::cout << "End of the canvas" << std::endl;
}