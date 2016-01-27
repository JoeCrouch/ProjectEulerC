//http://projecteuler.net/problem=67

#ifndef ProjectEulerC_problem67_h
#define ProjectEulerC_problem67_h

#include "problem.h"

class Problem67 : public Problem {
    
public:
    static const Problem67 INSTANCE;
    void run() const;
    
private:
    Problem67() {};
};

#endif
