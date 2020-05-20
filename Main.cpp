#include "MeteorDatabase.h"
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

vector<vector<string>> vectorFile;
string databaseName;
Meteor_Database MeteorInfo;

void output1() {
    for (vector<vector<string>>::iterator it = vectorFile.begin(); it != vectorFile.end(); ++it) {

        if ((*it).empty())continue;
        cout << "Database: " << databaseName << ' ';
        cout << "Meteor number: " << (*it)[0] << ' ';
        cout << "Date and time: " << (*it)[1] << ' ';
        cout << "Solar longitude: " << (*it)[4] << ' ';
        cout << "q: " << (*it)[2] << ' ';
        cout << "Excentricity: " << (*it)[5] << ' ';
        cout << "Peri: " << (*it)[7] << ' ';
        cout << "Node: " << (*it)[8] << ' ';
        cout << "Inclination: " << (*it)[6] << ' ';
        cout << '\n';
    }
}

void output2() {
    for (vector<Meteor_Data>::iterator it = MeteorInfo.meteor_vector.begin(); it != MeteorInfo.meteor_vector.end(); ++it) {
        cout << "Database: " << it->database << ' ';
        cout << "Meteor number: " << it->meteor_number << ' ';
        cout << "Date and time: " << it->datetime << ' ';
        cout << "Solar longitude: " << it->solar_longitude << ' ';
        cout << "q: " << it->q << ' ';
        cout << "Excentricity: " << it->excentricity << ' ';
        cout << "Peri: " << it->peri << ' ';
        cout << "Node: " << it->node << ' ';
        cout << "Inclination: " << it->inclination << ' ';
        cout << '\n';
    }
}

void program()
{
    cout << "Running program...\n";
    cout << "Input database name:\n";
    cin >> databaseName;
    Meteor_Database temp_MeteorFile(databaseName, vectorFile);
    MeteorInfo = temp_MeteorFile;
    cout << "Run complete.\n";
}

void test1()
{
    cout << "Running test...\n";
    program();
    cout << "Outputting...\n";
    output1();
    cout << "Test complete.\n";
}

void test2()
{
    cout << "Running test...\n";
    program();
    cout << "Outputting...\n";
    output2();
    cout << "Test complete.\n";
}

int main()
{
    for (;;) {
        cout << "Enter command:\n";
        string command;
        cin >> command;
        if (command == "test1")test1();
        if (command == "test2")test2();
        if (command == "run")program();
        if (command == "exit") {
            cout << "Quitting...\n";
            break;
        }
        else cout << "Unknown command. Please try again.\n";
    }
    return 0;
}