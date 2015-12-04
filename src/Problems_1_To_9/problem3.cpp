//http://projecteuler.net/problem=3

#include "problem3.h"
#include <iostream>
#include <iomanip>

using std::setw;
using std::cout;
using std::endl;

//TODO: This entire file and probaly ALL FILES: WTF was I naming these variables?
long int factors[100];
void vecPrint(long int *Y,int n);
void primefactors(long long int n, int s);

const Problem3 Problem3::INSTANCE = Problem3();

void Problem3::run() const {
    int s = 0;
    long long n = 600851475143;
    long int d;
    
    primefactors(n, s);
    cout << "Prime factors of 600851475143 are: " << endl;
    
    vecPrint(factors, 100);
    d = factors[0];
    for (int i = 1; i < 100; i++) {
        if (factors[i] == 0) {
            break;
        }else if (factors[i] > d) {
            d = factors[i];
        }
    }
    cout << "Largest Prime = " << d << endl << endl;
}

//TODO: extract into tool
void vecPrint(long int *Y,int n){
    for (int i = 0; i < n + 1; i++) {
        if (Y[i] != 0) {
            cout << setw(10) << Y[i] << endl;
            //TODO: WTF!? if its zero just give up? Why not using vector?
        } else {
            return;
        }
    }
    return;
}

//TODO: again extract into tool.
void primefactors(long long int n, int s) {
    long int d = 0;
    
    for(int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            d = i;
            break;
        }
    }
    
    if (d == 0) {
        factors[s] = n;
        return;
    }
    
    factors[s] = d;
    s += 1;
    primefactors(n/d, s);
}
