#include "gtest/gtest.h"

#include "../../../cracking_code_interview/8.5.RecursiveMultiply/RecursiveMultiply.h"

using std::string;

using jr::recursiveMultiply;

TEST(Test_RecursiveMultiply, BothZeros) {
    EXPECT_EQ(0, recursiveMultiply(0, 0));
}

TEST(Test_RecursiveMultiply, OneZero) {
    EXPECT_EQ(0, recursiveMultiply(50, 0));
}

TEST(Test_RecursiveMultiply, One) {
    EXPECT_EQ(93, recursiveMultiply(93, 1));
}

TEST(Test_RecursiveMultiply, SameNumber1) {
    EXPECT_EQ(100, recursiveMultiply(10, 10));
}

TEST(Test_RecursiveMultiply, SameNumber2) {
    EXPECT_EQ(169, recursiveMultiply(13, 13));
}

TEST(Test_RecursiveMultiply, BothEven1) {
    EXPECT_EQ(336, recursiveMultiply(28, 12));
}

TEST(Test_RecursiveMultiply, BothEven2) {
    EXPECT_EQ(168, recursiveMultiply(4, 42));
}

TEST(Test_RecursiveMultiply, OneOdd1) {
    EXPECT_EQ(126, recursiveMultiply(3, 42));
}

TEST(Test_RecursiveMultiply, OneOdd2) {
    EXPECT_EQ(462, recursiveMultiply(42, 11));
}

TEST(Test_RecursiveMultiply, BothOdd1) {
    EXPECT_EQ(451, recursiveMultiply(41, 11));
}

TEST(Test_RecursiveMultiply, BothOdd2) {
    EXPECT_EQ(1139, recursiveMultiply(67, 17));
}