#include "rectangle.h"

#include <iostream>

#include "pixel_buffer.h"

Rectangle::Rectangle(int x, int y, int width, int height)
    : x_(x), y_(y), width_(width), height_(height) {
    std::cout << "[LOG] Shape ctor: Rectangle\n";
}

void Rectangle::draw(PixelBuffer& buffer) const {
    if (width_ <= 0 || height_ <= 0) {
        return;
    }

    for (int dx = 0; dx < width_; ++dx) {
        const int topX = x_ + dx;
        const int topY = y_;
        const int bottomY = y_ + height_ - 1;

        if (topX >= 0 && topY >= 0) {
            buffer.setPixel(static_cast<std::size_t>(topX),
                            static_cast<std::size_t>(topY), 1);
        }
        if (topX >= 0 && bottomY >= 0) {
            buffer.setPixel(static_cast<std::size_t>(topX),
                            static_cast<std::size_t>(bottomY), 1);
        }
    }

    for (int dy = 0; dy < height_; ++dy) {
        const int leftX = x_;
        const int rightX = x_ + width_ - 1;
        const int y = y_ + dy;

        if (leftX >= 0 && y >= 0) {
            buffer.setPixel(static_cast<std::size_t>(leftX),
                            static_cast<std::size_t>(y), 1);
        }
        if (rightX >= 0 && y >= 0) {
            buffer.setPixel(static_cast<std::size_t>(rightX),
                            static_cast<std::size_t>(y), 1);
        }
    }
}
