#include "gtest/gtest.h"

#include "../../../../InterviewProblems/CodingProblems/ProductsOfOtherNumbers/ProductsOfOtherNumbers.h"

using jr::getProductsOfAllExceptAtIndexQuadratic;
using jr::getProductsOfAllExceptAtIndexBothLinear;
using jr::getProductsOfAllExceptAtIndexOptimal;

using std::vector;

vector<int> numbers;
vector<int> correctAnswer;

void setupExampleCase() {
    numbers = {1, 7, 3, 4};
    correctAnswer = {84, 12, 28, 21};
}

void setupZeroCase() {
    numbers = {0};
    correctAnswer = {0};
}

void setupRandomCase1() {
    numbers = {0, 1, 2};
    correctAnswer = {2, 0, 0};
}

void setupRandomCase2() {
    numbers = {8, 9, 10};
    correctAnswer = {90, 80, 72};
}

TEST(Test_ProductsOfOtherNumbers, ExampleQuadratic) {
    setupExampleCase();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexQuadratic(numbers));
}

TEST(Test_ProductsOfOtherNumbers, ZeroQuadratic) {
    setupZeroCase();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexQuadratic(numbers));
}

TEST(Test_ProductsOfOtherNumbers, Random1Quadratic) {
    setupRandomCase1();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexQuadratic(numbers));
}

TEST(Test_ProductsOfOtherNumbers, Random2Quadratic) {
    setupRandomCase2();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexQuadratic(numbers));
}

TEST(Test_ProductsOfOtherNumbers, ExampleLinear) {
    setupExampleCase();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexBothLinear(numbers));
}

TEST(Test_ProductsOfOtherNumbers, ZeroLinear) {
    setupZeroCase();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexBothLinear(numbers));
}

TEST(Test_ProductsOfOtherNumbers, Random1Linear) {
    setupRandomCase1();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexBothLinear(numbers));
}

TEST(Test_ProductsOfOtherNumbers, Random2Linear) {
    setupRandomCase2();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexBothLinear(numbers));
}

TEST(Test_ProductsOfOtherNumbers, ExampleOptimal) {
    setupExampleCase();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexOptimal(numbers));
}

TEST(Test_ProductsOfOtherNumbers, ZeroOptimal) {
    setupZeroCase();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexOptimal(numbers));
}

TEST(Test_ProductsOfOtherNumbers, Random1Optimal) {
    setupRandomCase1();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexOptimal(numbers));
}

TEST(Test_ProductsOfOtherNumbers, Random2Optimal) {
    setupRandomCase2();
    EXPECT_EQ(correctAnswer, getProductsOfAllExceptAtIndexOptimal(numbers));
}