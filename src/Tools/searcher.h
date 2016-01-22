
#ifndef ProjectEulerC_searcher_h
#define ProjectEulerC_searcher_h

#include <vector>

using std::vector;

class Searcher {
public:
    
    template<typename T>
    static bool vectorContains(vector<T> vector, T entry) {
        return find(vector.begin(), vector.end(), entry) != vector.end();
    }
    
private:
    Searcher() {};
};


#endif
