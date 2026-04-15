#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "triangle.h"

namespace {

class ProbeShape : public Shape {
public:
    explicit ProbeShape(int* destroyedCount) : destroyedCount_(destroyedCount) {
    }

    ~ProbeShape() override {
        ++(*destroyedCount_);
    }

    void draw() const override {
    }

    double area() const override {
        return 0.0;
    }

    double perimeter() const override {
        return 0.0;
    }

private:
    int* destroyedCount_ = nullptr;
};

}  // namespace

TEST_CASE("Shapes compute area and perimeter") {
    const Circle circle(2.0);
    const Rectangle rectangle(4.0, 5.0);
    const Triangle triangle(3.0, 4.0, 5.0);

    REQUIRE(circle.area() == Catch::Approx(12.566370614359172).epsilon(1e-9));
    REQUIRE(circle.perimeter() == Catch::Approx(12.566370614359172).epsilon(1e-9));

    REQUIRE(rectangle.area() == Catch::Approx(20.0));
    REQUIRE(rectangle.perimeter() == Catch::Approx(18.0));

    REQUIRE(triangle.area() == Catch::Approx(6.0));
    REQUIRE(triangle.perimeter() == Catch::Approx(12.0));
}

TEST_CASE("Polymorphic calls dispatch correctly") {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(1.0));
    shapes.push_back(std::make_unique<Rectangle>(2.0, 3.0));
    shapes.push_back(std::make_unique<Triangle>(3.0, 4.0, 5.0));

    double areaSum = 0.0;
    double perimeterSum = 0.0;
    for (const std::unique_ptr<Shape>& shape : shapes) {
        areaSum += shape->area();
        perimeterSum += shape->perimeter();
    }

    REQUIRE(areaSum == Catch::Approx(3.141592653589793 + 6.0 + 6.0).epsilon(1e-9));
    REQUIRE(perimeterSum == Catch::Approx(6.283185307179586 + 10.0 + 12.0).epsilon(1e-9));
}

TEST_CASE("Draw prints textual representation") {
    const Rectangle rectangle(7.0, 8.0);
    std::ostringstream output;
    std::streambuf* oldBuffer = std::cout.rdbuf(output.rdbuf());

    rectangle.draw();
    std::cout.rdbuf(oldBuffer);

    const std::string text = output.str();
    REQUIRE(text.find("Rectangle") != std::string::npos);
    REQUIRE(text.find("width=7") != std::string::npos);
    REQUIRE(text.find("height=8") != std::string::npos);
}

TEST_CASE("Virtual destructor works with unique_ptr<Shape>") {
    int destroyedCount = 0;
    {
        std::unique_ptr<Shape> shape = std::make_unique<ProbeShape>(&destroyedCount);
    }
    REQUIRE(destroyedCount == 1);
}
