#ifndef SERGIOTEST_SEARCH_H
#define SERGIOTEST_SEARCH_H

#include <vector>

class Search {
public:
    /**
     * @param data data to be searched for in the array
     * @param array array where binary search will occur. It assumes it's sorted.
     * @return -1 if data isn't in the array, its index within it if it is
     */
    template <typename T>
    static int BinarySearch(T target, std::vector<T> array) {
        int start = 0;
        int end = array.size();
        while(start < end) {
            int middle = (start+end)/2;
            if (target < array.at(middle)) {
                end = middle;
            } else if (target > array.at(middle)) {
                start = middle+1;
            } else {
                return middle;
            }
        }
        return start;
    }

};

#endif //SERGIOTEST_SEARCH_H
