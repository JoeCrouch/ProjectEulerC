
#include "numberCharacteristic.h"
#include "transformer.h"

int NumberCharacteristic::lengthOf(long number) {
    int length = 0;
    while (number != 0) {
        length++;
        number /= 10;
    }
    
    return length;
}

bool NumberCharacteristic::isPalindromic(int n) {
    vector<int> nAsVector = Transformer::asVector(n);
    
    return isPalindromic(nAsVector);
}

bool NumberCharacteristic::isPalindromic(vector<int> vector) {
    for (unsigned int i = 0; i < vector.size() / 2; ++i) {
        if (vector[i] != vector[vector.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool NumberCharacteristic::is1To9Pandigital(long number) {
    vector<int> asVector = Transformer::asVector(number);
    
    if (asVector.size() != 9) {
        return false;
    }
    
    for (int i = 1; i < 10; ++i) {
        if (find(asVector.begin(), asVector.end(), i) == asVector.end()) {
            return false;
        }
    }
    
    return true;
}
