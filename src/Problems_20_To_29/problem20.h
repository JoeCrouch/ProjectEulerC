//http://projecteuler.net/problem=20

#ifndef ProjectEulerC_problem20_h
#define ProjectEulerC_problem20_h

#include "problem.h"

class Problem20 : public Problem {

public:
    static const Problem20 INSTANCE;
    void run() const;

private:
    Problem20() {};
};

#endif
