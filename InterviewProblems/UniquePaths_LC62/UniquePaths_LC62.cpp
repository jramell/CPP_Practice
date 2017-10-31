#include "UniquePaths_LC62.h"

/**
 * Solves Solves https://leetcode.com/problems/unique-paths
 * Sees possible paths as possible permutations of a string of length rows+cols-2
 * made by decissions (Down, Right, Right, Down, for example). There are (rows+cols-2)!
 * ways to rearrange it. However, there are (cols-1) Rights in the string, and (rows-1) Downs,
 * the rearranging of which would not make two different permutations. So, the answer is
 * (rows+cols-2)! / ( (rows-1)!(cols-1)! ). This algorithm calculates that.
 *
 * @return unique ways to get from top-left to bottom-right of a matrix with rows rows and cols columns
 */
int jr::uniquePaths(int rows, int cols) {
    rows--;
    cols--;
    unsigned long answer = 1;
    long minFactorial = 1;
    int maximum = (rows > cols)? rows : cols;
    for (long i = rows+cols; i > maximum; i--, minFactorial++) {
        answer *= i;
        answer /= minFactorial;
    }
    return answer;
}