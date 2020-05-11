#include <string>
#include "MeteorData.h"
using namespace std;

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
<<<<<<< HEAD

Meteor_Data::Meteor_Data(string _database, int _meteor_number, string _date, string _time, string _beta_heliocentric, string _solar_longitude, string _excentricity, string _inclination, string _peri, string _node) {
    database = _database;
    meteor_number = _meteor_number;

    date = _date;
    time = _time;
    beta_heliocentric = stod(_beta_heliocentric);
=======
    datetime = _datetime;
    q = stod(_q);
>>>>>>> e8b1e013f1dc39f099116042c85487cd4d71a928
    solar_longitude = stod(_solar_longitude);
    excentricity = stod(_excentricity);
    inclination = stod(_inclination);
    peri = stod(_peri);
    node = stod(_node);
}
