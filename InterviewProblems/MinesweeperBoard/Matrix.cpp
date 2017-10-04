#include <stdexcept>

using minesweeper::Matrix;

template<typename T>
void Matrix<T>::resize(int rows, int cols) {
    matrix.resize(rows);
    for (std::vector<T>& row : matrix) {
        row.resize(cols);
    }
}

template<typename T>
int Matrix<T>::rows() const {
    return matrix.size();
}

template<typename T>
int Matrix<T>::rows() {
    return static_cast<const Matrix<T>&>(*this).rows(); //calls const version of rows to avoid code duplication
}

template<typename T>
int Matrix<T>::cols() {
    return static_cast<const Matrix<T>&>(*this).cols(); //calls const version of cols to avoid code duplication
}

template<typename T>
int Matrix<T>::cols() const {
    if (matrix.size() > 0) {
        return matrix.at(0).size();
    } else {
        return 0;
    }
}

template<typename T>
T& Matrix<T>::at(int row, int col) {
    if (row <= 0 || row > cols()) {
        throw std::out_of_range("No such row in matrix");
    } else if (col <= 0 || col > rows()) {
        throw std::out_of_range("No such column in matrix");
    }
    return matrix.at(row).at(col);
}
