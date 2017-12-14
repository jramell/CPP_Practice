/**
 * My solution with Time complexity O(n^3) and space complexity O(n) to problem
 * which statement is at: https://www.pramp.com/challenge/gKQ5zA52mySBOA5GALj9
 *
 * Array Quadruplet
    Given an unsorted array of integers arr and a number s, write a function findArrayQuadruplet that finds four numbers (quadruplet) in arr that sum up to s. Your function should return an array of these numbers in an ascending order. If such a quadruplet doesn’t exist, return an empty array.

    Note that there may be more than one quadruplet in arr whose sum is s. You’re asked to return the first one you encounter (considering the results are sorted).

    Explain and code the most efficient solution possible, and analyze its time and space complexities.

    Example:

    input:  arr = [2, 7, 4, 0, 9, 5, 1, 3], s = 20

    output: [0, 4, 7, 9] # The ordered quadruplet of (7, 4, 0, 9)
                         # whose sum is 20. Notice that there
                         # are two other quadruplets whose sum is 20:
                         # (7, 9, 1, 3) and (2, 4, 9, 5), but again you’re
                         # asked to return the just one quadruplet (in an
                         # ascending order)
    Constraints:

    [time limit] 5000ms

    [input] array.integer arr

    1 ≤ arr.length ≤ 100
    [input] integer s

    [output] array.integer
 */
#ifndef SERGIOTEST_ARRAYQUADRUPLETLINEARSPACE_H
#define SERGIOTEST_ARRAYQUADRUPLETLINEARSPACE_H

#include <vector>
#include <unordered_set>
#include <algorithm>

class ArrayQuadrupletLinearSpace {
    std::vector<int> canPairReach(const std::vector<int>& arr, int start, int end, int target) {
        std::vector<int> pair;
        std::unordered_set<int> seen;
        for(int i = start; i < end; i++) {
            int currentNumber = arr.at(i);
            if(seen.find(target - currentNumber) != seen.end()) {
                pair.push_back(std::min(currentNumber, target - currentNumber));
                pair.push_back(std::max(currentNumber, target - currentNumber));
                break;
            } else {
                seen.insert(currentNumber);
            }
        }
        return pair;
    }

    std::vector<int> findArrayQuadruplet(const std::vector<int> &arr, int s) {
        std::vector<int> quadruple;
        for(int i = 0; i < arr.size() && quadruple.empty(); i++) {
            for(int j = i+1; j < arr.size() && quadruple.empty(); j++) {
                int currentSum = arr.at(i) + arr.at(j);
                std::vector<int> currentPair = canPairReach(arr, j+1, arr.size(), s - currentSum);
                if(!currentPair.empty()) {
                    quadruple.push_back(arr.at(i));
                    quadruple.push_back(arr.at(j));
                    quadruple.push_back(currentPair.at(0));
                    quadruple.push_back(currentPair.at(1));
                }
            }
        }
        std::sort(quadruple.begin(), quadruple.end());
        return quadruple;
    }
};
#endif //SERGIOTEST_ARRAYQUADRUPLETLINEARSPACE_H
