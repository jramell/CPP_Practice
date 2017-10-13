#include <algorithm>
#include "GreatestCommonDivisor.h"

long jr::greatestCommonDivisor(long number1, long number2) { //Implements Euclid's algorithm
    long max = std::max(number1, number2);
    long min = std::min(number1, number2);
    while(min != 0) {
        long temp = min;
        min = max%min;
        max = temp;
    }
    return abs(max);
}