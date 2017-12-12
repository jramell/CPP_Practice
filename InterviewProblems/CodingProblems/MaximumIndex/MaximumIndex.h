/**
 * Solution to problem whose original statement is at: http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
 *
 * Given an array arr[], find the maximum j – i such that arr[j] > arr[i].

    Examples:

      Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
      Output: 6  (j = 7, i = 1)

      Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
      Output: 8 ( j = 8, i = 0)

      Input:  {1, 2, 3, 4, 5, 6}
      Output: 5  (j = 5, i = 0)

      Input:  {6, 5, 4, 3, 2, 1}
      Output: -1
 */

#ifndef SERGIOTEST_MAXIMUMINDEX_H
#define SERGIOTEST_MAXIMUMINDEX_H

#include <vector>

namespace jr {
    int maximumIndexQuadratic(std::vector<int> numbers) {
        int maximumIndex = 0;
        for(int i = 0; i < numbers.size(); i++) {
            for(int j = numbers.size()-1; j >= 0; j--) {
                if(numbers.at(j) >= numbers.at(i)) {
                    maximumIndex = std::max(maximumIndex, j - i);
                    break;
                }
            }
        }
        return maximumIndex;
    }

    int maximumIndexLinear(std::vector<int> numbers) {
        std::vector<int> maxFromRight(numbers.size());
        std::vector<int> minFromLeft(numbers.size());
        minFromLeft.at(0) = numbers.at(0);
        maxFromRight.at(numbers.size()-1) = numbers.back();
        for(int i = 1; i < numbers.size(); i++) {
            minFromLeft.at(i) = std::min(numbers.at(i), minFromLeft.at(i-1));
        }
        for(int i = numbers.size()-2; i >= 0; i--) {
            maxFromRight.at(i) = std::max(numbers.at(i), maxFromRight.at(i+1));
        }
        int i = 0;
        int j = 0;
        int maximumIndex = 0;
        while(j < numbers.size()) {
            if(maxFromRight.at(j) >= minFromLeft.at(i)) {
                maximumIndex = std::max(maximumIndex, j - i);
                j++;
            } else {
                i++;
            }
        }
        return maximumIndex;
    }
}

#endif //SERGIOTEST_MAXIMUMINDEX_H
