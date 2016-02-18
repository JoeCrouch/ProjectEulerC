
#ifndef ProjectEulerC_fileReader_h
#define ProjectEulerC_fileReader_h

#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;

class FileReader {
public:
    
    template<typename T>
    static vector<T> readFile(string fileName, vector<T> (*readContents)(ifstream& f)) {
        ifstream file;
        
        file.open(fileName);
        
        if (!file.good()) {
            throw std::runtime_error("could not open file" + fileName);
        }
        
        vector<T> fileContents = (*readContents)(file);
        
        file.close();
        
        return fileContents;
    }
    
    static vector<string> readStringFile(string fileName);
    
private:
    FileReader() {};
};


#endif
