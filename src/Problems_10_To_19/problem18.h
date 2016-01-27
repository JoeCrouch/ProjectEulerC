//http://projecteuler.net/problem=18

#ifndef ProjectEulerC_problem18_h
#define ProjectEulerC_problem18_h

#include "problem.h"

class Problem18 : public Problem {
    
public:
    static const Problem18 INSTANCE;
    void run() const;
    
private:
    Problem18() {};
};

#endif
