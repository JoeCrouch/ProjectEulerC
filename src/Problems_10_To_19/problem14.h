//http://projecteuler.net/problem=14

#ifndef ProjectEulerC_problem14_h
#define ProjectEulerC_problem14_h

#include "problem.h"

class Problem14 : public Problem {
    
public:
    static const Problem14 INSTANCE;
    void run() const;
    
private:
    Problem14() {};
};

#endif
