//http://projecteuler.net/problem=22

#include "problem22.h"
#include "stringCalculator.h"
#include "fileReader.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

const Problem22 Problem22::INSTANCE = Problem22();

void Problem22::run() const {
    vector<string> names = FileReader::readStringFile("names.txt");
    
    sort(names.begin(), names.end());
    
    long sum = 0;
    for (int i = 0; i < names.size(); ++i) {
        string name = names[i];
        long nameScore = StringCalculator::getStringScore(names[i]);
        sum += nameScore * (i + 1);
    }
    
    cout << "Total Scores Sum For Names is: " << sum << endl << endl;
}




