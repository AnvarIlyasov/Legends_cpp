#include <iostream>
#include <memory>
#include <type_traits>

#include "canvas.h"
#include "circle.h"
#include "rectangle.h"

int main() {
    static_assert(!std::is_copy_constructible<Canvas>::value,
                  "Canvas copy constructor must be deleted");
    static_assert(!std::is_copy_assignable<Canvas>::value,
                  "Canvas copy assignment must be deleted");
    static_assert(std::is_move_constructible<Canvas>::value,
                  "Canvas should be move constructible");

    Canvas canvas(40, 12);
    canvas.addShape(std::make_unique<Circle>(7, 5, 3));
    canvas.addShape(std::make_unique<Rectangle>(20, 2, 12, 7));

    std::cout << "Canvas created with " << canvas.shapeCount() << " shapes.\n";

    std::cout << "Copying buffer...\n";
    PixelBuffer original(100, 100);
    original.setPixel(5, 5, 1);

    PixelBuffer copied(original);
    PixelBuffer assigned(8, 8);
    assigned = original;

    original.setPixel(5, 5, 0);
    std::cout << "Original(5,5): " << static_cast<int>(original.getPixel(5, 5)) << '\n';
    std::cout << "Copied(5,5): " << static_cast<int>(copied.getPixel(5, 5)) << '\n';
    std::cout << "Assigned size: " << assigned.width() << "x" << assigned.height()
              << "\n";

    std::cout << "Moving canvas...\n";
    Canvas movedCanvas(std::move(canvas));

    movedCanvas.render();
    std::cout << "Canvas rendered:\n";
    movedCanvas.print(std::cout);

    std::cout << "Destructors called in reverse order. No leaks.\n";
    return 0;
}
