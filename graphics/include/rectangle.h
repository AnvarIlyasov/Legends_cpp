#pragma once

#include "shape.h"

class Rectangle : public Shape {
private:
  double width_ = 0.0;
  double height_ = 0.0;
  Point topLeft;

public:
  Rectangle(double width, double height);

  void setTopLeft(Point point);

  Point getTopLeft() const;
  double getWidth() const;
  double getHeight() const;
  
  std::pair<Point, Point> getBounds() const override;
  void draw() const override;
  double area() const override;
};