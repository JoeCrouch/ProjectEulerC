
#ifndef ProjectEulerCXCode_calculator_h
#define ProjectEulerCXCode_calculator_h

#include <vector>
using std::vector;

class Calculator {
    static Calculator calculator;

public:
    static Calculator& instace() {
        static Calculator instance;
        return instance;
    };

    int sumMulitplesOf(vector<int> factors, int upTo);
    int sumFibonacciMultiplesOf(vector<int> factors, int upTo);
    long sumNumbersFromTo(int from, int to);
    long sumSquaresFromTo(int from, int to);
    bool isPalindromic(int n);
    bool isPrime(long n);
    int powerOf(int number, int power);
    vector<int> powerOfAsVector(int number, int power);
    vector<int> buildVectorOfPrimesBelow(int upperBound);
    int conc(int a, int b);
    long lowestCommonDenominator(vector<int> numbers);

    private :
    Calculator() {};
};

#endif
