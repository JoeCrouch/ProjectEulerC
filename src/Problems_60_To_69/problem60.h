//http://projecteuler.net/problem=60

#ifndef ProjectEulerC_problem60_h
#define ProjectEulerC_problem60_h

#include "problem.h"

class Problem60 : public Problem {
    
public:
    static const Problem60 INSTANCE;
    void run() const;
    
private:
    Problem60() {};
};

#endif