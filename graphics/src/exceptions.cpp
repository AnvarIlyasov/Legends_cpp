#include "exceptions.h"

InvalidDimensionsException::InvalidDimensionsException(const std::string &msg)
    : std::domain_error(msg) {}

OutOfCanvasBoundsException::OutOfCanvasBoundsException(const std::string &msg)
    : std::runtime_error(msg) {}

UnsupportedShapeTypeException::UnsupportedShapeTypeException(
    const std::string &msg)
    : std::runtime_error(msg) {}