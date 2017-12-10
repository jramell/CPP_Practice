#ifndef SERGIOTEST_10_3_SEARCHINROTATEDARRAY_H
#define SERGIOTEST_10_3_SEARCHINROTATEDARRAY_H

#include <vector>

namespace jr {
    /**
     * Solves Cracking The Code Interview exercise 10.3. Search In Rotated Array. Statement:
     * Given a sorted array of n integers that has been rotated an unknown number of times, write code to find
     * an element in the array. You may assume that the array was originally sorted in increasing order.
        EXAMPLE
        Input: find 5 in {15, 16, 19, 20, 25, 1, 3,4,5,7,10, 14}
        Output: 8 (the index of 5 in the array)
     */
    //Time complexity = O(log n) without duplicates, O(n) with duplicates.
    //Space complexity = O(1)
    int searchInRotatedArray(int element, const std::vector<int>& array) {
        int start = 0;
        int end = array.size();
        while(start < end) {
            int middle = (start + end) / 2;
            if(array.at(middle) == element) {
                return middle;
            }
            if(array.at(start) < array.at(middle)) { //left side sorted
                //if should go left and
                //is in left’s range. We can only ask it this way because we
                //know left side is sorted
                if(array.at(middle) > element && array.at(start) <= element) {
                    end = middle; //go left
                } else {
                    start = middle+1; //go right
                }
            } else if(array.at(end-1) > array.at(middle)) { //right side sorted
                //if should go right and
                //is in right’s range. We can only ask it this way because know
                //right side is sorted.
                if(array.at(middle) < element && array.at(end-1) >= element) {
                    start = middle+1; //go right
                } else {
                    end = middle; //go left
                }
            } else if(array.at(start) == array.at(middle)) {
                start++;
            }
            if(array.at(middle) == array.at(end-1)) {
                end--;
            }
        }
        return -1;
    }
}
#endif //SERGIOTEST_10_3_SEARCHINROTATEDARRAY_H
