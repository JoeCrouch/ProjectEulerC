//http://projecteuler.net/problem=34

#ifndef ProjectEulerC_problem34_h
#define ProjectEulerC_problem34_h

#include "problem.h"

class Problem34 : public Problem {
    
public:
    static const Problem34 INSTANCE;
    void run() const;
    
private:
    Problem34() {};
};

#endif
