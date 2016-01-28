
#ifndef ProjectEulerC_date_h
#define ProjectEulerC_date_h

class Date {

public:
    Date(int day, int month, int year);
    int getDay();
    int getMonth();
    int getYear();
    void addDays(int days);

    static int maxDayForMonth(int month, int year);
    static bool isLeapYear(int year);

private:
    Date();
    int day_;
    int month_;
    int year_;
};

#endif
