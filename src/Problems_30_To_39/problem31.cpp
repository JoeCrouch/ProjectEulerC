//http://projecteuler.net/problem=31

#include "problem31.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int numberOfWaysToProduceNumberFrom(int number, vector<int> options);

const Problem31 Problem31::INSTANCE = Problem31();

void Problem31::run() const {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    
    cout << "Number of ways to make £2 out of standard coins is: " << numberOfWaysToProduceNumberFrom(200, coins) << endl << endl;
}

int numberOfWaysToProduceNumberFrom(int number, vector<int> options) {
    if (options.size() == 0) {
        return 0;
    }
    
    int lastOption = options.back();
    options.pop_back();
    int dividesWithoutReachingNumber = number / lastOption;
    
    int count = 0;
    if (number % lastOption == 0) {
        count ++;
        dividesWithoutReachingNumber --;
    }
    
    for (int i = dividesWithoutReachingNumber; i >=0; --i) {
        count += numberOfWaysToProduceNumberFrom(number - i * lastOption, options);
    }
    
    
    return count;
}

