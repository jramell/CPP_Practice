#include "../../Algorithms/GreatestCommonDivisor/GreatestCommonDivisor.h"
#include "gtest/gtest.h"

using jr::greatestCommonDivisor;

TEST(Test_GreatestCommonDivisor, Zeroes) {
    EXPECT_EQ(0, greatestCommonDivisor(0,0));
}

TEST(Test_GreatestCommonDivisor, Multiples3) {
    EXPECT_EQ(3, greatestCommonDivisor(3,33));
}

TEST(Test_GreatestCommonDivisor, Multiples5) {
    EXPECT_EQ(5, greatestCommonDivisor(150,5));
}

TEST(Test_GreatestCommonDivisor, Multiples7) {
    EXPECT_EQ(7, greatestCommonDivisor(84,7));
}

TEST(Test_GreatestCommonDivisor, Primes1) {
    EXPECT_EQ(1, greatestCommonDivisor(929,757));
}

TEST(Test_GreatestCommonDivisor, Primes2) {
    EXPECT_EQ(1, greatestCommonDivisor(3677,3539));
}

TEST(Test_GreatestCommonDivisor, Primes3) {
    EXPECT_EQ(1, greatestCommonDivisor(5323,6113));
}

TEST(Test_GreatestCommonDivisor, Primes4) {
    EXPECT_EQ(1, greatestCommonDivisor(11471,15331));
}

TEST(Test_GreatestCommonDivisor, Negative1) {
    EXPECT_EQ(10, greatestCommonDivisor(-20,-10));
}

TEST(Test_GreatestCommonDivisor, Negative2) {
    EXPECT_EQ(33, greatestCommonDivisor(-33,-99));
}

TEST(Test_GreatestCommonDivisor, Random1) {
    EXPECT_EQ(14, greatestCommonDivisor(84,70));
}

TEST(Test_GreatestCommonDivisor, Random2) {
    EXPECT_EQ(3, greatestCommonDivisor(235821,452901));
}

TEST(Test_GreatestCommonDivisor, Random3) {
    EXPECT_EQ(2, greatestCommonDivisor(50230,35672));
}

TEST(Test_GreatestCommonDivisor, Random4) {
    EXPECT_EQ(48242, greatestCommonDivisor(48242,96484));
}

TEST(Test_GreatestCommonDivisor, Big1) {
    EXPECT_EQ(5, greatestCommonDivisor(252058100,129501245));
}

TEST(Test_GreatestCommonDivisor, Big2) {
    EXPECT_EQ(2147483647, greatestCommonDivisor(-2147483647,2147483647));
}

