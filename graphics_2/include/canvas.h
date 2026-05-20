#pragma once

#include <cstddef>
#include <memory>
#include <ostream>
#include <vector>

#include "pixel_buffer.h"
#include "shape.h"

class Canvas {
public:
    Canvas(std::size_t width, std::size_t height);

    Canvas(const Canvas&) = delete;
    Canvas& operator=(const Canvas&) = delete;

    Canvas(Canvas&&) noexcept = default;
    Canvas& operator=(Canvas&&) noexcept = default;

    ~Canvas() = default;

    void addShape(std::unique_ptr<Shape> shape);
    void render();
    void print(std::ostream& out) const;

    std::size_t shapeCount() const;

    PixelBuffer& buffer();
    const PixelBuffer& buffer() const;

private:
    PixelBuffer buffer_;
    std::vector<std::unique_ptr<Shape>> shapes_;
};
