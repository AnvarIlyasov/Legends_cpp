#pragma once

#include <stdexcept>
#include <string>

class InvalidDimensionsException : public std::domain_error {
public:
  explicit InvalidDimensionsException(const std::string &msg);
};

class OutOfCanvasBoundsException : public std::runtime_error {
public:
  explicit OutOfCanvasBoundsException(const std::string &msg);
};

class UnsupportedShapeTypeException : public std::runtime_error {
public:
  explicit UnsupportedShapeTypeException(const std::string &msg);
};