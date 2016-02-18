#include "problem1.h"
#include "problem2.h"
#include "problem3.h"
#include "problem4.h"
#include "problem5.h"
#include "problem6.h"
#include "problem7.h"
#include "problem8.h"
#include "problem9.h"
#include "problem10.h"
#include "problem11.h"
#include "problem12.h"
#include "problem13.h"
#include "problem14.h"
#include "problem15.h"
#include "problem16.h"
#include "problem17.h"
#include "problem18.h"
#include "problem19.h"
#include "problem20.h"
#include "problem21.h"
#include "problem22.h"
#include "problem23.h"
#include "problem24.h"
#include "problem25.h"
#include "problem26.h"
#include "problem27.h"
#include "problem28.h"
#include "problem29.h"
#include "problem30.h"
#include "problem31.h"
#include "problem32.h"
#include "problem33.h"
#include "problem34.h"
#include "problem35.h"
#include "problem36.h"
#include "problem37.h"
#include "problem38.h"
#include "problem39.h"
#include "problem40.h"
#include "problem41.h"
#include "problem42.h"
#include "problem60.h"
#include "problem67.h"

#include <iostream>
#include <ctime>
#include <string>
#include <map>

using std::map;
using std::clock_t;
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::string;

map<int, const Problem*> availableProblems();
map<int, const Problem*> problems = availableProblems();

int main() {

    int input = 0;
    while (input != -1) {
        cout << endl << "Which Problem Would You Like To Run? (Enter -1 To Stop Running Programs)" << endl;
        cin >> input;

        map<int, const Problem*>::iterator find = problems.find(input);
        if (find != problems.end()) {

            cout << "Problem " << input << ": " << endl << endl;

            clock_t t1 = clock();

            find->second->run();

            clock_t t2 = clock();
            double time = (double) (t2 - t1) / CLOCKS_PER_SEC;
            cout << fixed << "Time Taken = " << time << " seconds." << endl;
        } else if (input != -1) {
            cout << endl << input << " is not a currently available problem." << endl;
            cout << "Try one of: " << endl;
            for (map<int, const Problem*>::iterator it = problems.begin(); it != problems.end(); it++) {
                cout << it->first << endl;
            }
            cout << endl;
        }
    }
    return 0;
}

map<int, const Problem*> availableProblems() {
    static map<int, const Problem*> problems;

    if (problems.size() == 0) {
        problems[1] = &(Problem1::INSTANCE);
        problems[2] = &(Problem2::INSTANCE);
        problems[3] = &(Problem3::INSTANCE);
        problems[4] = &(Problem4::INSTANCE);
        problems[5] = &(Problem5::INSTANCE);
        problems[6] = &(Problem6::INSTANCE);
        problems[7] = &(Problem7::INSTANCE);
        problems[8] = &(Problem8::INSTANCE);
        problems[9] = &(Problem9::INSTANCE);
        problems[10] = &(Problem10::INSTANCE);
        problems[11] = &(Problem11::INSTANCE);
        problems[12] = &(Problem12::INSTANCE);
        problems[13] = &(Problem13::INSTANCE);
        problems[14] = &(Problem14::INSTANCE);
        problems[15] = &(Problem15::INSTANCE);
        problems[16] = &(Problem16::INSTANCE);
        problems[17] = &(Problem17::INSTANCE);
        problems[18] = &(Problem18::INSTANCE);
        problems[19] = &(Problem19::INSTANCE);
        problems[20] = &(Problem20::INSTANCE);
        problems[21] = &(Problem21::INSTANCE);
        problems[22] = &(Problem22::INSTANCE);
        problems[23] = &(Problem23::INSTANCE);
        problems[24] = &(Problem24::INSTANCE);
        problems[25] = &(Problem25::INSTANCE);
        problems[26] = &(Problem26::INSTANCE);
        problems[27] = &(Problem27::INSTANCE);
        problems[28] = &(Problem28::INSTANCE);
        problems[29] = &(Problem29::INSTANCE);
        problems[30] = &(Problem30::INSTANCE);
        problems[31] = &(Problem31::INSTANCE);
        problems[32] = &(Problem32::INSTANCE);
        problems[33] = &(Problem33::INSTANCE);
        problems[34] = &(Problem34::INSTANCE);
        problems[35] = &(Problem35::INSTANCE);
        problems[36] = &(Problem36::INSTANCE);
        problems[37] = &(Problem37::INSTANCE);
        problems[38] = &(Problem38::INSTANCE);
        problems[39] = &(Problem39::INSTANCE);
        problems[40] = &(Problem40::INSTANCE);
        problems[41] = &(Problem41::INSTANCE);
        problems[42] = &(Problem42::INSTANCE);
        problems[60] = &(Problem60::INSTANCE);
        problems[67] = &(Problem67::INSTANCE);
    }

    return problems;
}
