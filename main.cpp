#include <iostream>
#include <random>
#include "InterviewProblems/MinesweeperBoard/Matrix.h"
#include "InterviewProblems/MinesweeperBoard/MinesweeperBoard.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <forward_list>
#include <unordered_set>
#include <bitset>

using std::forward_list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::unordered_set;

void runTests(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}

void printBinaryOfInt(int number) {
/*    for (int i = 31; i >= 0; i--) {
        if ( ((1 << i) & number) > 0) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << endl;*/
    cout << std::bitset<32>(number) << endl;
}
int main(int argc, char* argv[])
{
/*    cout << "START" << endl;
    minesweeper::Matrix<int> board = minesweeper::randomMinesweeperBoard(10, 10, 10);
    board.printMatrix();
    cout << "END" << endl;*/
    runTests(argc, argv);
}