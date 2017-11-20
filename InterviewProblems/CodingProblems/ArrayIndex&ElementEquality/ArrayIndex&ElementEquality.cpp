#include <vector>

/**
 * Solves problem whose original statement is at: https://www.pramp.com/challenge/jKoA5GAVy9Sr9jGBjz04
 * Given a sorted array arr of distinct integers, write a function indexEqualsValueSearch that returns
 * the lowest index i for which arr[i] == i. Return -1 if there is no such index. Analyze the time and
 * space complexities of your solution and explain its correctness.
 *
 * Examples:
 *  input: arr = [-8,0,2,5]
    output: 2 # since arr[2] == 2

    input: arr = [-1,0,3,6]
    output: -1 # since no index in arr satisfies arr[i] == i.

 * Constraints:
    [time limit] 5000ms

    [input] array.integer arr

    1 ≤ arr.length ≤ 100
    [output] integer
 */
 //Time complexity: O(log n), Space complexity: O(1)
int indexEqualsValueSearch(const std::vector<int>& arr) {
    int start = 0;
    int end = arr.size();
    while(start < end) {
        int middleIndex = (start+end)/2;
        if(arr.at(middleIndex) == middleIndex) {
            //if the possibility for lower arr[i] = i elements exists, go left
            if(middleIndex > 0 && arr.at(middleIndex-1) == middleIndex-1) {
                end = middleIndex;
                continue;
            }
            return middleIndex;
        } else if(arr.at(middleIndex) < middleIndex) { //all left elements are also like that, so go right
            start = middleIndex+1;
        } else { //all right elements are higher than their index, so go left
            end = middleIndex;
        }
    }
    return -1;
}