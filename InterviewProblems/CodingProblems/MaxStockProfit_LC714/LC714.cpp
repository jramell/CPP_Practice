//Check LC714.h for my own notes of what I learned solving this problem
#include "LC714.h"

using std::max;

int maxT(int a, int b, int c) {
    int tempMax = max(a,b);
    return max(tempMax, c);
}

//Define matrix where [i][j] contains best thing I can do considering 0..i as buying points and 0..j as selling points.
//That way, [i][j] is the best between:
//
//1. Selling at j what you bought at i + your profit before buying at i. The expression for this is:
//          prices[j](how much you sell) - prices[i] - fee + prices[i-1][i-1]
//2. What you could do not considering i as a buying point. The expression for this is:
//          prices[i-1][j]
//3. What you could do by selling before considering selling in j. The expression for this is:
//          prices[i][j-1]
//
//After that, realize you only need previous row to calculate the current one, and store only those instead of
//the whole matrix. Time complexity: O(n^2). Space complexity: O(n).
int jr::LC714::maxProfitQuadraticTime(std::vector<int>& prices, int fee) {
    //vector<vector<int>> sellMatrix(prices.size(), vector<int>(prices.size(), 0));
    std::vector<int> currentRow(prices.size(), 0);

    for (int col = 1; col < prices.size(); col++) {
        int ifSold = prices.at(col) - prices.at(0) - fee;
        currentRow.at(col) = max(ifSold, currentRow.at(col-1));
    }

    for (int row = 1; row < prices.size(); row++) {
        for (int col = row; col < prices.size(); col++) {
            std::vector<int> previousRow = currentRow;
            int profitIfBoughtAtRowAndSoldAtCol = prices.at(col) - prices.at(row) - fee + previousRow.at(row-1);
            currentRow.at(col) = maxT(profitIfBoughtAtRowAndSoldAtCol, previousRow.at(col), currentRow.at(col-1));
        }
    }
    return currentRow.at(prices.size()-1);
}

/**
 * At every step, you have only two choices: buying or selling stock. Define vector buy, where buy[i] is the maximum
 * profit up to day i by considering buying up to that day. Define vector sell, where sell[i] is the maximum profit
 * up to day i by considering selling up to that day. This is akin to defining a matrix with only buy and sell as rows.
 *
 * This way, when buying we have two choices: not buying or selling what we currently have and buying again. So,
 *          buy[i] = max(buy[i-1], sell[i-1] - profit - fee
 * When selling we also have two choices: not selling or buying the stock we're going to sell and selling it. We add
 *          buy[i-1] because we already considered buying stock in previous iterations over that array. So,
 *          sell[i] = max(sell[i-1], buy[i-1] + profit
 *
 * The implementation uses i+1 instead of i to avoid out_of_range problems.
 * Time complexity: O(n). Space complexity: O(n).
 */
int jr::LC714::maxProfitLinearTimeAndSpace(std::vector<int>& prices, int fee) {
        std::vector<int> buy(prices.size()+1, -prices.at(0));
        std::vector<int> sell(prices.size()+1, 0);
        for (int i = 0; i < prices.size(); i++) {
            buy.at(i+1) = max(buy.at(i), sell.at(i) - prices.at(i));
            sell.at(i+1) = max(sell.at(i), buy.at(i) + prices.at(i) - fee);
        }
        return sell.at(prices.size());
}

/**
 * Using the same logic as the solution with linear time and space, realize you only need the previous buy
 * and sell values to calculate the current ones, so store only those.
 * Time complexity: O(n). Space complexity: O(1).
 */
int jr::LC714::maxProfitLinearTimeConstSpace(std::vector<int>& prices, int fee) {
    int previousSell = 0;
    int previousBuy = -prices.at(0);
    int currentBuy = 0;
    for (int i = 0; i < prices.size(); i++) {
        currentBuy = max(previousBuy, previousSell - prices.at(i));
        previousSell = max(previousSell, previousBuy + prices.at(i) - fee);
        previousBuy = currentBuy;
    }
    return previousSell;
}