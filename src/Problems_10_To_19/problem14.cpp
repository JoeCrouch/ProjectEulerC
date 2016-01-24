//http://projecteuler.net/problem=14

#include "problem14.h"
#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::max;
using std::map;

long collatzFunction(long n);

const Problem14 Problem14::INSTANCE = Problem14();

void Problem14::run() const {
    map<int, int> cache;
    int start = 999999;
    int numberWithMaxChain = start;
    int maxChainLength = 1;
    
    for (int i = start; 2 * i > start; --i) {
        int chainLength = 1;
        long number = i;
        
        while (number != 1) {
            if (number > i && number < start) {
                chainLength += cache[(int) number];
                break;
            } else if (2 * number > i && 2 * number < start) {
                chainLength += (cache[(int) (2 * number)] - 1);
                break;
            }
            number = collatzFunction(number);
            chainLength++;
        }
        
        cache[i] = chainLength;
        
        if (chainLength > maxChainLength) {
            maxChainLength = chainLength;
            numberWithMaxChain = i;
        }
    }
    
    cout << "Number Below 1 Mill With Longest Collatz Chain is: " << numberWithMaxChain << endl << endl;
}

long collatzFunction(long n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}


