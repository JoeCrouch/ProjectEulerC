//http://projecteuler.net/problem=9

#include "problem9.h"
#include <iostream>

using std::cout;
using std::endl;

const Problem9 Problem9::INSTANCE = Problem9();

void Problem9::run() const {
    int a = 0, b = 0, c = 0;

    for (a = 354; a > 0; a--) {
        for (b = 500; b > 176; b--) {
            for (c = 500; c > 250; c--) {
                if (a + b + c < 1000) {
                    break;
                } else if (a + b + c == 1000 && a * a + b * b == c * c) {
                    goto exit;
                }
            }
        }
    }

    exit:
    cout << "The Pythagorean triplet that sums to 1000 is:" << endl;
    cout << a << "^2 + " << b << "^2 = " << c << "^2" << endl;
    cout << a << "+" << b << "+" << c << "=" << a + b + c <<endl;
    cout << "The product of these is:" << endl;
    cout << a * b * c << endl << endl;
}
