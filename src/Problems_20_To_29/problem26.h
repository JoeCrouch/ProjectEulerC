//http://projecteuler.net/problem=26

#ifndef ProjectEulerC_problem26_h
#define ProjectEulerC_problem26_h

#include "problem.h"

class Problem26 : public Problem {
    
public:
    static const Problem26 INSTANCE;
    void run() const;
    
private:
    Problem26() {};
};

#endif
