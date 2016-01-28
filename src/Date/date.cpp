
#include "date.h"
#include <stdexcept>

using std::invalid_argument;

Date::Date(int day, int month, int year) : day_(day), month_(month), year_(year) {
    if (month < 1 || month > 12) {
        throw invalid_argument("month must be between 1 and 12 (inclusive)");
    } else if (day < 1 || day > maxDayForMonth(month, year)) {
        throw invalid_argument("day must be between 1 and max day for the month (inclusive)");
    }
}

int Date::maxDayForMonth(int month, int year) {
    if (month < 1 || month > 12) {
        throw invalid_argument("month must be between 1 and 12 (inclusive)");
    }

    switch (month) {
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
            return 30;
        case 6:
            return 30;
        case 9:
            return 30;
        case 11:
            return 30;
        default:
            return 31;
    }
}

bool Date::isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int Date::getDay() {
    return day_;
}

int Date::getMonth() {
    return month_;
}
int Date::getYear() {
    return year_;
}
void Date::addDays(int days) {
    day_ += days;

    while (day_ > maxDayForMonth(month_, year_)) {
        day_ = day_ - maxDayForMonth(month_, year_);
        month_ += 1;

        if (month_ > 12) {
            month_ = 1;
            year_ += 1;
        }
    }
}


