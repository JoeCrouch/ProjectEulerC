//http://projecteuler.net/problem=19

#ifndef ProjectEulerC_problem19_h
#define ProjectEulerC_problem19_h

#include "problem.h"

class Problem19 : public Problem {

public:
    static const Problem19 INSTANCE;
    void run() const;

private:
    Problem19() {};
};

#endif
