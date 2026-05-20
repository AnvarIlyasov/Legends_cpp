#pragma once

#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int x, int y, int width, int height);
    void draw(PixelBuffer& buffer) const override;

private:
    int x_;
    int y_;
    int width_;
    int height_;
};
