#include "check_square.hpp"
#include "is_symmetric.hpp"
#include "output_transpose.hpp"
#include "read_matrix.hpp"
#include "transpose.hpp"

#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> matrix;
  readMatrix(matrix);

  const bool is_square = checkSquareMatrix(matrix);
  std::cout << "\n";

  if (!is_square) {
    std::cout << "Matrix is not square. Program stopped.\n";
    return 0;
  }

  is_symmentic(matrix, static_cast<int>(matrix.size()));
  transpose(matrix);
  output(matrix);

  return 0;
}
