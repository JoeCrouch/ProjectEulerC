//http://projecteuler.net/problem=67

#include "problem67.h"
#include "transformer.h"
#include "trianglePathCalculator.h"
#include "fileReader.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::getline;

vector<vector<int>> readTriangle(ifstream &triangleFile);

const Problem67 Problem67::INSTANCE = Problem67();

void Problem67::run() const {

    vector<vector<int>> triangle = FileReader::readFile("triangle.txt", readTriangle);

    int maxTotal = TrianglePathCalculator::maxTotalForTrianglePath(triangle);
    cout << "Path With Greatest Sum From Top To Bottom Is: " << maxTotal << endl << endl;
}


vector<vector<int>> readTriangle(ifstream &triangleFile) {

    vector<vector<int>> triangle;

    string row;
    while (getline(triangleFile, row, '\n')) {
        triangle.push_back(Transformer::asVector(row, ' '));
    }

    return triangle;
}




