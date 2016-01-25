//http://projecteuler.net/problem=15

#ifndef ProjectEulerC_problem15_h
#define ProjectEulerC_problem15_h

#include "problem.h"

class Problem15 : public Problem {
    
public:
    static const Problem15 INSTANCE;
    void run() const;
    
private:
    Problem15() {};
};

#endif
