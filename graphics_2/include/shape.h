#pragma once

class PixelBuffer;

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw(PixelBuffer& buffer) const = 0;
};
