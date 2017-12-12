/**
 * My solution to problem whose original statement is at: https://practice.geeksforgeeks.org/problems/meta-strings
 *
 * Given two strings, the task is to check whether these strings are meta strings or not. Meta strings are the strings
 * which can be made equal by exactly one swap in any of the strings. Equal string are not considered here as Meta strings.

    Examples:

    Input : A = "geeks"
            B = "keegs"
    Output : 1
    By just swapping 'k' and 'g' in any of string,
    both will become same.

    Input : A = "rsting"
            B = "string
    Output : 0
 */

#ifndef SERGIOTEST_METASTRINGS_H
#define SERGIOTEST_METASTRINGS_H

#include <string>

namespace jr {
    class MetaStrings {
        void swapCharacters(std::string& word, int i, int j) {
            char temp = word.at(i);
            word.at(i) = word.at(j);
            word.at(j) = temp;
        }
    
        bool areMetaStrings(std::string word1, std::string word2) {
            if (word1.size() != word2.size()) {
                return false;
            }
    
            int swapIndex = -1;
            for(int i = 0; i < word1.size(); i++) {
                if(word1.at(i) != word2.at(i)) {
                    if(swapIndex == -1) {
                        swapIndex = i;
                    } else {
                        swapCharacters(word1, swapIndex, i);
                        //could be optimized by storing a count of unmatched characters, then if count is
                        //exactly 2 and word1[swapIndex] == word2[i] && word2[swapIndex] == word1[i], return true.
                        return word1 == word2;
                    }
                }
            }
            return false;
        }
    };
}

#endif //SERGIOTEST_METASTRINGS_H
