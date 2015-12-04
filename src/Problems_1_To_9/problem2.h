//http://projecteuler.net/problem=2

#ifndef ProjectEulerC_problem2_h
#define ProjectEulerC_problem2_h

#include "problem.h"

class Problem2 : public Problem {
    
public:
    static const Problem2 INSTANCE;
    void run() const;
    
private:
    Problem2() {};
};

#endif
