#include "pixel_buffer.h"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <utility>

PixelBuffer::PixelBuffer() : data_(nullptr), width_(0), height_(0) {
    std::cout << "[LOG] PixelBuffer default ctor\n";
}

PixelBuffer::PixelBuffer(std::size_t width, std::size_t height)
    : data_(nullptr), width_(width), height_(height) {
    if (width_ > 0 && height_ > 0) {
        data_ = new uint8_t[width_ * height_];
        std::fill(data_, data_ + (width_ * height_), static_cast<uint8_t>(0));
    }
    std::cout << "[LOG] PixelBuffer ctor: " << width_ << "x" << height_ << "\n";
}

PixelBuffer::~PixelBuffer() {
    if (data_ != nullptr) {
        std::cout << "[LOG] PixelBuffer dtor: releasing " << width_ << "x" << height_ << "\n";
    } else {
        std::cout << "[LOG] PixelBuffer dtor: source cleared\n";
    }
    delete[] data_;
}

PixelBuffer::PixelBuffer(const PixelBuffer& other)
    : data_(nullptr), width_(other.width_), height_(other.height_) {
    if (other.data_ != nullptr) {
        data_ = new uint8_t[width_ * height_];
        std::memcpy(data_, other.data_, width_ * height_);
    }
    std::cout << "[LOG] PixelBuffer copy ctor: " << width_ << "x" << height_ << "\n";
}

PixelBuffer::PixelBuffer(PixelBuffer&& other) noexcept
    : data_(other.data_), width_(other.width_), height_(other.height_) {
    other.data_ = nullptr;
    other.width_ = 0;
    other.height_ = 0;
    std::cout << "[LOG] PixelBuffer move ctor (data transferred)\n";
}

PixelBuffer& PixelBuffer::operator=(const PixelBuffer& other) {
    if (this == &other) {
        return *this;
    }

    uint8_t* newData = nullptr;
    if (other.data_ != nullptr) {
        newData = new uint8_t[other.width_ * other.height_];
        std::memcpy(newData, other.data_, other.width_ * other.height_);
    }

    delete[] data_;
    data_ = newData;
    width_ = other.width_;
    height_ = other.height_;

    std::cout << "[LOG] PixelBuffer copy assignment: " << width_ << "x" << height_ << "\n";
    return *this;
}

PixelBuffer& PixelBuffer::operator=(PixelBuffer&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] data_;

    data_ = other.data_;
    width_ = other.width_;
    height_ = other.height_;

    other.data_ = nullptr;
    other.width_ = 0;
    other.height_ = 0;

    std::cout << "[LOG] PixelBuffer move assignment (data transferred)\n";
    return *this;
}

std::size_t PixelBuffer::width() const {
    return width_;
}

std::size_t PixelBuffer::height() const {
    return height_;
}

void PixelBuffer::clear(uint8_t value) {
    if (data_ != nullptr) {
        std::fill(data_, data_ + (width_ * height_), value);
    }
}

void PixelBuffer::setPixel(std::size_t x, std::size_t y, uint8_t value) {
    if (!inBounds(x, y)) {
        return;
    }
    data_[index(x, y)] = value;
}

uint8_t PixelBuffer::getPixel(std::size_t x, std::size_t y) const {
    if (!inBounds(x, y)) {
        return 0;
    }
    return data_[index(x, y)];
}

const uint8_t* PixelBuffer::data() const {
    return data_;
}

uint8_t* PixelBuffer::data() {
    return data_;
}

std::string PixelBuffer::toAscii(char empty, char filled) const {
    std::ostringstream out;

    for (std::size_t y = 0; y < height_; ++y) {
        for (std::size_t x = 0; x < width_; ++x) {
            out << (getPixel(x, y) == 0 ? empty : filled);
        }
        if (y + 1 < height_) {
            out << '\n';
        }
    }

    return out.str();
}

std::size_t PixelBuffer::index(std::size_t x, std::size_t y) const {
    return y * width_ + x;
}

bool PixelBuffer::inBounds(std::size_t x, std::size_t y) const {
    return x < width_ && y < height_;
}
