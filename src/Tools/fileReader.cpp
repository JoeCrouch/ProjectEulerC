
#include "fileReader.h"

vector<string> readString(ifstream& file);

vector<string> FileReader::readStringFile(string fileName) {
    return readFile<string>(fileName, readString);
}

vector<string> readString(ifstream& file) {
    vector<string> words;
    
    string word;
    while (getline(file, word, ',')) {
        word = word.substr(1, word.size() - 2);
        words.push_back(word);
    }
    
    return words;
}


