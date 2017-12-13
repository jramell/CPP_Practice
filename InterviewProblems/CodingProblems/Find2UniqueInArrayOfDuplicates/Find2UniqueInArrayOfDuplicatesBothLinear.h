/**
 * My first solution to problem whose original statement is at: https://practice.geeksforgeeks.org/problems/finding-the-numbers
 * This solution has a time and space complexity of O(n).
 *
 * You are given an array A containing 2*N+2 positive numbers, out of which N numbers are repeated exactly once and the other two numbers occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.

    Input :
    The first line contains a value T, which denotes the number of test cases. Then T test cases follow .The first line of each test case contains a value N. The next line contains 2*N+2 space separated integers.

    Output :
    Print in a new line the two numbers in ascending order.

    Constraints :
    1<=T<=100
    1<=N<=10^6
    1<=A[i]<=5*10^8

    Example:
    Input :
    2
    2
    1 2 3 2 1 4
    1
    2 1 3 2

    Output :
    3 4
    1 3
 */
#ifndef SERGIOTEST_FIND2UNIQUEINARRAYOFDUPLICATESBOTHLINEAR_H
#define SERGIOTEST_FIND2UNIQUEINARRAYOFDUPLICATESBOTHLINEAR_H

#include <vector>
#include <unordered_set>

class Find2UniqueInArrayOfDuplicatesBothLinear {
    template <typename T>
    void swapIndexes(std::vector<T>& array, int i, int j) { 
        T temp = array.at(i);
        array.at(i) = array.at(j);
        array.at(j) = temp;
    }
    
    std::vector<int> pairOfUniques(std::vector<int> numbers) {
        std::unordered_set<int> uniques;
        for(int number : numbers) {
            auto iter = uniques.find(number);
            if(iter != uniques.end()) {
                uniques.erase(iter);
            } else {
                uniques.insert(number);
            }
        }
        std::vector<int> pairOfUniques;
        for(int unique : uniques) {
            pairOfUniques.push_back(unique);
        }
        if(pairOfUniques.at(0) > pairOfUniques.at(1)) {
            swapIndexes(pairOfUniques, 0, 1);
        }
        return pairOfUniques;
    }
};

#endif //SERGIOTEST_FIND2UNIQUEINARRAYOFDUPLICATESBOTHLINEAR_H
