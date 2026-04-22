#include "shapeFactory.h"
#include "circle.h"
#include "rectangle.h"
#include "exceptions.h"
#include <iostream>

std::optional<std::unique_ptr<Shape>> ShapeFactory::create(const std::string& type,
                                                           std::span<const ParamType> params) {
    try {
        if (type == "Circle") {
            if (params.size() < 1)
                throw std::invalid_argument("Circle requires a radius.");
            if (!std::holds_alternative<double>(params[0]))
                throw std::invalid_argument("Circle radius must be a double.");
            double r = std::get<double>(params[0]);
            return std::make_unique<Circle>(r);
        }
        else if (type == "Rectangle") {
            if (params.size() < 2)
                throw std::invalid_argument("Rectangle requires width and height.");
            if (!std::holds_alternative<double>(params[0]) ||
                !std::holds_alternative<double>(params[1]))
                throw std::invalid_argument("Rectangle sides must be doubles.");
            double w = std::get<double>(params[0]);
            double h = std::get<double>(params[1]);
            return std::make_unique<Rectangle>(w, h);
        }
        else {
            throw UnsupportedShapeTypeException("Unknown shape type: " + type);
        }
    }
    catch (const InvalidDimensionsException& e) {
        std::cerr << "Factory: dimension error — " << e.what() << "\n";
        return std::nullopt;
    }
    catch (const UnsupportedShapeTypeException& e) {
        std::cerr << "Factory: unsupported type — " << e.what() << "\n";
        return std::nullopt;
    }
    catch (const std::exception& e) {
        std::cerr << "Factory: other error — " << e.what() << "\n";
        return std::nullopt;
    }
}