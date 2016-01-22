//http://projecteuler.net/problem=60

#include "problem60.h"
#include "calculator.h"
#include "searcher.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::find;

const Problem60 Problem60::INSTANCE = Problem60();

vector<int> concatanatedPrimesGreaterThanPosition(int number, vector<int> primes);

void Problem60::run() const {
    int upperBoundForPrimes = 10000;
    int lowerBoundForSumOfPrimes = 5 * upperBoundForPrimes;
    
    Calculator calc = Calculator::instace();
    vector<int> primes = calc.buildVectorOfPrimesBelow(upperBoundForPrimes);

    map<int, vector<int>> concatanatedPrimes;

    for (int a = 1; a < primes.size(); ++a) {
        int primeA = primes[a];
        
        if (primeA * 5 > lowerBoundForSumOfPrimes) {
            break;
        } else if (concatanatedPrimes.find(primeA) == concatanatedPrimes.end()) {
            concatanatedPrimes[primeA] = concatanatedPrimesGreaterThanPosition(a, primes);
        }
        
        vector<int> concatanatedPrimesForA = concatanatedPrimes[primeA];

        for (int b = a + 1; b < primes.size(); ++b) {
            int primeB = primes[b];
            
            if (primeA + primeB * 4 > lowerBoundForSumOfPrimes) {
                break;
            } else if (!Searcher::vectorContains(concatanatedPrimesForA, primeB)) {
                continue;
            } else if (concatanatedPrimes.find(primeB) == concatanatedPrimes.end()) {
                concatanatedPrimes[primeB] = concatanatedPrimesGreaterThanPosition(b, primes);
            }
            
            vector<int> concatanatedPrimesForB = concatanatedPrimes[primeB];

            for (int c = b + 1; c < primes.size(); ++c) {
                int primeC = primes[c];
                
                if (primeA + primeB + primeC * 3 > lowerBoundForSumOfPrimes) {
                    break;
                } else if (!Searcher::vectorContains(concatanatedPrimesForA, primeC)
                           || !Searcher::vectorContains(concatanatedPrimesForB, primeC)) {
                    continue;
                } else if (concatanatedPrimes.find(primeC) == concatanatedPrimes.end()) {
                    concatanatedPrimes[primeC] = concatanatedPrimesGreaterThanPosition(c, primes);
                }
                
                vector<int> concatanatedPrimesForC = concatanatedPrimes[primeC];

                for (int d = c + 1; d < primes.size(); ++d) {
                    int primeD = primes[d];
                    
                    if (primeA + primeB + primeC + primeD * 2 > lowerBoundForSumOfPrimes) {
                        break;
                    } else if (!Searcher::vectorContains(concatanatedPrimesForA, primeD)
                               || !Searcher::vectorContains(concatanatedPrimesForB, primeD)
                               || !Searcher::vectorContains(concatanatedPrimesForC, primeD))  {
                       continue;
                    } else if (concatanatedPrimes.find(primeD) == concatanatedPrimes.end()) {
                        concatanatedPrimes[primeD] = concatanatedPrimesGreaterThanPosition(d, primes);
                    }
                    
                    vector<int> concatanatedPrimesForD = concatanatedPrimes[primeD];

                    for (int e = d + 1; e < primes.size(); ++e) {
                        int primeE = primes[e];
                        
                        if(primeA + primeB + primeC + primeD + primeE > lowerBoundForSumOfPrimes) {
                            break;
                        } else if (!Searcher::vectorContains(concatanatedPrimesForA, primeE)
                            || !Searcher::vectorContains(concatanatedPrimesForB, primeE)
                            || !Searcher::vectorContains(concatanatedPrimesForC, primeE)
                            || !Searcher::vectorContains(concatanatedPrimesForD, primeE)) {
                            continue;
                        }
                        
                        lowerBoundForSumOfPrimes = primeA + primeB + primeC + primeD + primeE;
                        cout << "New Lower Bound: "
                        << primeA << " + " << primeB << " + " << primeC << " + " << primeD << " + " << primeE
                        << " = " << lowerBoundForSumOfPrimes
                        << endl;
                    }
                }
            }
        }
    }
}


//Checks which primes concatenate both ways round to another prime
vector<int> concatanatedPrimesGreaterThanPosition(int number, vector<int> primes) {
    vector<int> concatanatedPrimesForNumber;
    
    Calculator calc = Calculator::instace();
    for (int i = number + 1; i < primes.size(); i++) {
        if (calc.isPrime(calc.conc(primes[number], primes[i])) && calc.isPrime(calc.conc(primes[i], primes[number]))) {
            concatanatedPrimesForNumber.push_back(primes[i]);
        }
    }
    
    return concatanatedPrimesForNumber;
}
