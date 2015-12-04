//http://projecteuler.net/problem=10

#ifndef ProjectEulerC_problem10_h
#define ProjectEulerC_problem10_h

#include "problem.h"

class Problem10 : public Problem {
    
public:
    static const Problem10 INSTANCE;
    void run() const;
    
private:
    Problem10() {};
};

#endif
