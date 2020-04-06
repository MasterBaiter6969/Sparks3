#include <iostream>
<<<<<<< HEAD
#include <fstream>
#include "MeteorDatabase.h"
=======
#include <vector>
#include <fstream>
#include <string>
>>>>>>> 152432ed337cd0ed0b750e2ff651a0d2a08b8081
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) FOR(i, 0, n)

const long long MAXN = 1000001;

using namespace std;

vector<vector<string>> csvfile;
vector<string> vs;
string line;
int databaseSelect; // CAMS = 1, GMN = 2, EDMOND = 3, SONATACO = 4
<<<<<<< HEAD
Meteor_Database MeteorInfo;
=======
>>>>>>> 152432ed337cd0ed0b750e2ff651a0d2a08b8081

void CAMSPushB(int rowNum, int columnNum, string data) {
    switch (columnNum) {

    case 2:
        cout << "Date: " << data << ' ';
        csvfile[rowNum].push_back(data);
        break;

    case 3:
        cout << "Time: " << data << ' ';
        csvfile[rowNum].push_back(data);
        break;

    case 57:
        cout << "Beta_heliocentric: " << data << ' ';
        csvfile[rowNum].push_back(data);
        break;

    case 59:
        cout << "Solar_longitude: " << data << ' ';
        csvfile[rowNum].push_back(data);
        break;

    case 64:
        cout << "Excentricity: " << data << ' ';
        csvfile[rowNum].push_back(data);
        break;

    case 66:
        cout << "Inclination: " << data << ' ';
        csvfile[rowNum].push_back(data);
        break;

    case 68:
        cout << "Peri: " << data << ' ';
        csvfile[rowNum].push_back(data);
        break;

    case 70:
        cout << "Node: " << data << ' ';
        csvfile[rowNum].push_back(data);
        break;

    default:
        break;

    }
}

void CAMSread() {
    ifstream CAMSfile("CAMS_summary_2010to2016.txt");
    if (CAMSfile.is_open() && databaseSelect == 1)
    {
        while (getline(CAMSfile, line))
        {
            size_t prevFound = 0, Found = line.find(';');
            int columnNum = 0;
            int rowNum = stoi(line.substr(prevFound, Found - prevFound));

        cout << "MeteoritNum: " << rowNum << ' ';
        rowNum--;
        csvfile[rowNum].push_back(to_string(rowNum));
    
        while (line.find(";", Found + 1) <= line.size()) {
            prevFound = Found;
            Found = line.find(";", Found + 1);
            string data = line.substr(prevFound + 1, Found - prevFound - 1);

            CAMSPushB(rowNum, columnNum, data);

            columnNum++;
        }
        cout << '\n';

        }
        CAMSfile.close();
    }
    else cout << "Unable to open file";
}

int main()
{
    csvfile.insert(csvfile.begin(), MAXN, vs);
<<<<<<< HEAD
    cout << "Input desired database number (1 for CAMS, 2 for GMN, 3 for EDMOND, 4 for SONATACO):\n";
=======
    cout << "Input desired database number (1 for CAMS, 2 for GMN, 3 for EDMOND, 4 for SONATACO:\n";
>>>>>>> 152432ed337cd0ed0b750e2ff651a0d2a08b8081

    cin >> databaseSelect;

    switch (databaseSelect) {
        case 1:
<<<<<<< HEAD
        {
            CAMSread();
            Meteor_Database temp_MeteorFile("CAMS", csvfile);
            MeteorInfo = temp_MeteorFile;
            break;
        }
        default:
            break;
    }
    return 0;
}
=======
            CAMSread();
            break;
        default:
            break;
    }


    return 0;
}
>>>>>>> 152432ed337cd0ed0b750e2ff651a0d2a08b8081
