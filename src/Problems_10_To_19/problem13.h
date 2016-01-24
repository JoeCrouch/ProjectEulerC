//http://projecteuler.net/problem=13

#ifndef ProjectEulerC_problem13_h
#define ProjectEulerC_problem13_h

#include "problem.h"

class Problem13 : public Problem {
    
public:
    static const Problem13 INSTANCE;
    void run() const;
    
private:
    Problem13() {};
};

#endif
