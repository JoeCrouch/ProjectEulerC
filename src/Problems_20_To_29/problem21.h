//http://projecteuler.net/problem=21

#ifndef ProjectEulerC_problem21_h
#define ProjectEulerC_problem21_h

#include "problem.h"

class Problem21 : public Problem {

public:
    static const Problem21 INSTANCE;
    void run() const;

private:
    Problem21() {};
};

#endif
