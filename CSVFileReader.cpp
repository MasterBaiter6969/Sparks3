#include <iostream>
#include <fstream>
#include "MeteorDatabase.h"
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

vector<vector<string>> csvfile;
vector<string> line_seperated;
string line;
int databaseSelect; // CAMS = 1, GMN = 2, EDMOND = 3, SONATACO = 4
Meteor_Database MeteorInfo;
<<<<<<< HEAD

void output1() {
    for (vector<vector<string>>::iterator it = csvfile.begin(); it != csvfile.end(); ++it) {

        if ((*it).empty())continue;
        cout << "MeteoriteNum: " << (*it)[0] << ' ';
        cout << "Date: " << (*it)[1] << ' ';
        cout << "Time: " << (*it)[2] << ' ';
        cout << "Beta_heliocentric: " << (*it)[3] << ' ';
        cout << "Solar_longitude: " << (*it)[4] << ' ';
        cout << "Excentricity: " << (*it)[5] << ' ';
        cout << "Inclination: " << (*it)[6] << ' ';
        cout << "Peri: " << (*it)[7] << ' ';
        cout << "Node: " << (*it)[8] << ' ';
        cout << '\n';
    }
}
=======
>>>>>>> 106d8b02e9c987b5d8f16125d30e70aacc95a662

void output2() {
    for (vector<Meteor_Data>::iterator it = MeteorInfo.meteor_vector.begin(); it != MeteorInfo.meteor_vector.end(); ++it) {
        cout << "Database: " << it->database << ' ';
        cout << "MeteorNumber: " << it->meteor_number << ' ';
        cout << "Date: " << it->date << ' ';
        cout << "Time: " << it->time << ' ';
        cout << "Beta Heliocentric: " << it->beta_heliocentric << ' ';
        cout << "Solar longitude: " << it->solar_longitude << ' ';
        cout << "Excentricity: " << it->excentricity << ' ';
        cout << "Inclination: " << it->inclination << ' ';
        cout << "Peri: " << it->peri << ' ';
        cout << "Node: " << it->node << ' ';
        cout << '\n';
    }
}

void parse() {
    size_t prevFound = 0, Found = line.find(';');
    int rowNum = stoi(line.substr(prevFound, Found - prevFound));
    rowNum--;
    line_seperated.push_back(to_string(rowNum));
    while (line.find(";", Found + 1) <= line.size()) {
        prevFound = Found;
        Found = line.find(";", Found + 1);
        string data = line.substr(prevFound + 1, Found - prevFound - 1);
        line_seperated.push_back(data);
    }
    csvfile.push_back(line_seperated);
}

void CAMSread() {
    ifstream CAMSfile("CAMS_summary_2010to2016.txt");
    if (CAMSfile.is_open() && databaseSelect == 1)
    {
        while (getline(CAMSfile, line))
        {
            parse();
            line_seperated.clear();
        }
        CAMSfile.close();
    }
    else cout << "Unable to open input file.\n";
}

<<<<<<< HEAD
void GMNread() {
=======
int main()
{
    csvfile.insert(csvfile.begin(), MAXN, vs);
    cout << "Input desired database number (1 for CAMS, 2 for GMN, 3 for EDMOND, 4 for SONATACO):\n";
>>>>>>> 106d8b02e9c987b5d8f16125d30e70aacc95a662

}

void EDMONDread() {

}

void SONATACOread() {

}

void program()
{
    cout << "Running program...\n";
    cout << "Input desired database number (1 for CAMS, 2 for GMN, 3 for EDMOND, 4 for SONATACO):\n";
    cin >> databaseSelect;
    switch (databaseSelect) {
        case 1:
        {
            CAMSread();
            Meteor_Database temp_MeteorFile("CAMS", csvfile);
            MeteorInfo = temp_MeteorFile;
<<<<<<< HEAD
            break;
        }
        case 2:
        {
            GMNread();
            Meteor_Database temp_MeteorFile("GMN", csvfile);
            MeteorInfo = temp_MeteorFile;
            break;
        }
        case 3:
        {
            EDMONDread();
            Meteor_Database temp_MeteorFile("EDMOND", csvfile);
            MeteorInfo = temp_MeteorFile;
            break;
        }
        case 4:
        {
            SONATACOread();
            Meteor_Database temp_MeteorFile("SONATACO", csvfile);
            MeteorInfo = temp_MeteorFile;
=======
>>>>>>> 106d8b02e9c987b5d8f16125d30e70aacc95a662
            break;
        }
        default:
            break;
    }
<<<<<<< HEAD
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
=======
>>>>>>> 106d8b02e9c987b5d8f16125d30e70aacc95a662
    return 0;
}