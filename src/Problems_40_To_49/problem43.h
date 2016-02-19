//http://projecteuler.net/problem=43

#ifndef ProjectEulerC_problem43_h
#define ProjectEulerC_problem43_h

#include "problem.h"

class Problem43 : public Problem {
    
public:
    static const Problem43 INSTANCE;
    void run() const;
    
private:
    Problem43() {};
};

#endif
