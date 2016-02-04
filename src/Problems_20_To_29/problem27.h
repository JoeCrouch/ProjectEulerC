//http://projecteuler.net/problem=27

#ifndef ProjectEulerC_problem27_h
#define ProjectEulerC_problem27_h

#include "problem.h"

class Problem27 : public Problem {
    
public:
    static const Problem27 INSTANCE;
    void run() const;
    
private:
    Problem27() {};
};

#endif
