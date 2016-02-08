
#include "transformer.h"
#include <stdio.h>
#include <cstdlib>
#include <sstream>

using std::stringstream;

string tensAsWord(int tens);

vector<int> Transformer::asVector(long n) {
    vector<int> nAsVector;

    int individualDigit = n % 10;

    nAsVector.push_back(individualDigit);

    if (n != individualDigit) {
        long nWithoutLastDigit = (n - individualDigit) / 10;
        vector<int> nWithoutLastDigitAsVector = asVector(nWithoutLastDigit);

        nAsVector.insert(nAsVector.begin(), nWithoutLastDigitAsVector.begin(), nWithoutLastDigitAsVector.end());
    }

    return nAsVector;
}

vector<int> Transformer::asVector(string n) {
    vector<int> stringAsIntVector;

    for (string::iterator it = n.begin(); it != n.end(); ++it) {
        int digit = *it - '0';
        stringAsIntVector.push_back(digit);
    }

    return stringAsIntVector;
}

vector<int> Transformer::asVector(string n, char delimeter) {
    vector<int> stringAsIntVector;
    stringstream ss(n);

    string num;
    while (getline(ss, num, delimeter)) {
        stringAsIntVector.push_back(atoi(num.c_str()));
    }

    return stringAsIntVector;
}

string Transformer::numberAsWord(int number) {
    if (number < 20) {
        switch (number) {
            case 0:
                return "Zero";
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
            case 10:
                return "Ten";
            case 11:
                return "Eleven";
            case 12:
                return "Twelve";
            case 13:
                return "Thirteen";
            case 14:
                return "Fourteen";
            case 15:
                return "Fifteen";
            case 16:
                return "Sixteen";
            case 17:
                return "Seventeen";
            case 18:
                return "Eighteen";
            case 19:
                return "Nineteen";
        }
    } else if (number < 100) {
        int units = number % 10;
        string unitsString = units == 0 ? "" : numberAsWord(units);
        int tens = (number - units) / 10;
        return tensAsWord(tens) + unitsString;
    } else if (number < 1000) {
        int remainder = number % 100;
        string remainderString = remainder == 0 ? "" : "And" + numberAsWord(remainder);
        int hundreds = (number - remainder) / 100;
        return numberAsWord(hundreds) + "Hundred" + remainderString;
    } else {
        int remainder = number % 1000;
        string remainderString = remainder == 0 ? "" : numberAsWord(remainder);
        int thousands = (number - remainder) / 1000;
        return numberAsWord(thousands) + "Thousand" + remainderString;
    }

    return "Error Number must be positive and less than 1,000,000";
}

string tensAsWord(int tens) {
    switch (tens) {
        case 2:
            return "Twenty";
        case 3:
            return "Thirty";
        case 4:
            return "Forty";
        case 5:
            return "Fifty";
        case 6:
            return "Sixty";
        case 7:
            return "Seventy";
        case 8:
            return "Eighty";
        case 9:
            return "Ninety";
        default:
            return "Error: number must be single positive digit greater than 1";
    }
}
