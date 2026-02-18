#include "count_words.h"
#include <cstring>
#include <vector>

int count_words(std::string text) {
  int count = 0;
  std::string delimiters = ", ;\n.\"'?!)(*\t%$#@:-=+^&<>/{}[]|)~";

  std::vector<char> text_copy(text.begin(), text.end());
  text_copy.push_back('\0');

  char *token = strtok(text_copy.data(), delimiters.c_str());
  while (token != nullptr) {
    count++;
    token = strtok(nullptr, delimiters.c_str());
  }
  return count;
}