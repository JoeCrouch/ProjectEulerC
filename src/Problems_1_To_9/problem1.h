//http://projecteuler.net/problem=1

#ifndef ProjectEulerC_problem1_h
#define ProjectEulerC_problem1_h

#include "problem.h"

class Problem1 : public Problem {
    
public:
    static const Problem1 INSTANCE;
    void run() const;
    
private:
    Problem1() {};
};


#endif
