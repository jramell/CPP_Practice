/**
 * My solution to Cracking the Code Interview's 8.9. exercise
 *
 * Parens: Implement an algorithm to print all valid (Le., properly opened and closed) combinations of n pairs of parentheses.
       EXAMPLE
        Input: 3
        Output: ((())), (()()), (())(), ()(()), ()()()
 */
#ifndef SERGIOTEST_8_9_PARENS_H
#define SERGIOTEST_8_9_PARENS_H

#include <string>
#include <vector>

std::vector<std::string> possibleParens(std::string prefix, int openingsLeft, int closingsLeft) {
    std::vector<std::string> parens;
    if(openingsLeft == 0 && closingsLeft == 0) {
        parens.push_back(prefix);
        return parens;
    }
    if(openingsLeft > 0) {
        std::vector<std::string> withOpening = possibleParens(prefix + "(", openingsLeft-1, closingsLeft+1);
        parens.insert(parens.end(), withOpening.begin(), withOpening.end());
    }
    if(closingsLeft > 0) {
        std::vector<std::string> withClosing = possibleParens(prefix + ")", openingsLeft, closingsLeft-1);
        parens.insert(parens.end(), withClosing.begin(), withClosing.end());
    }
}

std::vector<std::string> possibleParens(int length) {
    return possibleParens("", length, 0);
}

#endif //SERGIOTEST_8_9_PARENS_H
