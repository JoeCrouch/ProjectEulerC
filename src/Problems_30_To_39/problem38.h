//http://projecteuler.net/problem=38

#ifndef ProjectEulerC_problem38_h
#define ProjectEulerC_problem38_h

#include "problem.h"

class Problem38 : public Problem {
    
public:
    static const Problem38 INSTANCE;
    void run() const;
    
private:
    Problem38() {};
};

#endif
