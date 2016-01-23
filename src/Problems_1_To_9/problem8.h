//http://projecteuler.net/problem=8

#ifndef ProjectEulerC_problem8_h
#define ProjectEulerC_problem8_h

#include "problem.h"

class Problem8 : public Problem {
    
public:
    static const Problem8 INSTANCE;
    void run() const;
    
private:
    Problem8() {};
};

#endif
