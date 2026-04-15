#pragma once

#include "shape.h"

class Triangle : public Shape {
public:
    Triangle(double sideA, double sideB, double sideC);

    void draw() const override;
    double area() const override;
    double perimeter() const override;

private:
    double sideA_ = 0.0;
    double sideB_ = 0.0;
    double sideC_ = 0.0;
};
