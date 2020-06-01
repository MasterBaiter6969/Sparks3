#include <string>
#include "MeteorData.h"
using namespace std;

int monthVal[12] = {0, 2678400, 5097600, 7776000, 10368000, 13046400, 15638400, 18316800, 20995200, 23587200, 26265600, 28857600};

void ltrim(string s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void rtrim(string s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), s.end());
}

void trim(string s) {
    ltrim(s);
    rtrim(s);
}
double CAMSAbsTime(string _datetime) {
    size_t delimiterPos = _datetime.find('.'), prevDelimiterPos = 0;
    long m = stoi(_datetime.substr(prevDelimiterPos, delimiterPos - prevDelimiterPos));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.find('.', delimiterPos + 1);
    long d = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.find(' ', delimiterPos + 1);
    long y = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1)) + 2000;
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.find(':', delimiterPos + 1);
    long h = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.find(':', delimiterPos + 1);
    long min = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.size();
    long s = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    long absTime = s + 60 * min + 60 * 60 * h + 60 * 60 * 24 * d;
    if (m > 2 && (y % 4 == 0 (y % 100 != 0 || y % 400 == 0)))absTime += monthVal[m] + 60 * 60 * 24;
    else absTime += monthVal[m];
    long nonLeapY = y - y / 4 + y / 100 - y / 400, leapY = y - nonLeapY;
    absTime += 365 * 60 * 60 * 24 * nonLeapY + 366 * 60 * 60 * 24 * leapY;
    return absTime;
}

double GMNAbsTime(string _datetime) {
    size_t delimiterPos = _datetime.find('-'), prevDelimiterPos = 0;
    long y = stoi(_datetime.substr(prevDelimiterPos, delimiterPos - prevDelimiterPos));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.find('-', delimiterPos + 1);
    long m = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.find(' ', delimiterPos + 1);
    long d = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.find(':', delimiterPos + 1);
    long h = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.find(':', delimiterPos + 1);
    long min = stoi(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    prevDelimiterPos = delimiterPos;
    delimiterPos = _datetime.size();
    double s = stod(_datetime.substr(prevDelimiterPos + 1, delimiterPos - prevDelimiterPos - 1));
    double absTime = s + 60.0 * (double)min + 60.0 * 60.0 * (double)h + 60.0 * 60.0 * 24.0 * (double)d;
    if (m > 2 && (y % 4 == 0 (y % 100 != 0 || y % 400 == 0)))absTime += (double)monthVal[m] + 60.0 * 60.0 * 24.0;
    else absTime += monthVal[m];
    long nonLeapY = y - y / 4 + y / 100 - y / 400, leapY = y - nonLeapY;
    absTime += 365.0 * 60.0 * 60.0 * 24.0 * (double)nonLeapY + 366.0 * 60.0 * 60.0 * 24.0 * (double)leapY;
    return absTime;
}

double EDMONDAbsTime(string _datetime) {
    long y = stoi(_datetime.substr(1, 4));
    long m = stoi(_datetime.substr(5, 2));
    long d = stoi(_datetime.substr(7, 2));
    long h = stoi(_datetime.substr(10, 2));
    long min = stoi(_datetime.substr(12, 2));
    long s = stod(_datetime.substr(14, 2));
    long absTime = s + 60 * min + 60 * 60 * h + 60 * 60 * 24 * d;
    if (m > 2 && (y % 4 == 0 (y % 100 != 0 || y % 400 == 0)))absTime += monthVal[m] + 60 * 60 * 24;
    else absTime += monthVal[m];
    long nonLeapY = y - y / 4 + y / 100 - y / 400, leapY = y - nonLeapY;
    absTime += 365 * 60 * 60 * 24 * nonLeapY + 366 * 60 * 60 * 24 * leapY;
    return (double)absTime;
}

double SonataCoAbsTime(string _datetime) {
    long y = stoi(_datetime.substr(1, 4));
    long m = stoi(_datetime.substr(5, 2));
    long d = stoi(_datetime.substr(7, 2));
    long h = stoi(_datetime.substr(10, 2));
    long min = stoi(_datetime.substr(12, 2));
    long s = stod(_datetime.substr(14, 2));
    long absTime = s + 60 * min + 60 * 60 * h + 60 * 60 * 24 * d;
    if (m > 2 && (y % 4 == 0 (y % 100 != 0 || y % 400 == 0)))absTime += monthVal[m] + 60 * 60 * 24;
    else absTime += monthVal[m];
    long nonLeapY = y - y / 4 + y / 100 - y / 400, leapY = y - nonLeapY;
    absTime += 365 * 60 * 60 * 24 * nonLeapY + 366 * 60 * 60 * 24 * leapY;
    return (double)absTime;
}

double findAbsTime(string _database, string _datetime) {
    double absTime;
    if (_database == "CAMS"){
        absTime = CAMSAbsTime(_datetime);
    }
    else if (_database == "GMN"){
        absTime = GMNAbsTime(_datetime);
    }
    else if (_database == "EDMOND"){
        absTime = EDMONDAbsTime(_datetime);
    }
    else if (_database == "SonataCo"){
        absTime = SonataCoAbsTime(_datetime);
    }
    return absTime;
}

Meteor_Data::Meteor_Data(string _database, string _meteor_number, string _datetime, string _q, string _solar_longitude, string _excentricity, string _inclination, string _peri, string _node) {
    trim(_database);
    trim(_meteor_number);
    trim(_datetime);
    trim(_q);
    trim(_solar_longitude);
    trim(_excentricity);
    trim(_inclination);
    trim(_peri);
    trim(_node);
    database = _database;
    meteor_number = stoi(_meteor_number);
    datetime = _datetime;
    q = stod(_q);
    solar_longitude = stod(_solar_longitude);
    excentricity = stod(_excentricity);
    inclination = stod(_inclination);
    peri = stod(_peri);
    node = stod(_node);
    absTime = findAbsTime(database, datetime);
}