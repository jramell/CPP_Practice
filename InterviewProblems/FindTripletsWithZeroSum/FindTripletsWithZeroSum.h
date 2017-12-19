/**
 * My solution to problem with statement: https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum
 *
 * Given an array A[] of n elements. The task is to complete the function which returns true if triplets exists in array A[] whose sum is zero else returns false.

Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. The first line of each test case contains an integer N, denoting the number of elements in array. The second line of each test case contains N space separated values of the array A[].


    Output:
    For each test case in a new line output will be 1 if triplet exists else 0.

    Constrains:
    1<=T<=100
    1<=N<=1000
    -1000<=A[]<=1000


    Example(To be used only for expected output) :
    Input:
    2
    5
    0 -1 2 -3 1
    3
    1 2 3
    Output:
    1
    0
 */
#ifndef SERGIOTEST_FINDTRIPLETSWITHZEROSUM_H
#define SERGIOTEST_FINDTRIPLETSWITHZEROSUM_H

#include <unordered_set>

bool findPairWithSum(int arr[], int n, int startIndex, int sum) {
    std::unordered_set<int> seen;
    for(int i = startIndex; i < n; i++) {
        if(seen.find(sum - arr[i]) != seen.end()) {
            return true;
        } else {
            seen.insert(arr[i]);
        }
    }
    return false;
}

bool findTriplets(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        if(findPairWithSum(arr, n, i+1, -1*arr[i])) {
            return true;
        }
    }
    return false;
}

#endif //SERGIOTEST_FINDTRIPLETSWITHZEROSUM_H
