#pragma once
#include "shape.h"
#include <utility>

class Circle : public Shape {
private:
  double radius_ = 0.0;
  Point center_;

public:
  explicit Circle(double radius_);
  void setCenter(Point center_);

  Point getCenter() const;
  double getRadius() const;

  double area() const override;
  void draw() const override;
  std::pair<Point, Point> getBounds() const override;
};