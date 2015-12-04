//http://projecteuler.net/problem=9

#include "problem9.h"
#include <iostream>

using std::cout;
using std::endl;

const Problem9 Problem9::INSTANCE = Problem9();

void Problem9::run() const {
    //TODO: need for e, f and g?
    int d = 0, e = 0, f = 0, g = 0;

    for (int a = 100; a < 500; a++)
    {
        for (int b = 100; b < 500; b++)
        {
            for (int c = 100; c < 800; c++)
            {
                if (a * a + b * b == c * c) {
                    if (a + b + c == 1000) {
                        d = a * b * c;
                        e = a;
                        f = b;
                        g = c;
                        break;
                    }
                }
            }
            if (d != 0) {
                break;
            }
        }
        if (d != 0) {
            break;
        }
    }
    
    cout << "The Pythagorean triplet that sums to 1000 is:" << endl;
    cout << e << "^2 + " << f << "^2 = " << g << "^2" << endl;
    cout << e << "+" << f << "+" << g << "=" << e + f + g <<endl;
    cout << "The product of these is:" << endl;
    cout << d << endl << endl;
}
