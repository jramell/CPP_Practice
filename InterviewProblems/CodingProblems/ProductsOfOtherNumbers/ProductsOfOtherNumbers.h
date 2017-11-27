#ifndef SERGIOTEST_PRODUCTSOFOTHERNUMBERS_H
#define SERGIOTEST_PRODUCTSOFOTHERNUMBERS_H

/**
 * Solves problem whose original statement is at: https://www.interviewcake.com/question/cpp/product-of-other-numbers
 *
 * You have a vector of integers, and for each index you want to find the product of every integer except the integer at that index.
    Write a function getProductsOfAllIntsExceptAtIndex() that takes a vector of integers and returns a vector of the products.

    For example, given:

      [1, 7, 3, 4]

    your function would return:

      [84, 12, 28, 21]

    by calculating:

      [7 * 3 * 4,  1 * 3 * 4,  1 * 7 * 4,  1 * 7 * 3]

    Do not use division in your solution.
 */
#include <vector>

namespace jr {
    //Solves aforementioned problem with O(n^2) Time Complexity. Space Complexity: O(n) for answer, O(1) extra space.
    std::vector<int> getProductsOfAllExceptAtIndexQuadratic(std::vector<int> numbers);

    //Time complexity: O(n). Space complexity: O(n) for answer, O(n) extra space.
    std::vector<int> getProductsOfAllExceptAtIndexBothLinear(std::vector<int> numbers);

    //Time complexity: O(n). Space complexity: O(n) for answer, O(1) extra space.
    std::vector<int> getProductsOfAllExceptAtIndexOptimal(std::vector<int> numbers);
}

#endif //SERGIOTEST_PRODUCTSOFOTHERNUMBERS_H
