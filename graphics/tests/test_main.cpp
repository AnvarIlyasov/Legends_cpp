#include <cmath>
#include <iostream>
#include <span>
#include <string>
#include <variant>

#include "canvas.h"
#include "circle.h"
#include "exceptions.h"
#include "point.h"
#include "rectangle.h"
#include "shapeFactory.h"

namespace {

constexpr double kEps = 1e-9;

bool nearlyEqual(double a, double b) { return std::abs(a - b) < kEps; }

int runTest(const std::string &name, bool (*fn)()) {
  try {
    if (fn()) {
      std::cout << "[PASS] " << name << '\n';
      return 0;
    }
    std::cout << "[FAIL] " << name << '\n';
    return 1;
  } catch (const std::exception &e) {
    std::cout << "[FAIL] " << name << " threw exception: " << e.what() << '\n';
    return 1;
  } catch (...) {
    std::cout << "[FAIL] " << name << " threw unknown exception\n";
    return 1;
  }
}

bool testPointComparisons() {
  const Point p1(1, 2);
  const Point p2(3, 4);
  return (p1 < p2) && (p2 > p1) && !(p1 > p2);
}

bool testCircleAreaAndBounds() {
  Circle c(2.0);
  c.setCenter(Point(3, 4));
  const auto [minP, maxP] = c.getBounds();
  return nearlyEqual(c.area(), M_PI * 4.0) && nearlyEqual(minP.x, 1.0) &&
         nearlyEqual(minP.y, 2.0) && nearlyEqual(maxP.x, 5.0) &&
         nearlyEqual(maxP.y, 6.0);
}

bool testCircleNegativeRadiusThrows() {
  try {
    Circle c(-1.0);
    (void)c;
    return false;
  } catch (const InvalidDimensionsException &) {
    return true;
  }
}

bool testRectangleAreaAndBounds() {
  Rectangle r(5.0, 2.0);
  r.setTopLeft(Point(10, 20));
  const auto [minP, maxP] = r.getBounds();
  return nearlyEqual(r.area(), 10.0) && nearlyEqual(minP.x, 10.0) &&
         nearlyEqual(minP.y, 20.0) && nearlyEqual(maxP.x, 15.0) &&
         nearlyEqual(maxP.y, 22.0);
}

bool testRectangleNegativeSidesThrow() {
  try {
    Rectangle r(-1.0, 2.0);
    (void)r;
    return false;
  } catch (const InvalidDimensionsException &) {
    return true;
  }
}

bool testCanvasConstructorNeedsTwoPoints() {
  const Point onlyOne[] = {Point(0, 0)};
  try {
    Canvas canvas{std::span<const Point>(onlyOne)};
    (void)canvas;
    return false;
  } catch (const std::invalid_argument &) {
    return true;
  }
}

bool testCanvasAcceptsShapeInsideBoundsAndSwapsInputBounds() {
  const Point bounds[] = {Point(10, 10), Point(0, 0)};
  Canvas canvas{std::span<const Point>(bounds)};

  auto rect = std::make_unique<Rectangle>(3.0, 3.0);
  rect->setTopLeft(Point(1, 1));

  canvas.addShape(std::move(rect));
  canvas.addShape(nullptr);
  return true;
}

bool testCanvasRejectsOutOfBoundsShape() {
  const Point bounds[] = {Point(0, 0), Point(5, 5)};
  Canvas canvas{std::span<const Point>(bounds)};

  auto circle = std::make_unique<Circle>(2.0);
  circle->setCenter(Point(1, 1));

  try {
    canvas.addShape(std::move(circle));
    return false;
  } catch (const OutOfCanvasBoundsException &) {
    return true;
  }
}

bool testShapeFactoryCreatesCircleAndRectangle() {
  using Param = ShapeFactory::ParamType;

  const Param circleParams[] = {Param(2.5)};
  auto c = ShapeFactory::create("Circle", std::span<const Param>(circleParams));
  if (!c) {
    return false;
  }
  if (dynamic_cast<Circle *>((*c).get()) == nullptr) {
    return false;
  }

  const Param rectParams[] = {Param(3.0), Param(4.0)};
  auto r = ShapeFactory::create("Rectangle", std::span<const Param>(rectParams));
  if (!r) {
    return false;
  }
  return dynamic_cast<Rectangle *>((*r).get()) != nullptr;
}

bool testShapeFactoryRejectsInvalidInputs() {
  using Param = ShapeFactory::ParamType;

  const Param badCircleType[] = {Param(std::string("bad"))};
  const Param negativeCircle[] = {Param(-1.0)};
  const Param missingRectangle[] = {Param(3.0)};

  auto a = ShapeFactory::create("Circle", std::span<const Param>(badCircleType));
  auto b = ShapeFactory::create("Circle", std::span<const Param>(negativeCircle));
  auto c =
      ShapeFactory::create("Rectangle", std::span<const Param>(missingRectangle));
  auto d = ShapeFactory::create("Triangle", std::span<const Param>());

  return !a && !b && !c && !d;
}

} // namespace

int main() {
  int failed = 0;

  failed += runTest("Point comparisons", testPointComparisons);
  failed += runTest("Circle area and bounds", testCircleAreaAndBounds);
  failed += runTest("Circle negative radius throws",
                    testCircleNegativeRadiusThrows);
  failed += runTest("Rectangle area and bounds", testRectangleAreaAndBounds);
  failed += runTest("Rectangle negative sides throw",
                    testRectangleNegativeSidesThrow);
  failed += runTest("Canvas constructor needs two points",
                    testCanvasConstructorNeedsTwoPoints);
  failed += runTest("Canvas accepts in-bounds shape and swaps bounds",
                    testCanvasAcceptsShapeInsideBoundsAndSwapsInputBounds);
  failed += runTest("Canvas rejects out-of-bounds shape",
                    testCanvasRejectsOutOfBoundsShape);
  failed += runTest("ShapeFactory creates circle and rectangle",
                    testShapeFactoryCreatesCircleAndRectangle);
  failed += runTest("ShapeFactory rejects invalid inputs",
                    testShapeFactoryRejectsInvalidInputs);

  if (failed == 0) {
    std::cout << "\nAll tests passed.\n";
    return 0;
  }

  std::cout << "\nFailed tests: " << failed << '\n';
  return 1;
}
