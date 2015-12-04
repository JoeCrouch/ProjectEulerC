
#ifndef ProjectEulerCXCode_sumCalculator_h
#define ProjectEulerCXCode_sumCalculator_h

class SumCalculator {
    static SumCalculator calculator;
    
public:
    static SumCalculator& instaceOf() {
        static SumCalculator instance;
        return instance;
    };
    
    int sumMulitplesOf(int x, int y, int upTo);
    
private :
    SumCalculator() {};
};

#endif
