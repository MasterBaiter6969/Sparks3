#include <string>
using namespace std;

class Meteor_Data {
public:
    string database;
    int meteor_number;
    string datetime;
    double q;
    double solar_longitude;
    double excentricity;
    double inclination;
    double peri;
    double node;
    double absTime;

    Meteor_Data(string _database, string _meteor_number, string _datetime, string _q, string _solar_longitude, string _excentricity, string _inclination, string _peri, string _node);
};
