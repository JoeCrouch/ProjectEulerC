
#ifndef ProjectEulerC_transformer_h
#define ProjectEulerC_transformer_h

#include <stdio.h>
#include <vector>

using std::vector;

class Transformer {
public:
    static vector<int> asVector(int n);
    
private:
    Transformer() {};
};

#endif
