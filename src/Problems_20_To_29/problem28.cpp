//http://projecteuler.net/problem=28

#include "problem28.h"
#include <iostream>

using std::cout;
using std::endl;

long sumDiagnoalsOfSpiralGrid(int gridSize);

const Problem28 Problem28::INSTANCE = Problem28();

void Problem28::run() const {
    int gridSize = 1001;
    
    long sumOfDiagonals = sumDiagnoalsOfSpiralGrid(gridSize);
    
    cout << "The Sum Of The Diagonals In a 1001 x 1001 Spiral Grid Is: " << sumOfDiagonals << endl << endl;
}

long sumDiagnoalsOfSpiralGrid(int gridSize) {
    long sum = 1;
    int finalEntry = gridSize * gridSize;
    
    int number = 1;
    int difference = 2;
    while (number < finalEntry) {
        for (int i = 0; i < 4; ++i) {
            number += difference;
            sum += number;
        }
        difference += 2;
    }
    
    return sum;
}

