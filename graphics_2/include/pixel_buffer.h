#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

class PixelBuffer {
public:
    PixelBuffer();
    PixelBuffer(std::size_t width, std::size_t height);
    ~PixelBuffer();

    PixelBuffer(const PixelBuffer& other);
    PixelBuffer(PixelBuffer&& other) noexcept;

    PixelBuffer& operator=(const PixelBuffer& other);
    PixelBuffer& operator=(PixelBuffer&& other) noexcept;

    std::size_t width() const;
    std::size_t height() const;

    void clear(uint8_t value = 0);
    void setPixel(std::size_t x, std::size_t y, uint8_t value = 1);
    uint8_t getPixel(std::size_t x, std::size_t y) const;

    const uint8_t* data() const;
    uint8_t* data();

    std::string toAscii(char empty = ' ', char filled = '#') const;

private:
    std::size_t index(std::size_t x, std::size_t y) const;
    bool inBounds(std::size_t x, std::size_t y) const;

private:
    uint8_t* data_;
    std::size_t width_;
    std::size_t height_;
};
