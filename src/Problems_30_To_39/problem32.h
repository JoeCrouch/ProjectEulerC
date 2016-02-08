//http://projecteuler.net/problem=32

#ifndef ProjectEulerC_problem32_h
#define ProjectEulerC_problem32_h

#include "problem.h"

class Problem32 : public Problem {
    
public:
    static const Problem32 INSTANCE;
    void run() const;
    
private:
    Problem32() {};
};

#endif
