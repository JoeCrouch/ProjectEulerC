//http://projecteuler.net/problem=3

#ifndef ProjectEulerC_problem3_h
#define ProjectEulerC_problem3_h

#include "problem.h"

class Problem3 : public Problem {
    
public:
    static const Problem3 INSTANCE;
    void run() const;
    
private:
    Problem3() {};
};

#endif
