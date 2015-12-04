//http://projecteuler.net/problem=7

#include "problem7.h"
#include <iostream>

using std::cout;
using std::endl;

int isPrimeProblem7(int n);

const Problem7 Problem7::INSTANCE = Problem7();

void Problem7::run() const {
    int i=1,m=2,k=0;
    while(i<=10001)
    {
        if (isPrimeProblem7(m) == 1) {
            k = m;
            i = i + 1;
        }
        m++;
    }
    cout << "The 10,001st prime number is:" << endl;
    cout << k << endl << endl;
}

//TODO: extract
//TODO: not returning boolean??
int isPrimeProblem7(int n) {
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
        for (int i=7; i * i <= n; i++) {
            if(n%i==0) {
                return 0;
            }
        }
        return 1;
    }
}
