#include <vector>

/**
 * Solves problem whose original statement is in: https://www.pramp.com/challenge/ml9AwEA42YHK735G3lq
 *
 * Given a 2D array (matrix) inputMatrix of integers, create a function spiralCopy that copies inputMatrix’s values
 * into a 1D array in a spiral order, clockwise. Your function then should return that array.
 * Analyze the time and space complexities of your solution.
 *
 * Example:
 *      input:  inputMatrix  = [ [1,    2,   3,  4,    5],
                                 [6,    7,   8,  9,   10],
                                 [11,  12,  13,  14,  15],
                                 [16,  17,  18,  19,  20] ]
        output: [1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12]
 */

//Time complexity: O(rows*cols), Space complexity: O(rows*cols) in spiralCopy, O(1) without including it.
std::vector<int> spiralCopy(const std::vector<std::vector<int>>& inputMatrix) {
    std::vector<int> spiralCopy;
    if(inputMatrix.empty()) {
        return spiralCopy;
    }
    int copiedTopRows = 0;
    int copiedRightColumns = 0;
    int width = inputMatrix.at(0).size();
    int height = inputMatrix.size();
    while (2*copiedTopRows < height && 2*copiedRightColumns < width) {
        //copying top row from left to right
        for (int i = copiedRightColumns; i < width-copiedRightColumns; i++) {
            spiralCopy.push_back(inputMatrix.at(copiedTopRows).at(i));
        }
        copiedTopRows++;
        if(copiedTopRows >= inputMatrix.size()) {
            break;
        }
        //copying right column from top to bottom
        for (int i = copiedTopRows; i < height-copiedRightColumns; i++) {
            spiralCopy.push_back(inputMatrix.at(i).at(width-1-copiedRightColumns));
        }
        copiedRightColumns++;
        if(copiedRightColumns >= width) {
            break;
        }
        //copying bottom row from right to left
        for(int i = width-1-copiedRightColumns; i >= copiedRightColumns-1; i--) {
            spiralCopy.push_back(inputMatrix.at(inputMatrix.size()-1-(copiedTopRows-1)).at(i));
        }

        //copying left column from bottom to top
        for(int i = height-1-copiedTopRows; i >= copiedTopRows; i--) {
            spiralCopy.push_back(inputMatrix.at(i).at(copiedRightColumns-1));
        }
    }
    return spiralCopy;
}

