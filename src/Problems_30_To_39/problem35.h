//http://projecteuler.net/problem=35

#ifndef ProjectEulerC_problem35_h
#define ProjectEulerC_problem35_h

#include "problem.h"

class Problem35 : public Problem {
    
public:
    static const Problem35 INSTANCE;
    void run() const;
    
private:
    Problem35() {};
};

#endif
