/**
 * My solution to Cracking The Code Interview exercise 10.4. It was the one I thought of before reading the
 * book's solution. It has a Time Complexity of O(log n) and a Space Complexity of O(1)like the book's, but
 * lacks the same optimizations and is therefore slower despite having the same worst case performance.
 *
 * Problem statement:
 * Sorted Search, No Size: You are given an array-like data structure Listy which lacks a size method. It does,
 * however, have an e lementAt (i) method that returns the element at index i in 0(1) time. If i is beyond the
 * bounds of the data structure, it returns -1. (For this reason, the data structure only supports positive integers.)
 * Given a Listy which contains sorted, positive integers, find the index at which an element x occurs. If x occurs
 * multiple times, you may return any index.
 */

#ifndef SERGIOTEST_10_4_SORTEDSEARCHNOSIZEMINE_H
#define SERGIOTEST_10_4_SORTEDSEARCHNOSIZEMINE_H

#include <vector>

namespace jr {
    struct Listy {
        std::vector<int> listy;
        int elementAt(int index) {
            if(index < 0 || index >= listy.size()) {
                return -1;
            }
            return listy.at(index);
        }
        Listy(std::vector<int> listy) : listy(listy) { }
    };

    int size(Listy listy) {
        if(listy.elementAt(0) == -1) {
            return 0;
        }
        int start = 0;
        int end = 1;
        while(listy.elementAt(end - 1) != -1) {
            start = end;
            end *= 2;
        }
        while(start < end) {
            int middle = (start + end) / 2;
            if(listy.elementAt(middle) == -1) {
                end = middle;
            } else {
                start = middle + 1;
            }
        }
        return end;
    }

    int indexOf(int element, Listy listy) {
        int start = 0;
        int end = size(listy);
        while(start < end) {
            int middle = (start + end) / 2;
            if(listy.elementAt(middle) < element) {
                start = middle + 1;
            } else if(listy.elementAt(middle) > element) {
                end = middle;
            } else {
                return middle;
            }
        }
        return -1;
    }
}


#endif //SERGIOTEST_10_4_SORTEDSEARCHNOSIZEMINE_H
