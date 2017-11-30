/**
 * Solution to Cracking the Code Interview 6th Edition's problem 10.1.
 * Problem statement:
 *
 * You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B.
 * Write a method to merge B into A in sorted order.
 */
#include <vector>

using std::vector;
//Note for myself: The first time I solved this problem, I thought of a solution that seemed to work but
//really didn't. The result of testing it with too few testcases before trying to implement it.
void mergeSorted(vector<int>& A, vector<int>& B, int lastA) {
    int indexA = lastA;
    int indexB = B.size()-1;
    int sortedIndex = A.size()-1;
    while(indexB >= 0) {
        if(indexA >= 0 && A.at(indexA) > B.at(indexB)) {
            A.at(sortedIndex) = A.at(indexA);
            indexA--;
        } else {
            A.at(sortedIndex) = B.at(indexB);
            indexB--;
        }
        sortedIndex--;
    }
}
