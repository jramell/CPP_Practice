#include "gtest/gtest.h"
#include "../../../InterviewProblems/MinesweeperBoard/MinesweeperBoard.h"

using minesweeper::Matrix;

TEST(Test_MinesweeperMatrix, UninitializedRowsNoThrow) {
    Matrix<int> testMatrix;
    ASSERT_NO_THROW(testMatrix.rows());
}

TEST(Test_MinesweeperMatrix, UninitializedRowsCorrectAnswer) {
    Matrix<int> testMatrix;
    EXPECT_EQ(0, testMatrix.rows());
}

TEST(Test_MinesweeperMatrix, UninitializedColsNoThrow) {
    Matrix<int> testMatrix;
    ASSERT_NO_THROW(testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, UninitializedColsCorrectAnswer) {
    Matrix<int> testMatrix;
    EXPECT_EQ(0, testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, ResizeTo0_Rows) {
    Matrix<int> testMatrix;
    testMatrix.resize(0, 0);
    EXPECT_EQ(0, testMatrix.rows());
}

TEST(Test_MinesweeperMatrix, ResizeTo0_Cols) {
    Matrix<int> testMatrix;
    testMatrix.resize(0, 0);
    EXPECT_EQ(0, testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, Resize0RowsAnd1Cols) {
    Matrix<int> testMatrix;
    testMatrix.resize(0, 1);
    EXPECT_EQ(0, testMatrix.rows());
    EXPECT_EQ(0, testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, Resize1RowsAnd0Cols) {
    Matrix<int> testMatrix;
    testMatrix.resize(1, 0);
    EXPECT_EQ(1, testMatrix.rows());
    EXPECT_EQ(0, testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, ResizeToSquare) {
    Matrix<int> testMatrix;
    testMatrix.resize(10, 10);
    EXPECT_EQ(10, testMatrix.rows());
    EXPECT_EQ(10, testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, DoubleResize) {
    Matrix<int> testMatrix;
    testMatrix.resize(10, 10);
    testMatrix.resize(0, 0);
    EXPECT_EQ(0, testMatrix.rows());
    EXPECT_EQ(0, testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, ResizeRowsHigherThanCols) {
    Matrix<int> testMatrix;
    testMatrix.resize(15, 10);
    EXPECT_EQ(15, testMatrix.rows());
    EXPECT_EQ(10, testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, ResizeRowsLessThanCols) {
    Matrix<int> testMatrix;
    testMatrix.resize(10, 20);
    EXPECT_EQ(10, testMatrix.rows());
    EXPECT_EQ(20, testMatrix.cols());
}

TEST(Test_MinesweeperMatrix, AtThrowsWhenEmpty) {
    Matrix<int> testMatrix;
    ASSERT_THROW(testMatrix.at(0, 0), std::out_of_range);
}

TEST(Test_MinesweeperMatrix, AtThrowsInInvalidPositivePos) {
    Matrix<int> testMatrix;
    testMatrix.resize(10, 10);
    ASSERT_THROW(testMatrix.at(11, 1), std::out_of_range);
}

TEST(Test_MinesweeperMatrix, AtThrowsInInvalidNegativePos) {
    Matrix<int> testMatrix;
    testMatrix.resize(10, 10);
    ASSERT_THROW(testMatrix.at(-5, 1), std::out_of_range);
}

TEST(Test_MinesweeperMatrix, AtUpdatesValidPos) {
    Matrix<int> testMatrix;
    testMatrix.resize(10, 10);
    testMatrix.at(1,1) = 55;
    EXPECT_EQ(55, testMatrix.at(1,1));
}