#include "canvas.h"
#include "circle.h"
#include "point.h"
#include "rectangle.h"
#include "shapeFactory.h"
#include <iostream>
#include <memory>
#include <span>

int main() {
  Point boundsArray[] = {Point(0, 0), Point(100, 100)};
  std::span<const Point> boundsSpan(boundsArray);
  Canvas canvas(boundsSpan);

  using Param = ShapeFactory::ParamType;

  Param circleParams[] = {Param(5.0)};
  auto optCircle =
      ShapeFactory::create("Circle", std::span<const Param>(circleParams));
  if (optCircle) {
    auto circlePtr = std::move(*optCircle);
    if (auto *c = dynamic_cast<Circle *>(circlePtr.get())) {
      c->setCenter(Point(50, 50));
    }
    canvas.addShape(std::move(circlePtr));
  } else {
    std::cout << "Failed to create Circle.";
  }

  Param rectParams[] = {Param(30.0), Param(40.0)};
  auto optRect =
      ShapeFactory::create("Rectangle", std::span<const Param>(rectParams));
  if (optRect) {
    auto rectPtr = std::move(*optRect);
    if (auto *r = dynamic_cast<Rectangle *>(rectPtr.get())) {
      r->setTopLeft(Point(10, 20));
    }
    canvas.addShape(std::move(rectPtr));
  } else {
    std::cout << "Failed to create Rectangle.\n";
  }

  canvas.drawAll();

  return 0;
}