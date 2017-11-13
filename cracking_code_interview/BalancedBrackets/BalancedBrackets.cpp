#include "BalancedBrackets.h"
#include <stack>

char matchingClosingBracket(char openingBracket) {
    char closingBracket = '\0';
    if(openingBracket == '(') {
        closingBracket = ')';
    } else if(openingBracket == '[') {
        closingBracket = ']';
    } else if (openingBracket == '{') {
        closingBracket = '}';
    }
    return closingBracket;
}

bool is_balanced(std::string expression) {
    std::stack<char> closingBracketOrder;
    closingBracketOrder.push(matchingClosingBracket(expression.at(0)));
    for(int i = 1; i < expression.size(); i++) {
        char currentCharacter = expression.at(i);
        char matchingBracket = matchingClosingBracket(currentCharacter);
        if(!closingBracketOrder.empty() && currentCharacter == closingBracketOrder.top()) {
            closingBracketOrder.pop();
        } else if(matchingBracket != '\0') {
            closingBracketOrder.push(matchingBracket);
        } else {
            return false;
        }
    }
    return closingBracketOrder.empty();
}
