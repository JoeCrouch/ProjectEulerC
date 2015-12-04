//http://projecteuler.net/problem=6

#include "problem6.h"
#include <iostream>

using std::cout;
using std::endl;

const Problem6 Problem6::INSTANCE = Problem6();

void Problem6::run() const {
    long int sum = 0, sum2 = 0;
    for(int i=1;i<=100;i++)
    {
        sum=sum+i*i;
        sum2=sum2+i;
    }
    cout<<"The sum of the squares of the first 100 natural numbers is:" << endl;
    cout << sum << endl << endl;
    
    cout<<"The square of the sum of the first 100 natural numbers is:" << endl;
    cout << sum2 * sum2 << endl << endl;
    
    long int k = (sum2 * sum2) - sum;
    cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is:" << endl;
    cout << k << endl << endl;
}
