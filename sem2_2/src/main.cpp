#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "reading.h"
#include "count_lines.h"
#include "count_symbols.h"
#include "count_words.h"

int main(){
    std::cout<< "Введите ваш текст: ";
    std::string line;
    std::string text;
    text = read_text(line);

    int lines = count_lines(text);
    int symbols = count_symbols(text, lines);
    int words = count_words(text);

    std::cout<< "Количество символов: " << symbols << '\n';
    std::cout<< "Количество строк: " << lines<< '\n';
    std::cout<< "Количество слов: " << words<< '\n';
}