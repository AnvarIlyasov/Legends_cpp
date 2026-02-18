#include <catch2/catch_test_macros.hpp>
#include "count_lines.h"
#include "count_symbols.h"
#include "count_words.h"
#include "max_words_line.h"
#include <sstream>
#include <string>

TEST_CASE("Test count_lines", "[lines]") {
    REQUIRE(count_lines("") == 0);
    REQUIRE(count_lines("Hello world") == 0);
    REQUIRE(count_lines("Hello\nWorld") == 1);
    REQUIRE(count_lines("Line1\nLine2\nLine3") == 2);
    REQUIRE(count_lines("Line1\nLine2\nLine3\n") == 3);
}

TEST_CASE("Test count_words", "[words]") {
    REQUIRE(count_words("") == 0);
    REQUIRE(count_words("Hello") == 1);
    REQUIRE(count_words("Hello world") == 2);
    REQUIRE(count_words("Hello, world! How are you?") == 5);
    REQUIRE(count_words("Word1\nWord2 Word3\nWord4") == 4);
}

TEST_CASE("Test count_symbols", "[symbols]") {
    std::string text1 = "Hello";
    REQUIRE(count_symbols(text1, 0) == 5);
    
    std::string text2 = "Hello\nWorld";
    int lines2 = count_lines(text2);
    REQUIRE(count_symbols(text2, lines2) == 10); // 5+5+1(\n)=11 - 1(line)=10
    
    std::string text3 = "Hello\nWorld\n";
    int lines3 = count_lines(text3);
    REQUIRE(count_symbols(text3, lines3) == 10); // 5+5+2(\n)=12 - 2(lines)=10
}

TEST_CASE("Test max_words_line", "[maxline]") {
    std::string text1 = "Hello world\nHow are you\nFine";
    REQUIRE(max_words_line(text1) == "How are you");
    
    std::string text2 = "One two three four\nOne two\nOne two three";
    REQUIRE(max_words_line(text2) == "One two three four");
    
    std::string text3 = "Short\nMedium line here\nLongest line with many words here";
    REQUIRE(max_words_line(text3) == "Longest line with many words here");
}

TEST_CASE("Test read_text", "[read]") {
    std::istringstream iss1("Hello world");
    REQUIRE(read_text(iss1) == "Hello world\n");
    
    std::istringstream iss2("Line1\nLine2\nLine3");
    REQUIRE(read_text(iss2) == "Line1\nLine2\nLine3\n");
    
    std::istringstream iss3("");
    REQUIRE(read_text(iss3) == "");
}