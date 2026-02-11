#include "check_square.hpp"

#include <iostream>
#include <vector>

bool checkSquareMatrix(const std::vector<std::vector<int>> &matrix) {
  const std::size_t rows = matrix.size();
  bool isSquare = true;

  for (const auto &row : matrix) {
    if (row.size() != rows) {
      isSquare = false;
      break;
    }
  }

  return isSquare;
}
