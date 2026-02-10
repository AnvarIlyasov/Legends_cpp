#include "is_symmetric.hpp"

#include <iostream>
#include <vector>
int is_symmentic(std::vector<std::vector<int>> matrix, int lenght) {
  for (int i = 0; i < lenght; i++) {
    for (int j = i + 1; j < lenght; j++)
      if (matrix[i][j] != matrix[j][i]) {
        std::cout << "Матрица не симметрична\n";
        return 0;
      }
  }
  std::cout << "Матрица симметрична\n";
  return 0;
}
