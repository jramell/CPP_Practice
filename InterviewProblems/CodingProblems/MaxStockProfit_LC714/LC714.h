#ifndef SERGIOTEST_LC714_H
#define SERGIOTEST_LC714_H

#include <vector>

namespace jr {
/**
 * Solves: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
 */
    class LC714 {
        /**
         * My first solution. It uses DP to check all possible buying points and selling points,
         * and chooses the best decission at each step. Runs in O(n^2) and uses O(n) memory, where n
         * is the size of prices. The solution is akin to that of the Knapsack problem, and I learned from
         * it to implement the improved version.
         */
        int maxProfitQuadraticTime(std::vector<int>& prices, int fee);

        /**
         * The next solution I implemented. I needed some hints to actually think of it, but I learned
         * of a new way to think of DP thanks to it: instead of thinking about checking all the possibilities
         * only once, think of checking all your possible options at every step of the process, and choosing
         * the best. This is the same as checking all possibilities for problems like Knapsack, but can mean
         * a drastic difference in problems such a this one. Runs in O(n) and uses O(n) memory.
         */
        int maxProfitLinearTimeAndSpace(std::vector<int>& prices, int fee);

        /**
         *
         */
        int maxProfitLinearTimeConstSpace(std::vector<int>& prices, int fee);
    };
}
#endif //SERGIOTEST_LC714_H
