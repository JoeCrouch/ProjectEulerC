//http://projecteuler.net/problem=19

#include "problem19.h"
#include "date.h"
#include <iostream>

using std::cout;
using std::endl;

const Problem19 Problem19::INSTANCE = Problem19();

void Problem19::run() const {
    Date date = Date(7, 1, 1900);

    int count = 0;
    while (date.getYear() < 2001) {
        if (date.getDay() == 1 && date .getYear() > 1900) {
            count++;
        }

        date.addDays(7);
    }

    cout << "The number of Sundays on the first of the month in the 20th century is: " << count << endl << endl;
}




