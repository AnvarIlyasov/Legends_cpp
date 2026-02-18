#include "count_symbols.h"
#include <string>
int count_symbols(std::string text, int line_count){
    return text.size() - line_count;
}