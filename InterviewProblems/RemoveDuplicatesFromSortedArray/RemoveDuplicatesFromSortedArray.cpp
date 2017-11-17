#include <vector>

/**
 * Original problem statement: https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array
 *
 * Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.
 * Note that even though we want you to return the new length, make sure to change the original array as well in place
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * Example:
 *      Given input array A = [1,1,2],
 *      Your function should return length = 2, and A is now [1,2].
 * @param sortedNumbers sorted array of numbers with duplicates
 * @return length of the array without duplicates, but original array should also be modified
 */
int removeDuplicates(std::vector<int>& sortedNumbers) {
    int count = 0;
    for(int i = 0; i < sortedNumbers.size(); i++) {
        if(i < sortedNumbers.size()-1 && sortedNumbers.at(i) == sortedNumbers.at(i+1)) {
            continue;
        }
        sortedNumbers.at(count) = sortedNumbers.at(i);
        count++;
    }
    sortedNumbers.erase(sortedNumbers.begin()+count, sortedNumbers.end());
    return sortedNumbers.size(); //or count
}