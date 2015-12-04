//http://projecteuler.net/problem=6

#ifndef ProjectEulerC_problem6_h
#define ProjectEulerC_problem6_h

#include "problem.h"

class Problem6 : public Problem {
    
public:
    static const Problem6 INSTANCE;
    void run() const;
    
private:
    Problem6() {};
};

#endif