
#ifndef ProjectEulerC_printer_h
#define ProjectEulerC_printer_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::vector;

class Printer {

public:

    template<typename T>
    static void vecPrint(vector<T> vectorToPrint) {
        for (typename vector<T>::iterator it = vectorToPrint.begin(); it < vectorToPrint.end(); ++it) {
            cout << setw(5) << *it;
        }
        cout << endl;
        return;
    }

    template<typename T>
    static void matPrint(vector<vector<T>> matrix) {
        for (typename vector<vector<T>>::iterator it = matrix.begin(); it < matrix.end(); ++it) {
            Printer::vecPrint(*it);
        }
        cout << endl << endl;
    }

private :
    Printer() {};
};

#endif
