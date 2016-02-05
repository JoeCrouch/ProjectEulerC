//http://projecteuler.net/problem=31

#ifndef ProjectEulerC_problem31_h
#define ProjectEulerC_problem31_h

#include "problem.h"

class Problem31 : public Problem {
    
public:
    static const Problem31 INSTANCE;
    void run() const;
    
private:
    Problem31() {};
};

#endif
