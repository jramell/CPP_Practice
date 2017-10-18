#include "RecursiveMultiply.h"
#include <algorithm>
long jr::recursiveMultiply(int number1, int number2) {
        int minimum = std::min(number1, number2);
        int maximum = std::max(number1, number2);
        if (minimum == 0) {
            return 0;
        }
        if(minimum == 1) {
            return maximum;
        }
        if (minimum % 2 == 0) {
            return recursiveMultiply(maximum, minimum>>1) << 1;
        }
        return (recursiveMultiply(maximum, minimum>>1) << 1) + maximum; //was recursiveMultiply(maximum, minimum-1) + maximum before
                                                                        //reading CTCI solution
}