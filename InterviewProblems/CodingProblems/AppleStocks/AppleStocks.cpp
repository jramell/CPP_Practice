#include <climits>
#include <stdexcept>
#include "AppleStocks.h"

/**
 * Solves question with original statement at: https://www.interviewcake.com/question/cpp/stock-price
 *
 * Suppose we could access yesterday's stock prices as a vector, where:

    The indices are the time in minutes past trade opening time, which was 9:30am local time.
    The values are the price in dollars of Apple stock at that time.
    So if the stock cost $500 at 10:30am, stockPricesYesterday[60] = 500.

    Write an efficient function that takes stockPricesYesterday and returns the best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.

    For example:

      vector<int> stockPricesYesterday{10, 7, 5, 8, 11, 9};

    getMaxProfit(stockPricesYesterday);
    // returns 6 (buying for $5 and selling for $11)

    No "shorting"—you must buy before you sell. You may not buy and sell in the same time step (at least 1 minute must pass).
 */
int jr::maxStockProfit(std::vector<int> stockPricesYesterday) {
    if(stockPricesYesterday.size() < 2) {
        throw std::invalid_argument("There must be at least 2 stock prices to calculate a profit");
    }
    int maxProfit = INT_MIN;
    int minStockPrice = stockPricesYesterday.at(0);
    for(int i = 1; i < stockPricesYesterday.size(); i++) {
        int price = stockPricesYesterday.at(i);
        maxProfit = std::max(maxProfit, price - minStockPrice);
        minStockPrice = std::min(price, minStockPrice);
    }
    return maxProfit;
}