
#ifndef ProjectEulerCXCode_calculator_h
#define ProjectEulerCXCode_calculator_h

#include <vector>
using std::vector;

class Calculator {

public:

    static int sumMulitplesOf(vector<int> factors, int upTo);
    static int sumFibonacciMultiplesOf(vector<int> factors, int upTo);
    static vector<int> sumOfVectors(vector<int> vector1, vector<int> vector2);
    static long sumNumbersFromTo(int from, int to);
    static long sumSquaresFromTo(int from, int to);
    static bool isPalindromic(int n);
    static int powerOf(int number, int power);
    static vector<int> powerOfAsVector(int number, int power);
    static int conc(int a, int b);
    static long lowestCommonDenominator(vector<int> numbers);

private :
    Calculator() {};
};

#endif
