#include <catch2/catch_test_macros.hpp>
#include "calculator.h"

TEST_CASE("Remainder handles various cases") {
    SECTION("Basic"){
        REQUIRE(sum(10, 3) == 13);
    }
    
    SECTION("Negative numbers"){
    REQUIRE(sum(-10, 3) == -7);     
    } 

    SECTION("sum 0"){
        REQUIRE(sum(10, 0) == 10);
    }

}