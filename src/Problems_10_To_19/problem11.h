//http://projecteuler.net/problem=11

#ifndef ProjectEulerC_problem11_h
#define ProjectEulerC_problem11_h

#include "problem.h"

class Problem11 : public Problem {
    
public:
    static const Problem11 INSTANCE;
    void run() const;
    
private:
    Problem11() {};
};

#endif
