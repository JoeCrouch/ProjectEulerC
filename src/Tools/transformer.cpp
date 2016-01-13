
#include "transformer.h"
#include <stdio.h>

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
