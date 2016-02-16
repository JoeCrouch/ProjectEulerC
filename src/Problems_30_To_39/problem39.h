//http://projecteuler.net/problem=39

#ifndef ProjectEulerC_problem39_h
#define ProjectEulerC_problem39_h

#include "problem.h"

class Problem39 : public Problem {
    
public:
    static const Problem39 INSTANCE;
    void run() const;
    
private:
    Problem39() {};
};

#endif
