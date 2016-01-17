
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
            cout << *it << " ";
        }
        cout << endl;
        return;
    }

    template<typename T>
    static void vecPrint(vector<T> vectorToPrint, int width) {
        for (typename vector<T>::iterator it = vectorToPrint.begin(); it < vectorToPrint.end(); ++it) {
            cout << setw(width) << *it;
        }
        cout << endl;
        return;
    }

    template<typename T>
    static void matPrint(vector<vector<T>> matrix, int width) {
        for (typename vector<vector<T>>::iterator it = matrix.begin(); it < matrix.end(); ++it) {
            Printer::vecPrint(*it, width);
        }
        cout << endl << endl;
    }

private :
    Printer() {};
};

#endif
