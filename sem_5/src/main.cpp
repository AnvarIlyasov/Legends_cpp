#include <fstream>
#include <iostream>
#include <string>
#include "reading.h"
#include "count_lines.h"
#include "count_symbols.h"
#include "count_words.h"
#include "max_words_line.h"

int main() {
    std::ifstream file("/Users/andrey/Desktop/input.txt");
    if (!file.is_open()) {
        std::cout << "Файл не открыт\n";
        return 1;
    }

    std::string text = read_text(file);

    int lines = count_lines(text);
    int symbols = count_symbols(text, lines);
    int words = count_words(text);

    std::cout << "Количество символов: " << symbols << '\n';
    std::cout << "Количество строк: " << lines << '\n';
    std::cout << "Количество слов: " << words << '\n';

    std::cout << "Строка с максимумом слов: " << max_words_line(text) << '\n';
    
    return 0;
}