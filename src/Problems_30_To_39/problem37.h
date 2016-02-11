//http://projecteuler.net/problem=37

#ifndef ProjectEulerC_problem37_h
#define ProjectEulerC_problem37_h

#include "problem.h"

class Problem37 : public Problem {
    
public:
    static const Problem37 INSTANCE;
    void run() const;
    
private:
    Problem37() {};
};

#endif
