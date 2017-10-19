//
// Created by Sergio on 10/19/2017.
//

#include "SumOfSubarrays.h"

//Question and solution described in: https://web.stanford.edu/class/cs9/lectures/04/Subarray%20Sums.pdf
//Note to self: I did get to the most optimal solution the first time I saw the problem, but it took me around 50min. Too long!
long jr::sumOfContiguousSubarrays(std::vector<int> numbers) {
    int sumOfContiguousSubarrays = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sumOfContiguousSubarrays += (i*(numbers.size() - i) + (numbers.size()-i)) * numbers.at(i);
    }
    return sumOfContiguousSubarrays;
}