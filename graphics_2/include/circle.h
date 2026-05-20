#pragma once

#include "shape.h"

class Circle : public Shape {
public:
    Circle(int centerX, int centerY, int radius);
    void draw(PixelBuffer& buffer) const override;

private:
    int centerX_;
    int centerY_;
    int radius_;
};
