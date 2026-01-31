#include "count_words.h"
int count_words(std::string text){
    int count_words = 0;
        std::string delimiters = ", ;\n.\"'?!)(*\t%$#@:-=+^&<>/{}[]|)~";
        char* token = strtok(&text[0], delimiters.c_str());
        while(token != nullptr){
            token = strtok(nullptr, delimiters.c_str());
            count_words++;
        }
    return count_words;
}