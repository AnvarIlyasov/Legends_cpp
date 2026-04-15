#pragma once

#include "shape.h"

class Circle : public Shape {
public:
    explicit Circle(double radius);

    void draw() const override;
    double area() const override;
    double perimeter() const override;

private:
    double radius_ = 0.0;
};
