
#ifndef ProjectEulerCXCode_calculator_h
#define ProjectEulerCXCode_calculator_h

#include <vector>
using std::vector;

class Calculator {

public:

    static int sumMulitplesOf(vector<int> factors, int upTo);
    static int sumFibonacciMultiplesOf(vector<int> factors, int upTo);
    static long sumProperDivisors(long n);
    static long sum(vector<long> numbers);
    static vector<int> sumOfVectors(vector<int> vector1, vector<int> vector2);
    static long sumNumbersFromTo(int from, int to);
    static long sumSquaresFromTo(int from, int to);
    static bool isPalindromic(int n);
    static int powerOf(int number, int power);
    static vector<int> powerOfAsVector(int number, int power);
    static long conc(long a, long b);
    static long conc(long a, long b, long c);
    static long lowestCommonDenominator(vector<int> numbers);
    static int maxTotalForTrianglePath(vector<vector<int>> triangle);
    static long factorial(long number);
    static vector<int> factorialAsVector(int number);

private :
    Calculator() {};
};

#endif
