//http://projecteuler.net/problem=23

#ifndef ProjectEulerC_problem23_h
#define ProjectEulerC_problem23_h

#include "problem.h"

class Problem23 : public Problem {
    
public:
    static const Problem23 INSTANCE;
    void run() const;
    
private:
    Problem23() {};
};

#endif
