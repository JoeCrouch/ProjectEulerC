
#ifndef ProjectEulerC_factoriser_h
#define ProjectEulerC_factoriser_h

#include <vector>
using std::vector;

class Factoriser {
    
public:
    
    static bool hasFactorIn(int number, vector<int> factors);
    static vector<long> factorise(long long number);
    static vector<long> divisorsFor(long number);
    
private :
    Factoriser() {};
};

#endif
