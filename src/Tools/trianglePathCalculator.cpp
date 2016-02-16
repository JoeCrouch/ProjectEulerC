
#include "trianglePathCalculator.h"
#include <algorithm>

using std::max;

void verifyIsTriangle(vector<vector<int>> triangle);
int maxTotalForVerifiedTrianglePath(vector<vector<int>> triangle);


int TrianglePathCalculator::maxTotalForTrianglePath(vector<vector<int>> triangle) {
    verifyIsTriangle(triangle);
    return maxTotalForVerifiedTrianglePath(triangle);
}

void verifyIsTriangle(vector<vector<int>> triangle) {
    for (unsigned int i = 0; i < triangle.size(); ++i) {
        if (triangle[i].size() != i + 1) {
            throw std::runtime_error("vector must be triangle shape");
        }
    }
}

int maxTotalForVerifiedTrianglePath(vector<vector<int>> triangle) {
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
        
        for (unsigned int i = 0; i < secondFromBottomRow.size(); ++i) {
            smallerTriangle[smallerTriangle.size() - 1][i] = secondFromBottomRow[i] + max(bottomRow[i], bottomRow[i + 1]);
        }
        
        return maxTotalForVerifiedTrianglePath(smallerTriangle);
    }
}
