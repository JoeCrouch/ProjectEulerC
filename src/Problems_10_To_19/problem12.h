//http://projecteuler.net/problem=12

#ifndef ProjectEulerC_problem12_h
#define ProjectEulerC_problem12_h

#include "problem.h"

class Problem12 : public Problem {
    
public:
    static const Problem12 INSTANCE;
    void run() const;
    
private:
    Problem12() {};
};

#endif
