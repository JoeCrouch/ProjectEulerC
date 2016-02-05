//http://projecteuler.net/problem=28

#ifndef ProjectEulerC_problem28_h
#define ProjectEulerC_problem28_h

#include "problem.h"

class Problem28 : public Problem {
    
public:
    static const Problem28 INSTANCE;
    void run() const;
    
private:
    Problem28() {};
};

#endif
