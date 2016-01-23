//http://projecteuler.net/problem=5

#ifndef ProjectEulerC_problem5_h
#define ProjectEulerC_problem5_h

#include "problem.h"

class Problem5 : public Problem {
    
public:
    static const Problem5 INSTANCE;
    void run() const;
    
private:
    Problem5() {};
};

#endif
