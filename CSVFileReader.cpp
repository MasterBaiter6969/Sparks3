#include <iostream>
#include <fstream>
#include "MeteorDatabase.h"
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

vector<vector<string>> vectorFile;
vector<string> line_seperated;
string line, databaseSelect, databaseName;
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

void parse() {
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

void fileRead() {
    cout << "Input file name:\n";
    cin >> databaseName;
    ifstream file(databaseName);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            parse();
            line_seperated.clear();
        }
        file.close();
    }
    else cout << "Unable to open input file.\n";
}

void GMNread() {
}

int main()
{
    csvfile.insert(csvfile.begin(), MAXN, vs);
    cout << "Input desired database number (1 for CAMS, 2 for GMN, 3 for EDMOND, 4 for SONATACO):\n";

}

void EDMONDread() {

}

void SONATACOread() {

}

void program()
{
    cout << "Running program...\n";
    cout << "Input database name:\n";
    cin >> databaseSelect;

    switch (databaseSelect) {
        case 1:
        {
            CAMSread();
            Meteor_Database temp_MeteorFile("CAMS", csvfile);
            MeteorInfo = temp_MeteorFile;

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

            break;
        }
        default:
            break;
    }

    fileRead();
    Meteor_Database temp_MeteorFile(databaseSelect, vectorFile);
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
