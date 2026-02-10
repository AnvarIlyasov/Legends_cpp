#include "check_square.hpp"
#include "is_symmetric.hpp"
#include "output_transpose.hpp"
#include "read_matrix.hpp"
#include "transpose.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("readMatrix reads matrix from stdin until empty line", "[read]") {
  std::istringstream fake_input("1 2 3\n4 5 6\n\n");
  std::streambuf *old_cin = std::cin.rdbuf(fake_input.rdbuf());

  std::vector<std::vector<int>> matrix;
  readMatrix(matrix);

  std::cin.rdbuf(old_cin);

  REQUIRE(matrix.size() == 2);
  REQUIRE(matrix[0] == std::vector<int>{1, 2, 3});
  REQUIRE(matrix[1] == std::vector<int>{4, 5, 6});
}

TEST_CASE("checkSquareMatrix prints different output for square/non-square",
          "[square]") {
  std::vector<std::vector<int>> square{{1, 2}, {3, 4}};
  std::vector<std::vector<int>> non_square{{1, 2, 3}, {4, 5, 6}};

  std::ostringstream out_square;
  std::streambuf *old_cout = std::cout.rdbuf(out_square.rdbuf());
  checkSquareMatrix(square);
  std::cout.rdbuf(old_cout);

  std::ostringstream out_non_square;
  old_cout = std::cout.rdbuf(out_non_square.rdbuf());
  checkSquareMatrix(non_square);
  std::cout.rdbuf(old_cout);

  REQUIRE_FALSE(out_square.str().empty());
  REQUIRE_FALSE(out_non_square.str().empty());
  REQUIRE(out_square.str() != out_non_square.str());
}

TEST_CASE("is_symmentic prints different message for symmetric/non-symmetric",
          "[symmetric]") {
  std::vector<std::vector<int>> symmetric{{1, 2}, {2, 3}};
  std::vector<std::vector<int>> non_symmetric{{1, 9}, {2, 3}};

  std::ostringstream out_symmetric;
  std::streambuf *old_cout = std::cout.rdbuf(out_symmetric.rdbuf());
  int sym_result = is_symmentic(symmetric, static_cast<int>(symmetric.size()));
  std::cout.rdbuf(old_cout);

  std::ostringstream out_non_symmetric;
  old_cout = std::cout.rdbuf(out_non_symmetric.rdbuf());
  int non_sym_result =
      is_symmentic(non_symmetric, static_cast<int>(non_symmetric.size()));
  std::cout.rdbuf(old_cout);

  REQUIRE(sym_result == 0);
  REQUIRE(non_sym_result == 0);
  REQUIRE(out_symmetric.str() != out_non_symmetric.str());
}

TEST_CASE("transpose transposes square matrix in-place", "[transpose]") {
  std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  transpose(matrix);

  REQUIRE(matrix ==
          std::vector<std::vector<int>>{{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
}

TEST_CASE("output prints matrix row by row", "[output]") {
  std::vector<std::vector<int>> matrix{{1, 2}, {3, 4}};

  std::ostringstream out;
  std::streambuf *old_cout = std::cout.rdbuf(out.rdbuf());
  output(matrix);
  std::cout.rdbuf(old_cout);

  REQUIRE(out.str() == "1 2 \n3 4 \n");
}
