#include "output_transpose.hpp"

#include <iostream>
#include <vector>
void output(std::vector<std::vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
