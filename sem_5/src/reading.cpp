#include "reading.h"
#include <string>
#include <istream>

std::string read_text(std::istream& in) {
    std::string text;
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) {
            break;
        }
        text += line + "\n";
    }
    return text;
}
