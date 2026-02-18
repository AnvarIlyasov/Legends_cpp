
#include "count_lines.h"
#include <algorithm>

int count_lines(std::string text) {
    return std::count(text.begin(), text.end(), '\n');
}