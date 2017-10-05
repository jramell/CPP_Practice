#include "gtest/gtest.h"

#include "../../../InterviewProblems/MinesweeperBoard/MinesweeperBoard.h"

using minesweeper::Matrix;

TEST(Test_MinesweeperBoard, RandomBoardGeneration) {
    ASSERT_NO_THROW(minesweeper::Matrix<int> board = minesweeper::randomMinesweeperBoard(10, 10, 10));
}

TEST(Test_MinesweeperBoard, DefaultBoardGeneration) {
    minesweeper::Matrix<int> generated = minesweeper::minesweeperBoard(2, 10, 10);
    minesweeper::Matrix<int> setup;
    setup.resize(10, 10);
    setup.at(0, 0) = 9;
    setup.at(0, 1) = 9;
    setup.at(0, 2) = 1;
    setup.at(1, 0) = 2;
    setup.at(1, 1) = 2;
    setup.at(1, 2) = 1;
    EXPECT_EQ(setup, generated);
}