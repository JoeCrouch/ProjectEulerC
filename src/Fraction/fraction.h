
#ifndef ProjectEulerC_fraction_h
#define ProjectEulerC_fraction_h

class Fraction {

public:
    Fraction(int numerator, int denominator);
    int getNumerator();
    int getDenominator();

    bool operator == (Fraction const& fract);

private:
    Fraction();
    int numerator_;
    int denominator_;
};

#endif
