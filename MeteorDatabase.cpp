#include "MeteorDatabase.h"

void Meteor_Database::add(Meteor_Data _Meteor_Dat)
{
	meteor_vector.push_back(_Meteor_Dat);
}


Meteor_Database::Meteor_Database(string _database, vector<vector<string>> _csvfile)
{
	database = _database;
	for (int i = 0; i < _csvfile.size(); ++i) {
		string _meteor_number, _date, _time, _beta_heliocentric, _solar_longitude, _excentricity, _inclination, _peri, _node;
		if (database == "CAMS") {
			_meteor_number = _csvfile[i][0];
			_date = _csvfile[i][1];
			_time = _csvfile[i][2];
			_beta_heliocentric = _csvfile[i][3];
			_solar_longitude = _csvfile[i][4];
			_excentricity = _csvfile[i][5];
			_inclination = _csvfile[i][6];
			_peri = _csvfile[i][7];
			_node = _csvfile[i][8];
		}
		Meteor_Data _Meteor_Dat(_database, _meteor_number, _date, _time, _beta_heliocentric, _solar_longitude, _excentricity, _inclination, _peri, _node);
		add(_Meteor_Dat);
	}
}

Meteor_Database::Meteor_Database(string _database, vector<vector<string>> _csvfile)
{
	database = _database;
	int n = _csvfile.size();
	for (int i = 0; i < n; ++i) {
		Meteor_Data _Meteor_Dat(_database, stoi(_csvfile[i][0]), _csvfile[i][1], _csvfile[i][2], _csvfile[i][3], _csvfile[i][4], _csvfile[i][5], _csvfile[i][6], _csvfile[i][7], _csvfile[i][8]);
		add(_Meteor_Dat);
	}
}

void Meteor_Database::add(Meteor_Data _Meteor_Dat)
{
	meteor_vector.push_back(_Meteor_Dat);
}
