//http://projecteuler.net/problem=30

#ifndef ProjectEulerC_problem30_h
#define ProjectEulerC_problem30_h

#include "problem.h"

class Problem30 : public Problem {
    
public:
    static const Problem30 INSTANCE;
    void run() const;
    
private:
    Problem30() {};
};

#endif
