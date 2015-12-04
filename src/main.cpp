#include "problem1.h"
#include "problem2.h"
#include "problem3.h"
#include "problem4.h"
#include "problem6.h"
#include "problem7.h"
#include "problem9.h"
#include "problem10.h"
#include "problem11.h"
#include "problem16.h"
#include "problem60.h"

#include <iostream>
#include <ctime>
#include <string>
#include <map>

using std::map;
using std::clock_t;
using std::cout;
using std::cin;
using std::endl;
using std::string;

map<int, const Problem*> availableProblems();
map<int, const Problem*> problems = availableProblems();

int main() {
    
    int input = 0;
    while (input != -1) {
        cout << endl << "Which Problem Would You Like To Run? (Enter -1 To Stop Running Programs)" << endl;
        cin >> input;
        
        map<int, const Problem*>::iterator find = problems.find(input);
        map<int, const Problem*>::iterator end = problems.end();
        if (find != end) {
            
            cout << "Problem " << input << ": " << endl;
            double time = 0;
            
            find->second->run();
            
            clock_t t1 = clock();
            time = time + (double)(t1) / CLOCKS_PER_SEC;
            cout << "Time Taken = " << time << " seconds." <<endl;
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
        problems[6] = &(Problem6::INSTANCE);
        problems[7] = &(Problem7::INSTANCE);
        problems[9] = &(Problem9::INSTANCE);
        problems[10] = &(Problem10::INSTANCE);
        problems[11] = &(Problem11::INSTANCE);
        problems[16] = &(Problem16::INSTANCE);
        problems[60] = &(Problem60::INSTANCE);
    }
    
    return problems;
}