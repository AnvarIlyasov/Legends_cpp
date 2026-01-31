#include "count_symbols.h"
int count_symbols(std::string text, int count_lines){
    return text.size() - count_lines;
}