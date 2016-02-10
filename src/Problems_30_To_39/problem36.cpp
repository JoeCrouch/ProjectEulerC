//http://projecteuler.net/problem=36

#include "problem36.h"
#include "calculator.h"
#include "transformer.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int palindromicNumberWithEvenNumberOfDigits(int n);
int palindromicNumberWithOddNumberOfDigits(int n);

const Problem36 Problem36::INSTANCE = Problem36();

void Problem36::run() const {
    int upperLimit = 1000000;
    int sum = 0;
    
    int i = 1;
    int palidromicNumber = palindromicNumberWithEvenNumberOfDigits(i);
    while (palidromicNumber < upperLimit) {
        if (Calculator::isPalindromic(Transformer::inBinary(palidromicNumber))) {
            sum += palidromicNumber;
        }
        i++;
        palidromicNumber = palindromicNumberWithEvenNumberOfDigits(i);
    }
    
    i = 1;
    palidromicNumber = palindromicNumberWithOddNumberOfDigits(i);
    while (palidromicNumber < upperLimit) {
        if (Calculator::isPalindromic(Transformer::inBinary(palidromicNumber))) {
            sum += palidromicNumber;
        }
        i++;
        palidromicNumber = palindromicNumberWithOddNumberOfDigits(i);
    }
    
    cout << "Sum of Numbers that are palindromic in base 10 and base 2 less than 1000000 is: " << sum << endl << endl;
}

int palindromicNumberWithEvenNumberOfDigits(int n) {
    int palindromicNumber = n;
    
    while (n > 0) {
        palindromicNumber =  (palindromicNumber * 10) + (n % 10);
        n /= 10;
    }
    
    return palindromicNumber;
}

int palindromicNumberWithOddNumberOfDigits(int n) {
    int palindromicNumber = n;
    n /= 10;
    
    while (n > 0) {
        palindromicNumber =  (palindromicNumber * 10) + (n % 10);
        n /= 10;
    }
    
    return palindromicNumber;
}



