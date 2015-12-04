
#include "sumCalculator.h"


int SumCalculator::sumMulitplesOf(int x, int y, int upTo) {
    int sum = 0;
    for (int i = 0; i < upTo; i++) {
        if (i % x == 0) {
            sum += i;
        }
        else if (i % y == 0) {
            sum = sum + i;
        }
    }
    return sum;
};