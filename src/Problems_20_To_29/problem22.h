//http://projecteuler.net/problem=22

#ifndef ProjectEulerC_problem22_h
#define ProjectEulerC_problem22_h

#include "problem.h"

class Problem22 : public Problem {
    
public:
    static const Problem22 INSTANCE;
    void run() const;
    
private:
    Problem22() {};
};

#endif
