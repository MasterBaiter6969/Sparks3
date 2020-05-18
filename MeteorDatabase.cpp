#include "MeteorDatabase.h"
#include <iostream>

void Meteor_Database::add(Meteor_Data _Meteor_Dat)
{
	meteor_vector.push_back(_Meteor_Dat);
}

bool compareTime(Meteor_Data Meteor1, Meteor_Data Meteor2) {
	int Meteor1Time = Meteor1.absTime;
	int Meteor2Time = Meteor2.absTime;
	return (Meteor1Time < Meteor2Time);
}

void sortByTime(Meteor_Data* meteor_vector_begin, Meteor_Data* meteor_vector_end) {
	sort(meteor_vector_begin, meteor_vector_end, compareTime);
}

Meteor_Database::Meteor_Database(string _database, vector<vector<string>> _vectorfile)
{
	database = _database;
	for (int i = 0; i < _vectorfile.size(); ++i) {
		string _meteor_number, _datetime, _q, _solar_longitude, _excentricity, _inclination, _peri, _node;
		if (database == "CAMS") {
			_meteor_number = _vectorfile[i][0];
			_datetime = _vectorfile[i][1] + ' ' + _vectorfile[i][2];
			_solar_longitude = _vectorfile[i][3];
			_q = _vectorfile[i][4];
			_excentricity = _vectorfile[i][5];
			_inclination = _vectorfile[i][6];
			_peri = _vectorfile[i][7];
			_node = _vectorfile[i][8];
		}
		else if (database == "GMN") {
			_meteor_number = _vectorfile[i][0];
			_datetime = _vectorfile[i][1];
			_solar_longitude = _vectorfile[i][2];
			_excentricity = _vectorfile[i][3];
			_inclination = _vectorfile[i][4];
			_peri = _vectorfile[i][5];
			_node = _vectorfile[i][6];
			_q = _vectorfile[i][7];
		}
		else if (database == "EDMOND" || database == "SonataCo") {
			_meteor_number = _vectorfile[i][0];
			_datetime = _vectorfile[i][1];
			_solar_longitude = _vectorfile[i][2];
			_q = _vectorfile[i][3];
			_excentricity = _vectorfile[i][4];
			_peri = _vectorfile[i][5];
			_node = _vectorfile[i][6];
			_inclination = _vectorfile[i][7];
		}
		else {
			cout << "Wrong database inputted. Please try again.\n";
		}
		Meteor_Data _Meteor_Dat(_database, _meteor_number, _datetime, _q, _solar_longitude, _excentricity, _inclination, _peri, _node);
		add(_Meteor_Dat);
	}
	sortByTime(meteor_vector.begin(), meteor_vector.end());
}

