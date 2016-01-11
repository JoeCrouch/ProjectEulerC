
#ifndef ProjectEulerCXCode_sumCalculator_h
#define ProjectEulerCXCode_sumCalculator_h

#include <vector>
using std::vector;

class SumCalculator {
    static SumCalculator calculator;
    
public:
    static SumCalculator& instace() {
        static SumCalculator instance;
        return instance;
    };

    int sumMulitplesOf(vector<int> factors, int upTo);
    int sumFibonacciMultiplesOf(vector<int> factors, int upTo);
    
    private :
    SumCalculator() {};
};

#endif