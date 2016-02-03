//http://projecteuler.net/problem=24

#ifndef ProjectEulerC_problem24_h
#define ProjectEulerC_problem24_h

#include "problem.h"

class Problem24 : public Problem {
    
public:
    static const Problem24 INSTANCE;
    void run() const;
    
private:
    Problem24() {};
};

#endif
