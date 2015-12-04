//http://projecteuler.net/problem=16

#include "problem16.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using std::cout;
using std::endl;
using std::setw;

//TODO: better variable names!
const Problem16 Problem16::INSTANCE = Problem16();

int *doubling2(int *A,int n,int a);
void VecPrint(int *Y,int n);
int *VecMake(int n);

void Problem16::run() const {
    int *A;
    int a = 1000, n = 302, sum = 0;

    A = VecMake(n);
    A = doubling2(A,n,a);
    
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    
    cout << "2 ^ 1000 = " << endl;
    
    VecPrint(A, 302);
    
    cout << "The sum of these digits is: " << endl;
    cout << sum << endl << endl;
}

//TODO: extract
int *doubling2 (int *A, int n, int a) {
    A[0]=1;
    
    for (int i = 1; i < n; i++) {
        A[i] = 0;
    }
    
    int j = 1;
    while (j <= a) {
        for (int i = 0; i <= n; i++) {
            if (A[i] != 0) {
                A[i] = A[i] * 2;
            }
        }
        for (int i=0; i <= n; i++){
            if (A[i] >= 10) {
                A[i] = A[i] - 10;
                A[i+1] = A[i+1] + 1;
            }
        }
        j++;
    }
    return A;
}

//TODO: extract
void VecPrint(int *Y, int n) {
    for (int i = n-1; i >= 0; i--) {
        cout << setw(1) << Y[i];
    }
    cout << "\n\n";
    return;
}

//TODO: extract
int *VecMake(int n) {
    int *Y;
    Y = (int *) malloc((n + 1) * sizeof(int));
    return(Y);
}
