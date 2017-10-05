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
        void printMatrix();
        bool operator== (const Matrix<T>&);

        template <typename S>
        friend bool operator== (const Matrix<S>&, const Matrix<S>&);
    };
    template <typename S>
    bool operator== (const Matrix<S>&, const Matrix<S>&);
}

#include "Matrix.cpp"

#endif //SERGIOTEST_MATRIX_H
