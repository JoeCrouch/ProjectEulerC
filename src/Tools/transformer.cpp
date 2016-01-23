
#include "transformer.h"
#include <stdio.h>

using std::stoi;

vector<int> Transformer::asVector(int n) {
    vector<int> nAsVector;
    
    int individualDigit = n % 10;
    
    nAsVector.push_back(individualDigit);
    
    if (n != individualDigit) {
        int nWithoutLastDigit = (n - individualDigit) / 10;
        vector<int> nWithoutLastDigitAsVector = asVector(nWithoutLastDigit);
        
        nAsVector.insert(nAsVector.begin(), nWithoutLastDigitAsVector.begin(), nWithoutLastDigitAsVector.end());
    }
    
    return nAsVector;
}

vector<int> Transformer::asVector(string n) {
    vector<int> stringAsIntVector;
    
    for (string::iterator it = n.begin(); it != n.end(); ++it) {
        int digit = *it - '0';
        stringAsIntVector.push_back(digit);
    }
    
    return stringAsIntVector;
}
