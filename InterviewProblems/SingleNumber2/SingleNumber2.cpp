#include "SingleNumber2.h"

/**
 * Problem description in ../SingleNumber2.h
 *
 * Counts the number of 1 bits at every position of every integer in numbers. Because all numbers are repeated
 * 3 times except one, this number will either be 3^m or 3^m+1, depending on whether the non-repeated number has a
 * 1 in that position or not. If it has a 1 there, set the 1 in our "uniqueNumber" answer. Essentially, we're deducing
 * what the unique number must be depending on the number of 1 bits in each position of every integer in the array.
 */
int jr::singleNumber(const std::vector<int>& numbers) {
    long numberOf1s = 0;
    int uniqueNumber = 0;
    for(int i = 0; i < 32; i++) {
        numberOf1s = 0;
        int shifted1 = 1 << i;
        for (int j = 0; j < numbers.size(); j++) {
            if((numbers.at(j) & shifted1) > 0) {
                numberOf1s++;
            }
        }
        //if there are 3^m+1 1s, the non-repeated number has a 1 bit in that position
        if ( (numberOf1s % 3) != 0 ) {
            uniqueNumber |= shifted1;
        }
    }
    return uniqueNumber;
}