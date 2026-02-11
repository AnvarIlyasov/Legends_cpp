#include "read_matrix.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


void readMatrix(std::vector<std::vector<int>> &a) {
  a.clear();
  std::string line;

  while (std::getline(std::cin, line)) {
    if (line.empty())
      break;
    std::istringstream iss(line);
    std::vector<int> row;
    int x;
    while (iss >> x) {
      row.push_back(x);
    }
    if (!row.empty()) {
      a.push_back(std::move(row));
    }
  }
}
