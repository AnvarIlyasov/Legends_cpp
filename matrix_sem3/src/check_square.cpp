#include "check_square.hpp"

#include <iostream>
#include <vector>

void checkSquareMatrix(const std::vector<std::vector<int>> &matrix) {
  std::size_t rows = matrix.size();

  bool isSquare = true;

  for (const auto &row : matrix) {
    if (row.size() != rows) {
      isSquare = false;
      break;
    }
  }

  if (isSquare)
    std::cout << "да";
  else
    std::cout << "нет";
}
