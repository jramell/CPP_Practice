//
// Created by Sergio on 10/4/2017.
//

#ifndef SERGIOTEST_MATRIX_H
#define SERGIOTEST_MATRIX_H

#include <vector>

namespace minesweeper {

    template<typename T>
    class Matrix {
        std::vector<std::vector<T>> matrix;
    public:
        void resize(int rows, int cols);
        T& at(int row, int col);
        int rows();
        int rows() const;
        int cols();
        int cols() const;
    };

}
#include "Matrix.cpp"

#endif //SERGIOTEST_MATRIX_H
