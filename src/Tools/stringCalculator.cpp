
#include "stringCalculator.h"

long StringCalculator::getStringScore(string word) {
    long score = 0;
    
    for (string::iterator it = word.begin(); it != word.end(); ++it) {
        score += *it - 'A' + 1;
    }
    
    return score;
}
