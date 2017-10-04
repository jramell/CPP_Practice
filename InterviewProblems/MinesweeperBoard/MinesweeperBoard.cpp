#include "MinesweeperBoard.h"

using minesweeper::Matrix;

/*
template <typename T>
void minesweeper::fillMatrixWith(Matrix<T> &matrix, T value) {
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j < matrix.rows(); j++) {
            matrix.at(i, j) = value;
        }
    }
}

template<typename T>
bool minesweeper::isValidRow(int row, const Matrix<T>& matrix) {
    return row >= 0 && row < matrix.rows();
}

template<typename T>
bool minesweeper::isValidColumn(int col, const Matrix<T>& matrix) {
    return col >= 0 && col < matrix.cols();
}

void minesweeper::incrementBoardCell(Matrix<int>& minesweeperBoard, int row, int col) {
    if (!isValidRow(row, minesweeperBoard)) {
        return;
    }
    if (!isValidColumn(col, minesweeperBoard)) {
        return;
    }
    if (minesweeperBoard.at(row, col) != 9) {
        minesweeperBoard.at(row, col)++;
    }
}

void minesweeper::insertMinesInBoard(Matrix<int> &minesweeperBoard, int amountOfMines) {
    int minesLeft = amountOfMines;
    for (int i = 0; i < minesweeperBoard.rows() && minesLeft > 0; i++) {
        for (int j = 0; j < minesweeperBoard.cols() && minesLeft > 0; j++) {
            minesweeperBoard.at(i, j) = 9;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    incrementBoardCell(minesweeperBoard, k, l);
                }
            }
            minesLeft--;
        }
    }
}

Matrix<int> minesweeper::minesweeperBoard(int amountOfMines, int boardHeight, int boardWidth) {
    Matrix<int> minesweeperBoard;
    minesweeperBoard.resize(boardHeight, boardWidth);
    if (boardHeight == 0 || boardWidth == 0) {
        return minesweeperBoard;
    }
    fillMatrixWith(minesweeperBoard, 0);
    insertMinesInBoard(minesweeperBoard, amountOfMines);
    return minesweeperBoard;
}*/
