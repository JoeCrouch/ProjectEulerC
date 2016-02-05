//http://projecteuler.net/problem=29

#ifndef ProjectEulerC_problem29_h
#define ProjectEulerC_problem29_h

#include "problem.h"

class Problem29 : public Problem {
    
public:
    static const Problem29 INSTANCE;
    void run() const;
    
private:
    Problem29() {};
};

#endif
