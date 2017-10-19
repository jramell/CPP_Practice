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
        //was recursiveMultiply(maximum, minimum-1) + maximum before reading CTCI solution
        //changed because if it gets here, minimum is odd, oddNumber-1 == evenNumber, which means
        //in the next recursive call I'd get returned what gets returned for even numbers, which is
        //recursiveMultiply(maximum, minimum>>1) << 1. So I can just use that value directly and save
        //myself another call
        return (recursiveMultiply(maximum, minimum>>1) << 1) + maximum;
}