#include<string>
using namespace std;

class Meteor_Data {
  public:
    string database; 
    int meteor_number;
    string date;
    string time;
    double beta_heliocentric;
    double solar_longitude;
    double excentricity;
    double inclination;
    double peri;
    double node;

    Meteor_Data(string database, int meteor_number, string date, string time, string beta_heliocentric, string solar_longitude, string excentricity, string inclination, string peri, string node);
    };
