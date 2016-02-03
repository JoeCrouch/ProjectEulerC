//http://projecteuler.net/problem=25

#ifndef ProjectEulerC_problem25_h
#define ProjectEulerC_problem25_h

#include "problem.h"

class Problem25 : public Problem {
    
public:
    static const Problem25 INSTANCE;
    void run() const;
    
private:
    Problem25() {};
};

#endif
