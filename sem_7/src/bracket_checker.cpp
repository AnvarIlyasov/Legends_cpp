#include "bracket_checker.h"

#include <stack>
#include <utility>

std::tuple<bool, std::vector<std::tuple<int, int, char>>> checkBrackets(const std::string& text) {
    std::stack<char> bracketStack;
    std::vector<std::pair<int, int>> positions;
    std::vector<std::tuple<int, int, char>> errors;

    int line = 1;
    int pos = 1;

    for (char symbol : text) {
        if (symbol == '\n') {
            ++line;
            pos = 1;
            continue;
        }

        if (symbol == '(' || symbol == '[') {
            bracketStack.push(symbol);
            positions.emplace_back(line, pos);
        } else if (symbol == ')') {
            if (bracketStack.empty() || bracketStack.top() != '(') {
                errors.emplace_back(line, pos, symbol);
            } else {
                bracketStack.pop();
                positions.pop_back();
            }
        } else if (symbol == ']') {
            if (bracketStack.empty() || bracketStack.top() != '[') {
                errors.emplace_back(line, pos, symbol);
            } else {
                bracketStack.pop();
                positions.pop_back();
            }
        }

        ++pos;
    }

    while (!bracketStack.empty()) {
        const std::pair<int, int> lastPosition = positions.back();
        errors.emplace_back(lastPosition.first, lastPosition.second, bracketStack.top());
        bracketStack.pop();
        positions.pop_back();
    }

    return {errors.empty(), errors};
}
