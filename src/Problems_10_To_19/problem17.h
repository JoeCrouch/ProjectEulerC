//http://projecteuler.net/problem=17

#ifndef ProjectEulerC_problem17_h
#define ProjectEulerC_problem17_h

#include "problem.h"

class Problem17 : public Problem {
    
public:
    static const Problem17 INSTANCE;
    void run() const;
    
private:
    Problem17() {};
};

#endif
