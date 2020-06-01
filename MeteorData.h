#include <string>
using namespace std;

class Meteor_Data {
public:
    string database;
    long meteor_number;
    double absTime;
    string datetime;
    double q;
    double solar_longitude;
    double excentricity;
    double inclination;
    double peri;
    double node;

    Meteor_Data(string _database, string _meteor_number, string _datetime, string _q, string _solar_longitude, string _excentricity, string _inclination, string _peri, string _node);
};