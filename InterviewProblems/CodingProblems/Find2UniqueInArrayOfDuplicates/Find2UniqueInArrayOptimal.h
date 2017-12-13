/**
 * My second solution to problem whose original statement is at: https://practice.geeksforgeeks.org/problems/finding-the-numbers
 * I implemented it after reading the hint: every bit set in XOR is set in only one of the unique elements.
 * This solution has a time complexity of O(n) and a space complexity of O(1).
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

#ifndef SERGIOTEST_FIND2UNIQUEINARRAYOPTIMAL_H
#define SERGIOTEST_FIND2UNIQUEINARRAYOPTIMAL_H

#include <algorithm>
#include <vector>

class Find2UniqueInArrayOptimal {
    std::vector<int> pairOfUniques(std::vector<int> numbers) {
        int totalXor = 0;
        for(int number : numbers) {
            totalXor ^= number;
        }
        int rightmostSetBitInXOR = totalXor & ~(totalXor-1); //any set bit in the XOR is ok tho
        int unique1 = 0;
        for(int number : numbers) {
            if(number & rightmostSetBitInXOR) { //number has same bit set as well
                //xor-ing all duplicates except one of the unique, which
                //means at the end of the loop, unique1 holds one of the
                //unique
                unique1 ^= number;
            }
        }
        int unique2 = totalXor ^ unique1;
        std::vector<int> pair(2);
        pair.at(0) = std::min(unique1, unique2);
        pair.at(1) = std::max(unique1, unique2);
        return pair;
    }
};

/**
 * The most important fact is that a 1 bit in the total XOR is a 1 bit in one of the unique
 * numbers. Since the unique numbers are distinct, there will be at least one set bit in the XOR.
 * Additionally, when we XOR all other numbers with that 1 bit, we're guaranteed to be XOR-ing a lot
 * of duplicates and only one of the unique. As a result, we end up with the unique number. Finally,
 * we XOR that with the totalXOR to get the other unique number.
 */
#endif //SERGIOTEST_FIND2UNIQUEINARRAYOPTIMAL_H
