//http://projecteuler.net/problem=67

#include "problem67.h"
#include "transformer.h"
#include "calculator.h"
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

vector<vector<int>> readTriangleFile();

const Problem67 Problem67::INSTANCE = Problem67();

void Problem67::run() const {

    vector<vector<int>> triangle = readTriangleFile();

    int maxTotal = Calculator::maxTotalForTrianglePath(triangle);
    cout << "Path With Greatest Sum From Top To Bottom Is: " << maxTotal << endl << endl;
}


vector<vector<int>> readTriangleFile() {

    vector<vector<int>> triangle;

    ifstream triangleFile;

    triangleFile.open("triangle.txt");

    if (!triangleFile.good()) {
        throw std::runtime_error("could not open triangle.txt");
    }

    string row;
    while (getline(triangleFile, row, '\n')) {
        triangle.push_back(Transformer::asVector(row, ' '));
    }

    triangleFile.close();

    return triangle;
}




