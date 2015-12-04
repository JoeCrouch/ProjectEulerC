//http://projecteuler.net/problem=4

#ifndef ProjectEulerC_problem4_h
#define ProjectEulerC_problem4_h

#include "problem.h"

class Problem4 : public Problem {
    
public:
    static const Problem4 INSTANCE;
    void run() const;
    
private:
    Problem4() {};
};

#endif

