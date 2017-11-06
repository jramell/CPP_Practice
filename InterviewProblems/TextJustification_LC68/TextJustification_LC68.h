//
// Created by Sergio on 11/6/2017.
//

#ifndef SERGIOTEST_TEXTJUSTIFICATION_LC68_H
#define SERGIOTEST_TEXTJUSTIFICATION_LC68_H

#include <vector>
#include <string>
namespace jr {
    /**
     * Original problem: https://leetcode.com/problems/text-justification/description
     * Given an array of words and a length L, format the text such that each line has exactly L characters
     * and is fully (left and right) justified.
     *
     * You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
     * Pad extra spaces ' ' when necessary so that each line has exactly L characters.
     *
     * Extra spaces between words should be distributed as evenly as possible. If the number of
     * spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more
     * spaces than the slots on the right.
     *
     * For the last line of text, it should be left justified and no extra space is inserted between words.
     *
     * Example: words: ["This", "is", "an", "example", "of", "text", "justification."] - L: 16
     * Return:
     * ["This    is    an",
     *  "example  of text",
     *  "justification.  "]
     *
     * @param words array of words
     * @param lineLength length L
     */
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int lineLength);
};


#endif //SERGIOTEST_TEXTJUSTIFICATION_LC68_H
