//http://projecteuler.net/problem=42

#include "problem42.h"
#include "searcher.h"
#include "stringCalculator.h"
#include "calculator.h"
#include "fileReader.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

const Problem42 Problem42::INSTANCE = Problem42();

void Problem42::run() const {
    vector<string> words = FileReader::readStringFile("words.txt");
    vector<long> stringScores;
    long maxWordScore = 0;
    
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
        long wordScore = StringCalculator::getStringScore(*it);
        stringScores.push_back(wordScore);
        maxWordScore = wordScore > maxWordScore ? wordScore : maxWordScore;
    }
    
    vector<long> triangleNumbers = Calculator::getTriangleNumbersLessThanOrEqualTo(maxWordScore);
    
    int count = 0;
    for (vector<long>::iterator it = stringScores.begin(); it != stringScores.end(); ++it) {
        if (Searcher::vectorContains(triangleNumbers, *it)) {
            count++;
        }
    }
    
    cout << "Total triangle words in file is: " << count << endl << endl;
    
}

