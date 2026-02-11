#include "transpose.hpp"

#include <iostream>
#include <vector>

void transpose(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}
