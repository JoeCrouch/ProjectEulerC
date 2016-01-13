//http://projecteuler.net/problem=4

#include "problem4.h"
#include "calculator.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

const Problem4 Problem4::INSTANCE = Problem4();

bool isPalindromic(int n);
bool isPalindromic(vector<int> n);
vector<int> asVector(int n);

void Problem4::run() const {
    int largestPalindromicProduct = 0, threeDigit1 = 0, threeDigit2 = 0;
    
    Calculator calculator = Calculator::instace();
    
    for (int i = 999; i >= 100; i--) {
        for(int j = i; j >= threeDigit2; j--) {
            int product = i * j;
            if (product > largestPalindromicProduct && calculator.isPalindromic(product)) {
                largestPalindromicProduct = product;
                threeDigit1 = i;
                threeDigit2 = j;
                break;
            }
        }
    }
    cout << "The largest palindrome made from the product of two 3-digit numbers is: " << endl;
    cout << "\n" << threeDigit1 << " * " << threeDigit2 << " = " << largestPalindromicProduct << endl << endl;
}

