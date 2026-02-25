#pragma once

#include <string>
#include <tuple>
#include <vector>

std::tuple<bool, std::vector<std::tuple<int, int, char>>> checkBrackets(const std::string& text);
