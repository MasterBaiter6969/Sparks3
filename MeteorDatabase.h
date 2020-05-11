#include "MeteorData.h"
#include <vector>

using namespace std;

class Meteor_Database {
public:
	string database;
	vector<Meteor_Data> meteor_vector;

	Meteor_Database() {};
	Meteor_Database(string _database, vector<vector<string>> _csvfile);
	void add(Meteor_Data _Meteor_Dat);
  void sortByTime(Meteor_Data* meteor_vector.begin(), Meteor_Data* meteor_vector.end());
  bool compareTime(Meteor_Data Meteor1, Meteor_Data Meteor2);
};
