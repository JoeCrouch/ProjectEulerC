//http://projecteuler.net/problem=33

#ifndef ProjectEulerC_problem33_h
#define ProjectEulerC_problem33_h

#include "problem.h"

class Problem33 : public Problem {
    
public:
    static const Problem33 INSTANCE;
    void run() const;
    
private:
    Problem33() {};
};

#endif
