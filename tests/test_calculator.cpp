#include <catch2/catch_test_macros.hpp>
#include "calculator.h"

TEST_CASE("Remainder works") {
    REQUIRE(remainder(10, 3) == 1);
    REQUIRE(remainder(20, 5) == 0);
    REQUIRE(remainder(7, 4) == 3);
}
