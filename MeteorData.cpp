#include <string>
#include "MeteorData.h"
using namespace std;

<<<<<<< HEAD
Meteor_Data::Meteor_Data(string _database, int _meteor_number, string _date, string _time, string _beta_heliocentric, string _solar_longitude, string _excentricity, string _inclination, string _peri, string _node) {
    database = _database;
    meteor_number = _meteor_number;
    date = _date;
    time = _time;
    beta_heliocentric = stod(_beta_heliocentric);
    solar_longitude = stod(_solar_longitude);
    excentricity = stod(_excentricity);
    inclination = stod(_inclination);
    peri = stod(_peri);
    node = stod(_node);
}
=======
Meteor_Data :: Meteor_Data(string _database, int _meteor_number, string _date, string _time, string _beta_heliocentric, string _solar_longitude, string _excentricity, string _inclination, string _peri, string _node){
  database = _database;
  meteor_number = _meteor_number;
  date = _date;
  time = _time;
  beta_heliocentric = stod(_beta_heliocentric);
  solar_longitude = stod(_solar_longitude);
  excentricity = stod(_excentricity);
  inclination = stod(_inclination);
  peri = stod(_peri);
  node = stod(_node);
}
>>>>>>> 152432ed337cd0ed0b750e2ff651a0d2a08b8081
