#include <catch2/catch_test_macros.hpp>

#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "bracket_checker.h"
#include "frequency_dict.h"
#include "word_splitter.h"

TEST_CASE("Brackets are balanced for valid input") {
    const std::string text = "a(b[c]d)\n[()]";
    const auto result = checkBrackets(text);

    CHECK(std::get<0>(result));
    CHECK(std::get<1>(result).empty());
}

TEST_CASE("Bracket checker reports errors for invalid input") {
    const std::string text = "([)]";
    const auto result = checkBrackets(text);

    CHECK_FALSE(std::get<0>(result));
    CHECK_FALSE(std::get<1>(result).empty());
}

TEST_CASE("Word splitting and frequency dict") {
    const std::string text = "Hello, hello world! [test] world";
    const std::vector<std::string> words = splitIntoWords(text);

    REQUIRE(words.size() == 5);
    CHECK(words[0] == "hello");
    CHECK(words[1] == "hello");
    CHECK(words[2] == "world");
    CHECK(words[3] == "test");
    CHECK(words[4] == "world");

    const std::unordered_map<std::string, int> dict = buildFrequencyDict(words);
    CHECK(dict.at("hello") == 2);
    CHECK(dict.at("world") == 2);
    CHECK(dict.at("test") == 1);
}
