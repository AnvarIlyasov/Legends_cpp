#include "circle.h"

#include <iostream>

#include "pixel_buffer.h"

Circle::Circle(int centerX, int centerY, int radius)
    : centerX_(centerX), centerY_(centerY), radius_(radius) {
    std::cout << "[LOG] Shape ctor: Circle\n";
}

void Circle::draw(PixelBuffer& buffer) const {
    const int radiusSquared = radius_ * radius_;

    for (int dy = -radius_; dy <= radius_; ++dy) {
        for (int dx = -radius_; dx <= radius_; ++dx) {
            const int distanceSquared = dx * dx + dy * dy;

            if (distanceSquared >= radiusSquared - radius_ &&
                distanceSquared <= radiusSquared + radius_) {
                const int x = centerX_ + dx;
                const int y = centerY_ + dy;

                if (x >= 0 && y >= 0) {
                    buffer.setPixel(static_cast<std::size_t>(x),
                                    static_cast<std::size_t>(y), 1);
                }
            }
        }
    }
}
