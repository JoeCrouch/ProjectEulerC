//http://projecteuler.net/problem=41

#ifndef ProjectEulerC_problem41_h
#define ProjectEulerC_problem41_h

#include "problem.h"

class Problem41 : public Problem {
    
public:
    static const Problem41 INSTANCE;
    void run() const;
    
private:
    Problem41() {};
};

#endif
