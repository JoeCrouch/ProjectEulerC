//Create a Camera class
#ifndef _Camera_H
#define _Camera_H



class SumCalculator {
    static SumCalculator calculator;

public:
    static SumCalculator& instaceOf() {
        static SumCalculator instance;
        return instance;
    };

    int sumMulitplesOf(int x, int y, int upTo) {
        int sum = 0;
        for(int i = 0; i < upTo; i++) {
                if(i%3==0){sum=sum+i;}
                else if (i%5==0) {sum=sum+i;}
        }
        return sum;
    };

private :
    SumCalculator() {};
};

#endif
