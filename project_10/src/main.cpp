#include <iostream>
#include <memory>
#include <vector>

#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "triangle.h"

namespace {

std::vector<std::unique_ptr<Shape>> buildDemoShapes() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Triangle>(3.0, 4.0, 5.0));
    return shapes;
}

void printShapeMetrics(const Shape& shape) {
    std::cout << "Area: " << shape.area() << '\n';
    std::cout << "Perimeter: " << shape.perimeter() << "\n\n";
}

}  // namespace

int main() {
    const std::vector<std::unique_ptr<Shape>> shapes = buildDemoShapes();

    for (const std::unique_ptr<Shape>& shape : shapes) {
        shape->draw();
        printShapeMetrics(*shape);
    }

    return 0;
}
