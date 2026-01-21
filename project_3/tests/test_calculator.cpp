#include <catch2/catch_test_macros.hpp>
#include "calculator.h"

TEST_CASE("Remainder handles various cases") {
    SECTION("Basic"){
        REQUIRE(rem(10, 3) == 1);
    }
    
    SECTION("Negative numbers"){
    REQUIRE(rem(-10, 3) == 2); // -10 % 3 = -1, but we want 2     
    } 

    SECTION("Division on 0"){ // Division on 0 - throw exception Деление на ноль - должно бросать исключение
        REQUIRE(rem(10, 0) == -1);
    }

    SECTION("Other cases"){
        REQUIRE(rem(0, 5) == 0);
        REQUIRE(rem(5, 5) == 0);
    }
}