//http://projecteuler.net/problem=22

#include "problem22.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::sort;

vector<string> readNameFile();
long getNameScore(string name);

const Problem22 Problem22::INSTANCE = Problem22();

void Problem22::run() const {
    vector<string> names = readNameFile();
    
    sort(names.begin(), names.end());
    
    long sum = 0;
    for (int i = 0; i < names.size(); ++i) {
        string name = names[i];
        long nameScore = getNameScore(names[i]);
        sum += nameScore * (i + 1);
    }
    
    cout << "Total Scores Sum For Names is: " << sum << endl << endl;
}

vector<string> readNameFile() {
    vector<string> names;
    
    ifstream triangleFile;
    
    triangleFile.open("names.txt");
    
    if (!triangleFile.good()) {
        throw std::runtime_error("could not open names.txt");
    }
    
    string name;
    while (getline(triangleFile, name, ',')) {
        name = name.substr(1, name.size() - 2);
        names.push_back(name);
    }
    
    triangleFile.close();
    
    return names;
}

long getNameScore(string name) {
    long score = 0;
    
    for (string::iterator it = name.begin(); it != name.end(); ++it) {
        score += *it - 'A' + 1;
    }
    
    return score;
}




