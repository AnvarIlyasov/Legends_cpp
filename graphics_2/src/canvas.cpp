#include "canvas.h"

#include <iostream>

Canvas::Canvas(std::size_t width, std::size_t height) : buffer_(width, height) {
}

void Canvas::addShape(std::unique_ptr<Shape> shape) {
    shapes_.push_back(std::move(shape));
}

void Canvas::render() {
    buffer_.clear(0);
    for (const std::unique_ptr<Shape>& shape : shapes_) {
        shape->draw(buffer_);
    }
}

void Canvas::print(std::ostream& out) const {
    out << buffer_.toAscii('.', '#') << '\n';
}

std::size_t Canvas::shapeCount() const {
    return shapes_.size();
}

PixelBuffer& Canvas::buffer() {
    return buffer_;
}

const PixelBuffer& Canvas::buffer() const {
    return buffer_;
}
