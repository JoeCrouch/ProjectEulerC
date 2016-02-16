//http://projecteuler.net/problem=39

#include "problem39.h"
#include <iostream>

using std::cout;
using std::endl;

const Problem39 Problem39::INSTANCE = Problem39();

void Problem39::run() const {
    int upperLimit = 1000;
    int bestPerimeter = 0;
    int maxNumberOfSolutions = 0;
    
    // For proof of limits and solution see below.
    for (int perimeter = 2; perimeter <= upperLimit; perimeter += 2) {
        int numberOfSolutions = 0;
        
        for (int a = 1; a < perimeter / 3; ++a) {
            if ((perimeter * (perimeter - 2 * a)) % (2 * (perimeter - a)) == 0) {
                numberOfSolutions++;
            }
        }
        
        if (numberOfSolutions > maxNumberOfSolutions) {
            maxNumberOfSolutions = numberOfSolutions;
            bestPerimeter = perimeter;
        }
    }
    
    cout
    << "Perimeter of right angle triangle with max number of integer solutions is: " << bestPerimeter << endl << endl;
}

/* Let the sides of the triangle be a, b and c with c being the longest side.
 * 
 * -> a^2 + b^2 = c^2  - (1)
 *
 * from the question we have a + b + c = p, (2), where p is the perimeter
 *
 * without loss of generalisation lets say a <= b < c 
 * 
 * (2) -> a < p / 3
 *
 *
 *
 * (1, 2) -> a^2 + b^2 = (p - a - b)^2
 *
 * -> a^2 + b^2 = p^2 + 2ab - 2bp - 2ap + a^2 + b^2
 * -> 2b(p - a) = p(p - 2a)
 * -> b = p(p - 2a) / 2(p - a)
 *
 * as b is an integer -> p(p - 2a) % 2(p - a) = 0
 *
 *
 *
 * (2) -> (a + b + c)^2 = p^2
 *
 * -> a^2 + b^2 + c^2 + 2ab + 2ac + 2bc = p^2
 * (1) -> 2(c^2 + ab + ac + bc) = p^2
 * -> p^2 is even
 * -> p is even
 *
 */






