#ifndef SERGIOTEST_BALANCEDBRACKETS_H
#define SERGIOTEST_BALANCEDBRACKETS_H

#include <string>

namespace jr {
    /**
     * @param openingBracket opening bracket you want the matching closing bracket to. Valid: '(', '[', '{'
     * @return ')' for openingBracket = '(', ']' for '[', '}' for '{'. For other values, '\0'
     */
    char matchingClosingBracket(char openingBracket);

    /**
     * Solves Cracking The Code Interview's Balanced Brackets problem on HackerRank: hackerrank.com/challenges/ctci-balanced-brackets
     * A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
     *
     * Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) occurs to the left of a closing
     * bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and ().
     *
     * A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not
     * balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced
     * opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ]
     *
     * By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:
     *      It contains no unmatched brackets
     *      The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets
     *
     * Given  strings of brackets, determine whether each sequence of brackets is balanced. Return true if they are, false otherwise.
     *
     * Example 1: expression = "{[()]}"
     *            Output = true -- The string {[()]} meets both criteria for being a balanced string
     *
     * Example 2: expression = "{[(])}"
     *            Output = false
     *            The string {[(])} is not balanced, because the brackets enclosed by the matched pairs [(] and (]) are not balanced
     *
     * @param expression string whose balanced state must be checked
     * @return true if expression is balanced, false if it's not
     */
    bool is_balanced(std::string expression);
}

#endif //SERGIOTEST_BALANCEDBRACKETS_H
