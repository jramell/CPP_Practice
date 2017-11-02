#ifndef SERGIOTEST_SINGLENUMBER2_H
#define SERGIOTEST_SINGLENUMBER2_H

#include <vector>

namespace jr {
        /**
         * Original problem: https://www.interviewbit.com/problems/single-number-ii/
         * Given an array of integers, every element appears thrice except for one which occurs once.
         * Find that element which does not appear thrice.
         * @param numbers array of integers
         * @return element which occurs once in the array
         */
        int singleNumber(const std::vector<int>& numbers);
}

#endif //SERGIOTEST_SINGLENUMBER2_H
