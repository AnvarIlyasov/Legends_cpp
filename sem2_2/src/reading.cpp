#include "reading.h"

std::string read_text(std::string line){
    std::string text;
     while(true){
        std::getline(std::cin, line);
        if (line.empty()){
            break;
        }
        text += line + "\n";
    }
    return text;
}