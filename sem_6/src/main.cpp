#include "count_lines.h"
#include "count_symbols.h"
#include "count_words.h"
#include "max_words_line.h"
#include "reading.h"
#include <fstream>
#include <iostream>
#include <string>

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

  auto [line_num, line_text] = max_words_line(text);

  if (line_num > 0) {
    std::cout << "Строка с максимумом слов: (строка " << line_num << ") "
              << line_text << '\n';
  } else {
    std::cout << "Текст пуст или не содержит строк\n";
  }

  return 0;
}