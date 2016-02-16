
#ifndef ProjectEulerCXCode_numberCharacteristic_h
#define ProjectEulerCXCode_numberCharacteristic_h

#include <vector>

using std::vector;

class NumberCharacteristic {
    
public:
    
    static int lengthOf(long number);
    static bool isPalindromic(int n);
    static bool isPalindromic(vector<int> vector);
    static bool is1To9Pandigital(long number);
    
    private :
    NumberCharacteristic() {};
};

#endif

