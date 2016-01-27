//http://projecteuler.net/problem=18

#include "problem18.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::max;

int maxTotalForTrianglePath(vector<vector<int>> triangle);

const Problem18 Problem18::INSTANCE = Problem18();

vector<vector<int>> triangle = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20, 4, 82, 47, 65},
    {19, 1, 23, 75, 3, 34},
    {88, 2, 77, 73, 7, 63, 67},
    {99, 65, 4, 28, 6, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    {04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23},
};

void Problem18::run() const {
    int maxTotal = maxTotalForTrianglePath(triangle);
    
    cout << "Path With Greatest Sum From Top To Bottom Is: " << maxTotal << endl << endl;
}


int maxTotalForTrianglePath(vector<vector<int>> triangle) {
    if (triangle.size() == 2) {
        int topPosition = triangle[0][0];
        int bottomPosition1 = triangle[1][0];
        int bottomPosition2 = triangle[1][1];
        return topPosition + max(bottomPosition1, bottomPosition2);
    } else {
        vector<vector<int>> smallerTriangle = triangle;
        
        vector<int> bottomRow = smallerTriangle[smallerTriangle.size() - 1];
        smallerTriangle.pop_back();
        
        vector<int> secondFromBottomRow = smallerTriangle[smallerTriangle.size() - 1];
        
        for (int i = 0; i < secondFromBottomRow.size(); ++i) {
            smallerTriangle[smallerTriangle.size() - 1][i] = secondFromBottomRow[i] + max(bottomRow[i], bottomRow[i + 1]);
        }
        
        return maxTotalForTrianglePath(smallerTriangle);
    }
}




