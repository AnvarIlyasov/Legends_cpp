#include "count_lines.h"
int count_lines(std::string text){
    return std::count(text.begin(), text.end(), '\n');
}