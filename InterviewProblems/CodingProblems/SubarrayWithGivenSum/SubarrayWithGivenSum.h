#ifndef SERGIOTEST_SUBARRAYWITHGIVENSUM_H
#define SERGIOTEST_SUBARRAYWITHGIVENSUM_H

#include <vector>
#include <unordered_map>
#include <iostream>

/**
 * Solves problem whose original statement is at: http://www.geeksforgeeks.org/find-subarray-with-given-sum/
 *
 * Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number.

    Examples:

    Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
    Ouptut: Sum found between indexes 2 and 4

    Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
    Ouptut: Sum found between indexes 1 and 4

    Input: arr[] = {1, 4}, sum = 0
    Output: No subarray found
    There may be more than one subarrays with sum as the given sum. The following solutions print first such subarray.
 */
//Time complexity: O(n). Space complexity: O(1)
void printIndexRangeWithSumOnlyPositives(std::vector<int> numbers, int sum) {
    int currentSum = numbers.at(0);
    int start = 0;
    int end = 0;
    while(end < numbers.size()) {
        if(currentSum < sum) {
            end++;
            if(end >= numbers.size()) {
                break;
            }
            currentSum += numbers.at(end);
        } else if(currentSum > sum) {
            currentSum -= numbers.at(start);
            if(start == end) {
                end++;
                if(end >= numbers.size()) {
                    break;
                }
                currentSum += numbers.at(end);
            }
            start++;
        } else {
            std::cout << start+1 << " " << end+1 << std::endl;
            return;
        }
    }
    std::cout << "-1" << std::endl;
}

/**
 * Solves problem similar to the one the method above solves, but supports negative integers in the array.
 * Original problem statement: http://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
 *
 * Given an unsorted array of integers, find a subarray which adds to a given number. If there are more than one subarrays with sum as the given number, print any of them.

    Examples:

    Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
    Ouptut: Sum found between indexes 2 and 4

    Input: arr[] = {10, 2, -2, -20, 10}, sum = -10
    Ouptut: Sum found between indexes 0 to 3

    Input: arr[] = {-10, 0, 2, -2, -20, 10}, sum = 20
    Ouptut: No subarray with given sum exists
 */
//Time complexity = O(n). Space complexity = O(n)
void printIndexRangeWithSumWithNegatives(std::vector<int> numbers, int sum) {
    int currentSum = 0;
    //key is amount that can be removed, value is ending index of that sum amount
    std::unordered_map<int, int> removableAmounts;
    for(int i = 0; i < numbers.size(); i++) {
        currentSum += numbers.at(i);
        if(currentSum > sum) {
            auto iter = removableAmounts.find(currentSum - sum);
            if(iter != removableAmounts.end()) {
                std::cout << i - iter->second << std::endl;//" - " << iter->second << " " << i << std::endl;
                return;
            }
        } else if(currentSum == sum) {
            std::cout << i << std::endl;
            return;
        }
        removableAmounts.emplace(currentSum, i);
    }
    std::cout << "0" << std::endl;
}

#endif //SERGIOTEST_SUBARRAYWITHGIVENSUM_H
