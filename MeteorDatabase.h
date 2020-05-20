#include "MeteorData.h"
#include <iostream>
#include <vector>

using namespace std;

class Meteor_Database {
public:
	string database;
	vector<Meteor_Data> meteor_vector;

	Meteor_Database() {};
	Meteor_Database(string _database, vector<vector<string>> _csvfile);
	void add(Meteor_Data _Meteor_Dat);
};
