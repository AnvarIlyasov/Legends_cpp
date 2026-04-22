#pragma once

#include <memory>
#include <string>
#include <optional>
#include <variant>
#include <span>
#include "shape.h"

class ShapeFactory {
public:
    using ParamType = std::variant<double, std::string>;

    static std::optional<std::unique_ptr<Shape>> create(const std::string& type,
                                                        std::span<const ParamType> params);
};