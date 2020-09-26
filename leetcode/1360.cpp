#include<time.h>
#include<string>
#include<chrono>
#include<iostream>

using namespace std;

int daysBetweenDates(string date1, string date2)
{
    using namespace std::chrono;
    int yyyy, mm, dd;
    char scanf_format[] = "%4d-%2d-%2d";
    sscanf(date1.c_str(), scanf_format, &yyyy, &mm, &dd);
    std::tm timeinfo = std::tm();
    timeinfo.tm_year = yyyy - 1900; // year: 2000
    timeinfo.tm_mon = mm - 1;           // month: january
    timeinfo.tm_mday = dd;          // day: 1st
    std::time_t t1 = std::mktime(&timeinfo);

    sscanf(date2.c_str(), scanf_format, &yyyy, &mm, &dd);
    timeinfo.tm_year = yyyy - 1900; // year: 2000
    timeinfo.tm_mon = mm - 1;           // month: january
    timeinfo.tm_mday = dd;          // day: 1st
    std::time_t t2 = std::mktime(&timeinfo);

    system_clock::time_point tp1 = system_clock::from_time_t(t1);
    system_clock::time_point tp2 = system_clock::from_time_t(t2);
    system_clock::duration d = tp2 - tp1;
    typedef duration<int, std::ratio<60 * 60 * 24>> days_type;
    days_type ndays = duration_cast<days_type>(d);
    return abs(ndays.count());
}

int main()
{
    string date1("2074-09-12");
    string date2("1983-01-08");

    cout << daysBetweenDates(date1, date2) << endl;
}