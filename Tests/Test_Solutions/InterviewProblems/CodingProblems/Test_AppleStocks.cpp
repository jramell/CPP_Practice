#include "gtest/gtest.h"

#include "../../../../InterviewProblems/CodingProblems/AppleStocks/AppleStocks.h"

using jr::maxStockProfit;
using std::vector;

TEST(Test_AppleStocks, Example) {
    vector<int> stockPricesYesterday{10, 7, 5, 8, 11, 9};
    EXPECT_EQ(6, maxStockProfit(stockPricesYesterday));
}

TEST(Test_AppleStocks, NotEnoughPrices) {
    vector<int> stockPricesYesterday{10};
    EXPECT_THROW(maxStockProfit(stockPricesYesterday), std::invalid_argument);
}

TEST(Test_AppleStocks, NegativeProfit) {
    vector<int> stockPricesYesterday{10, 9, 8, 7, 6, 5};
    EXPECT_EQ(-1, maxStockProfit(stockPricesYesterday));
}

TEST(Test_AppleStocks, RandomTestcase1) {
    vector<int> stockPricesYesterday{9, 3, 5, 6, 99, 1};
    EXPECT_EQ(96, maxStockProfit(stockPricesYesterday));
}

TEST(Test_AppleStocks, RandomTestcase2) {
    vector<int> stockPricesYesterday{10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    EXPECT_EQ(10, maxStockProfit(stockPricesYesterday));
}

TEST(Test_AppleStocks, RandomTestcase3) {
    vector<int> stockPricesYesterday{293, 100, 101, 452, 943, 860, 1000};
    EXPECT_EQ(900, maxStockProfit(stockPricesYesterday));
}