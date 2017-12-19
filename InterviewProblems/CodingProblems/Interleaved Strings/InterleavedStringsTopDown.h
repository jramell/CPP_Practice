/**
 * My top-down DP solution to problem with statement: https://practice.geeksforgeeks.org/problems/interleaved-strings
 *
 * Given three strings A, B and C your task is to complete the function isInterleave which returns true if C is an interleaving of A and B else returns false. C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.

    Input:
    The first line of input contains an input T denoting the no of test cases. Then T test cases follow. Each test case contains three space separated strings A, B, C.

    Output:
    For each test case output will be 1 if C is interleaving of string A and B else 0.

    Constraints:
    1<=T<=100
    1<=length of A, B, C <=100

    Example(To be used only for expected output):
    Input:
    2
    YX  X  XXY
    XY X XXY

    Output
    0
    1

    Explanation:
    1. For first test case XXY is not interleaving of YX and X
    2. For the sec test case XXY is interleaving of XY and X.
 */
#ifndef SERGIOTEST_INTERLEAVEDSTRINGSTOPDOWN_H
#define SERGIOTEST_INTERLEAVEDSTRINGSTOPDOWN_H

#include <string>
#include <vector>

struct Triplet {
    int number1;
    int number2;
    int number3;
    Triplet(int n1, int n2, int n3) : number1(n1), number2(n2), number3(n3) { }
};

bool isInterleaveHelper(const std::string A, const std::string B, const std::string C,
                        int startA, int startB, int startC, std::vector<std::vector<std::vector<int>>> cache) {

    if(cache.at(startA).at(startB).at(startC) != -1) {
        return cache.at(startA).at(startB).at(startC);
    }
    bool ans = (startA < A.size() && startC < C.size()) && A.at(startA) == C.at(startC)
               && isInterleaveHelper(A, B, C, startA+1, startB, startC+1, cache)
               ||
               (startB < B.size() && startC < C.size()) && B.at(startB) == C.at(startC)
               && isInterleaveHelper(A, B, C, startA, startB+1, startC+1, cache);
    cache.at(startA).at(startB).at(startC) = ans;
    return ans;
}

bool isInterleave(string A, string B, string C) {
    std::vector<std::vector<std::vector<int>>> cache(A.size()+1, std::vector<std::vector<int>>(B.size()+1, std::vector<int>(C.size()+1, -1)));
    cache.at(A.size()).at(B.size()).at(C.size()) = true;
    return isInterleaveHelper(A, B, C, 0, 0, 0, cache);
}
#endif //SERGIOTEST_INTERLEAVEDSTRINGSTOPDOWN_H
