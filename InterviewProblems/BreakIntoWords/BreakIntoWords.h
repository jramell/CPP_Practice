#ifndef SERGIOTEST_BREAKINTOWORDS_H
#define SERGIOTEST_BREAKINTOWORDS_H

#include <string>
#include <unordered_set>

/**
 * Solution to problem described in: https://youtu.be/oWbUtlUhwa8?t=721
 * @param givenString string to break into words
 * @param dictionary dictionary with certain valid words
 * @return empty string if givenString can't be broken up into valid words. The broken up string if it can.
 */
    std::string breakIntoWords(std::string givenString, const std::unordered_set<std::string> &dictionary);

#endif //SERGIOTEST_BREAKINTOWORDS_H
