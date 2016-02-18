//http://projecteuler.net/problem=42

#ifndef ProjectEulerC_problem42_h
#define ProjectEulerC_problem42_h

#include "problem.h"

class Problem42 : public Problem {
    
public:
    static const Problem42 INSTANCE;
    void run() const;
    
private:
    Problem42() {};
};

#endif
