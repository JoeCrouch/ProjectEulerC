//http://projecteuler.net/problem=7

#ifndef ProjectEulerC_problem7_h
#define ProjectEulerC_problem7_h

#include "problem.h"

class Problem7 : public Problem {
    
public:
    static const Problem7 INSTANCE;
    void run() const;
    
private:
    Problem7() {};
};

#endif
