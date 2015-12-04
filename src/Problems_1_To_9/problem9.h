//http://projecteuler.net/problem=9

#ifndef ProjectEulerC_problem9_h
#define ProjectEulerC_problem9_h

#include "problem.h"

class Problem9 : public Problem {
    
public:
    static const Problem9 INSTANCE;
    void run() const;
    
private:
    Problem9() {};
};

#endif

