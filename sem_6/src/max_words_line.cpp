#include "max_words_line.h"
#include "count_words.h"
#include <sstream>

std::pair<int, std::string> max_words_line(const std::string& text) {
    std::istringstream iss(text);
    std::string line;
    int line_number = 1;  
    int bestCount = -1;
    int bestLineNumber = 0;
    std::string bestLine;
    
    while (std::getline(iss, line)) {
        int count = count_words(line);
        if (count > bestCount) {
            bestCount = count;
            bestLineNumber = line_number;
            bestLine = line;
        }
        line_number++;
    }
    
    return {bestLineNumber, bestLine};  
}