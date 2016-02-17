//http://projecteuler.net/problem=40

#ifndef ProjectEulerC_problem40_h
#define ProjectEulerC_problem40_h

#include "problem.h"

class Problem40 : public Problem {
    
public:
    static const Problem40 INSTANCE;
    void run() const;
    
private:
    Problem40() {};
};

#endif
