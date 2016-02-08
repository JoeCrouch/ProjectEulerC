
#include "fraction.h"
#include <stdexcept>

using std::invalid_argument;

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("denominator cannot be 0");
    } else if (numerator == 0) {
        numerator_ = 0;
        denominator_ = 1;
    } else {
        int sign = 1;
        if (numerator < 0) {
            sign *= -1;
            numerator *= -1;
        }
        if (denominator < 0) {
            sign *= -1;
            denominator *= -1;
        }
        
        long long tmp = gcd(numerator, denominator);
        numerator_ = numerator / tmp * sign;
        denominator_ = denominator / tmp;
    }
}

bool Fraction::operator ==(Fraction const& fract) {
    return numerator_ == fract.numerator_ && denominator_ == fract.denominator_;
}

int Fraction::getNumerator() {
    return numerator_;
}

int Fraction::getDenominator() {
    return denominator_;
}




