#pragma once

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double width, double height);

    void draw() const override;
    double area() const override;
    double perimeter() const override;

private:
    double width_ = 0.0;
    double height_ = 0.0;
};
