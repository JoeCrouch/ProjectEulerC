//http://projecteuler.net/problem=16

#ifndef ProjectEulerC_problem16_h
#define ProjectEulerC_problem16_h

#include "problem.h"

class Problem16 : public Problem {
    
public:
    static const Problem16 INSTANCE;
    void run() const;
    
private:
    Problem16() {};
};

#endif
