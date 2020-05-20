#include "MeteorDatabase.h"
#include <algorithm>
#include <fstream>

string  line, fileName;
vector<string> line_seperated;

void parse(string databaseName, vector<vector<string>> vectorFile) {
	size_t prevFound = 0, Found = line.find(';');
	int columnNum = 1;
	int rowNum = stoi(line.substr(prevFound, Found - prevFound));
	rowNum--;
	line_seperated.push_back(to_string(rowNum));
	while (line.find(";", Found + 1) <= line.size()) {
		prevFound = Found;
		Found = line.find(";", Found + 1);
		string data = line.substr(prevFound + 1, Found - prevFound - 1);
		if (databaseName == "CAMS" && (columnNum == 2 || columnNum == 3 || columnNum == 57 || columnNum == 59 || columnNum == 64 || columnNum == 66 || columnNum == 68 || columnNum == 70))line_seperated.push_back(data);
		else if (databaseName == "GMN" && (columnNum == 1 || columnNum == 4 || columnNum == 24 || columnNum == 26 || columnNum == 28 || columnNum == 30 || columnNum == 34))line_seperated.push_back(data);
		else if ((databaseName == "EDMOND" || databaseName == "SonataCo") && (columnNum == 2 || columnNum == 4 || columnNum == 19 || columnNum == 20 || columnNum == 22 || columnNum == 23 || columnNum == 24))line_seperated.push_back(data);
		columnNum++;
	}
	vectorFile.push_back(line_seperated);
}

void fileRead(string databaseName, vector<vector<string>> vectorFile) {
	cout << "Input file name:\n";
	cin >> fileName;
	ifstream file(fileName);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			parse(databaseName, vectorFile);
			line_seperated.clear();
		}
		file.close();
	}
	else cout << "Unable to open input file.\n";
}

void Meteor_Database::add(Meteor_Data _Meteor_Dat)
{
	meteor_vector.push_back(_Meteor_Dat);
}

bool compareTime(Meteor_Data Meteor1, Meteor_Data Meteor2) {
	int Meteor1Time = Meteor1.absTime;
	int Meteor2Time = Meteor2.absTime;
	return (Meteor1Time < Meteor2Time);
}

void sortByTime(vector<Meteor_Data>::iterator meteor_vector_begin, vector<Meteor_Data>::iterator meteor_vector_end) {
	sort(meteor_vector_begin, meteor_vector_end, compareTime);
}

Meteor_Database::Meteor_Database(string _database, vector<vector<string>> _vectorfile)
{
	fileRead(_database, _vectorfile);
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

