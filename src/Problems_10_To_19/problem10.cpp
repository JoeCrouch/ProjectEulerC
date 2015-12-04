//http://projecteuler.net/problem=10

#include "problem10.h"
#include <iostream>

using std::cout;
using std::endl;

int isPrime10(long int n);

const Problem10 Problem10::INSTANCE = Problem10();

void Problem10::run() const {
    long int m = 2;
    __int64_t sum = 0;
    //TODO: could be a for loop?
    while (m < 2000000)
    {
        if (isPrime10(m) == 1) {
            sum += m;
        }
        m++;
    }
    
    cout << "The sum of all the primes below two million is:" << endl;
    cout << sum << endl << endl;
}

//TODO: extract
//TODO: not returning boolean??
int isPrime10(long int n) {
    if (n <= 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    } else if (n < 9) {
        return 1;
    } else if (n % 3 == 0) {
        return 0;
    } else if (n % 5 == 0) {
        return 0;
    } else {
        for (int i = 7; i * i <= n; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}
