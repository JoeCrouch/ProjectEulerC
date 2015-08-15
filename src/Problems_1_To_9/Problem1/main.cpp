//http://projecteuler.net/problem=1
#include <iostream>

#include "SumCalculator.h"

using namespace std;

int main()
{
    SumCalculator calculator = SumCalculator::instaceOf();
    cout<<"The sum of all the multiples of 3 or 5 below 1000 is:"<<endl;
    cout<<calculator.sumMulitplesOf(3,5,1000);
    return 0;
}
