#ifndef SERGIOTEST_MINESWEEPERBOARD_H
#define SERGIOTEST_MINESWEEPERBOARD_H

#include "Matrix.h"

//Solves: https://techdevguide.withgoogle.com/paths/foundational/sequence-2/coding-question-minesweeper.
//Time it took on October 10th, 2017: 10min to understand problems because description wasn't very clear,
//                                  35min to code solution. 45min total. Need to get that down to 30min.
namespace minesweeper {

    template<typename T>
    void fillMatrixWith(Matrix<T>& matrix, T value);

    template<typename T>
    bool isValidRow(int row, const Matrix<T>& matrix);

    template<typename T>
    bool isValidColumn(int col, const Matrix<T>& matrix);

    void incrementBoardCell(Matrix<int>& minesweeperBoard, int row, int col);

    void insertMinesInBoard(Matrix<int>& minesweeperBoard, int amountOfMines);

    void insertRandomMinesInBoard(Matrix<int>& minesweeperBoard, int amountOfMines);

    Matrix<int> minesweeperBoard(int amountOfMines, int boardHeight, int boardWidth);

    Matrix<int> randomMinesweeperBoard(int amountOfMines, int boardHeight, int boardWidth);
}

#endif //SERGIOTEST_MINESWEEPERBOARD_H
