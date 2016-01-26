
#ifndef ProjectEulerC_transformer_h
#define ProjectEulerC_transformer_h

#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Transformer {
public:
    static vector<int> asVector(int n);
    static vector<int> asVector(string n);
    static string numberAsWord(int number);
    
private:
    Transformer() {};
};

#endif
