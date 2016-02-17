
#ifndef ProjectEulerC_transformer_h
#define ProjectEulerC_transformer_h

#include <stdio.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Transformer {
public:
    static vector<int> asVector(long n);
    static int asNumber(vector<int> numberAsVector);
    static vector<int> asVector(string n);
    static vector<int> asVector(string n, char delimeter);
    static string numberAsWord(int number);
    static vector<int> inBinary(int n);
    
private:
    Transformer() {};
};

#endif
