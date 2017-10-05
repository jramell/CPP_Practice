#include <random>
#include "MinesweeperBoard.h"

using minesweeper::Matrix;

//Note: stay in bounds using int i = max(0, value-1); i <= min(size()-1, value+1)

template<typename T>
void minesweeper::fillMatrixWith(Matrix<T>& matrix, T value) {
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j < matrix.cols(); j++) {
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
/*    if (!isValidRow(row, minesweeperBoard)) {
        return;
    }
    if (!isValidColumn(col, minesweeperBoard)) {
        return;
    }*/
    if (minesweeperBoard.at(row, col) != 9) {
        minesweeperBoard.at(row, col)++;
    }
}

void minesweeper::insertMinesInBoard(Matrix<int>& minesweeperBoard, int amountOfMines) {
    int minesLeft = amountOfMines;
    for (int i = 0; i < minesweeperBoard.rows() && minesLeft > 0; i++) {
        for (int j = 0; j < minesweeperBoard.cols() && minesLeft > 0; j++) {
            minesweeperBoard.at(i, j) = 9;
            for (int row = std::max(0, i - 1); row <= std::min(minesweeperBoard.rows(), i + 1); row++) {
                for (int col = std::max(0, j - 1); col <= std::min(minesweeperBoard.cols(), j + 1); col++) {
                    if (minesweeperBoard.at(row, col) != 9) {
                        minesweeperBoard.at(row, col)++;
                    }
                }
            }
            minesLeft--;
        }
    }
}

void minesweeper::insertRandomMinesInBoard(Matrix<int>& minesweeperBoard, int amountOfMines) {
    int minesLeft = amountOfMines;
    std::uniform_int_distribution<int> uniformRowDistribution(0, minesweeperBoard.rows()-1);
    std::uniform_int_distribution<int> uniformColDistribution(0, minesweeperBoard.cols()-1);
    std::mt19937 numberGenerator;
    while (minesLeft > 0) {
        int randomRow = uniformRowDistribution(numberGenerator);
        int randomCol = uniformColDistribution(numberGenerator);
        while (minesweeperBoard.at(randomRow, randomCol) == 9) {
            randomRow = uniformRowDistribution(numberGenerator);
            randomCol = uniformColDistribution(numberGenerator);
        }
        minesweeperBoard.at(randomRow, randomCol) = 9;
        for (int row = std::max(0, randomRow - 1); row <= std::min(minesweeperBoard.rows()-1, randomRow + 1); row++) {
            for (int col = std::max(0, randomCol - 1); col <= std::min(minesweeperBoard.cols()-1, randomCol + 1); col++) {
                if (minesweeperBoard.at(row, col) != 9) {
                    minesweeperBoard.at(row, col)++;
                }
            }
        }
        minesLeft--;
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
}

Matrix<int> minesweeper::randomMinesweeperBoard(int amountOfMines, int boardHeight, int boardWidth) {
    Matrix<int> minesweeperBoard;
    minesweeperBoard.resize(boardHeight, boardWidth);
    if (boardHeight == 0 || boardWidth == 0) {
        return minesweeperBoard;
    }
    fillMatrixWith(minesweeperBoard, 0);
    insertRandomMinesInBoard(minesweeperBoard, amountOfMines);
    return minesweeperBoard;
}

