#include <catch2/catch_test_macros.hpp>

#include <memory>
#include <type_traits>

#include "canvas.h"
#include "circle.h"
#include "rectangle.h"

namespace {

std::size_t countPaintedPixels(const Canvas& scene) {
    std::size_t paintedPixels = 0;
    for (std::size_t y = 0; y < scene.buffer().height(); ++y) {
        for (std::size_t x = 0; x < scene.buffer().width(); ++x) {
            if (scene.buffer().getPixel(x, y) != 0) {
                ++paintedPixels;
            }
        }
    }
    return paintedPixels;
}

}  // namespace

TEST_CASE("Canvas copy disabled and move enabled") {
    REQUIRE(!std::is_copy_constructible<Canvas>::value);
    REQUIRE(!std::is_copy_assignable<Canvas>::value);
    REQUIRE(std::is_move_constructible<Canvas>::value);
}

TEST_CASE("PixelBuffer deep copy works") {
    PixelBuffer source(6, 4);
    source.setPixel(2, 1, 1);

    PixelBuffer copied(source);
    source.setPixel(2, 1, 0);

    REQUIRE(copied.getPixel(2, 1) == 1);
}

TEST_CASE("PixelBuffer copy assignment and move reset source") {
    PixelBuffer source(6, 4);
    source.setPixel(2, 1, 1);

    PixelBuffer assigned(1, 1);
    assigned = source;

    REQUIRE(assigned.width() == 6);
    REQUIRE(assigned.height() == 4);
    REQUIRE(assigned.getPixel(2, 1) == 1);

    PixelBuffer moved(std::move(assigned));
    REQUIRE(moved.width() == 6);
    REQUIRE(moved.height() == 4);
    REQUIRE(assigned.width() == 0);
    REQUIRE(assigned.height() == 0);
    REQUIRE(assigned.data() == nullptr);
}

TEST_CASE("Canvas renders shapes and supports move") {
    Canvas scene(24, 10);
    scene.addShape(std::make_unique<Circle>(6, 5, 3));
    scene.addShape(std::make_unique<Rectangle>(14, 2, 8, 6));

    scene.render();
    REQUIRE(countPaintedPixels(scene) > 0);

    Canvas movedScene(std::move(scene));
    REQUIRE(movedScene.shapeCount() == 2);
}
