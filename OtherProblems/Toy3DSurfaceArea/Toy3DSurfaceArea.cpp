/**
 *  Solution to problem whose original statement is at: https://www.hackerrank.com/contests/w35/challenges/3d-surface-area
 *
 *  Madison, is a little girl who is fond of toys. Her friend Mason works in a toy manufacturing factory. Mason has a 2D board A
 *  of size H x W with H rows and W columns. The board is divided into cells of size 1x1 with each cell indicated by it's coordinate
 *  (i,j). The cell (i,j) has an integer A_ij written on it. To create the toy Mason stacks A_ij number of cubes of size 1x1x1 on
 *  the cell (i,j).
 *
 *  Given the description of the board showing the values of A_ij and that the price of the toy is equal to the 3d surface area
 *  find the price of the toy.
 *
 *  Example image: https://s3.amazonaws.com/hr-assets/0/1509009918-091bdd4cba-1502631298-5cd3275ce9-img2.png
 *
 *  Input Format
 *  The first line contains two space-separated integers H and W the height and the width of the board respectively.
 *  The next H lines contains W space separated integers. The jth integer in ith line denotes.
 *
 *  Constraints
 *  1 <= H, W <= 100
 *  1 <= A_ij <= 100
 *
 *  Output Format
 *  Print the required answer, i.e the price of the toy, in one line.
 *
 *  Sample Input 0:
 *          1 1
 *          1
 *  Sample Output 0:
 *          6
 *
 *  Explanation 0: https://s3.amazonaws.com/hr-assets/0/1505569910-2f8fc5da13-3d.png
 *                 The area of a 1x1x1 cube is 6.
 *
 *   Sample Input 1:
 *      3 3
 *      1 3 4
 *      2 2 3
 *      1 2 4
 *   Sample Output 1:
 *      60
 *
 *   Explanation 1: The sample input corresponds to the figure described in problem statement.
 */

#include <vector>
#include <iostream>

using namespace std;

/**
 * Auxiliary struct written for this solution
 */
struct CubeStack {
    int levels;
    int contributingArea;
    CubeStack(int levels, int initialArea) : levels(levels), contributingArea(initialArea) { }
    CubeStack() : levels(0), contributingArea(0) { }
};

/**
 * Solution with O(rows*cols) time complexity and O(rows*cols) space complexity. Space complexity can be improved,
 * as you only need adjacent rows to calculate current one. Currently testing a solution with O(cols) space complexity.
 */
int hackerRankMainQuadraticSpace() {
    int rows = 0;
    cin >> rows;
    int cols = 0;
    cin >> cols;
    vector<vector<CubeStack>> toy(rows, vector<CubeStack>(cols));
    //read all input
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int currentStackLevels = 0;
            cin >> currentStackLevels;
            //on stacking, bottom of top cube occludes and is occluded by top of bottom cube
            int stackingAreaLoss = 2*(currentStackLevels-1);
            int totalCubeArea = currentStackLevels*6;
            toy.at(i).at(j) = CubeStack(currentStackLevels, totalCubeArea - stackingAreaLoss);
        }
    }
    long toyArea = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            CubeStack& currentStack = toy.at(i).at(j);
            if(i-1 >= 0) {
                //minimum between current stack level and adjacent is how many faces current is getting occluded by adjacent
                currentStack.contributingArea -= min(currentStack.levels, toy.at(i-1).at(j).levels);
            }
            for(int k = max(0, j-1); k < min(cols,j+2); k++) {
                if(k == j) {
                    continue;
                }
                currentStack.contributingArea -= min(currentStack.levels, toy.at(i).at(k).levels);
            }
            if(i+1 < rows) {
                currentStack.contributingArea -= min(currentStack.levels, toy.at(i+1).at(j).levels);
            }
            toyArea += currentStack.contributingArea;
        }
    }
    cout << toyArea << endl;
    return 0;
}