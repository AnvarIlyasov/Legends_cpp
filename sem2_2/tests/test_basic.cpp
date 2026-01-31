#include <catch2/catch_test_macros.hpp>
#include "reading.h"
#include "count_lines.h"
#include "count_symbols.h"
#include "count_words.h"

TEST_CASE("Count Lines - Basic Functionality") {
    REQUIRE(count_lines("") == 0);
    REQUIRE(count_lines("Single line") == 0);
    REQUIRE(count_lines("Line 1\nLine 2\nLine 3\n") == 3);
}

TEST_CASE("Count Symbols - Character Counting") {
    std::string text1 = "Hello";
    std::string text2 = "Hello\nWorld\n";
    int lines2 = count_lines(text2);
    
    REQUIRE(count_symbols(text1, 0) == 5);
    REQUIRE(count_symbols(text2, lines2) == 10);
}

TEST_CASE("Count Words - Word Detection") {
    REQUIRE(count_words("") == 0);
    REQUIRE(count_words("Hello") == 1);
    REQUIRE(count_words("Hello World") == 2);
    REQUIRE(count_words("Hello, World! How are you?") == 5);
}

TEST_CASE("Integration - All Functions Together") {
    std::string text = "First line\nSecond line here\n";
    int lines = count_lines(text);
    int symbols = count_symbols(text, lines);
    int words = count_words(text);
    
    REQUIRE(lines == 2);
    REQUIRE(symbols == 28); 
    REQUIRE(words == 5);
}