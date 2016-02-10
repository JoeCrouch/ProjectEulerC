//http://projecteuler.net/problem=36

#ifndef ProjectEulerC_problem36_h
#define ProjectEulerC_problem36_h

#include "problem.h"

class Problem36 : public Problem {
    
public:
    static const Problem36 INSTANCE;
    void run() const;
    
private:
    Problem36() {};
};

#endif
