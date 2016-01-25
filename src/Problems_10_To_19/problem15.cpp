//http://projecteuler.net/problem=15

#include "problem15.h"
#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;

struct coordinate {
    int x, y;
    
    bool operator==(const coordinate &o) const {
        return x == o.x && y == o.y;
    }
    
    bool operator<(const coordinate &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
map<coordinate, long> cache;

long numberOfPaths(int width, int height);

const Problem15 Problem15::INSTANCE = Problem15();

void Problem15::run() const {
    int gridSize = 20;
    cout << "Number Of Paths In 20 X 20 Grid From Top Left To Bottom Right Is: " << numberOfPaths(gridSize, gridSize) << endl << endl;
    
}

long numberOfPaths(int width, int height) {
    coordinate coord = {width, height};
    
    if (cache.find(coord) != cache.end()) {
        return cache[coord];
    }
    
    long result = 0;
    if (width == 1 || height == 1) {
        result =  width + height;
    } else if (width == height) {
        result = 2 * numberOfPaths(width - 1, height);
    } else {
        result = numberOfPaths(width - 1, height) + numberOfPaths(width, height - 1);
    }
    
    cache[coord] = result;
    return result;
}



