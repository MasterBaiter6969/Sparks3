#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) FOR(i, 0, n)

const long long MAXN = 500001;

using namespace std;

vector<vector<string>> CAMSfile;
vector<string> vs;

int main()
{
    CAMSfile.insert(CAMSfile.begin(), MAXN, vs);
    string line;
    ifstream csvfile("CAMS_summary_2010to2016.txt");

    if (csvfile.is_open())
    {
        while (getline(csvfile, line))
        {
            size_t prevFound = 0, Found = line.find(';');
            int i = 0;
            int data0 = stoi(line.substr(prevFound, Found - prevFound));

            cout << "MeteoritNum: " << data0 << ' ';
            CAMSfile[data0 - 1].push_back(to_string(data0));

            while (line.find(";", Found + 1) <= line.size()) {
                prevFound = Found;
                Found = line.find(";", Found + 1);
                string data = line.substr(prevFound + 1, Found - prevFound - 1);

                switch (i){
                    case 2:
                        cout << "Date: " << data << ' ';
                        CAMSfile[data0 - 1].push_back(data);
                        break;
                    case 3:
                        cout << "Time: " << data << ' ';
                        CAMSfile[data0 - 1].push_back(data);
                        break;
                    case 57:
                        cout << "Beta_heliocentric: " << data << ' ';
                        CAMSfile[data0 - 1].push_back(data);
                        break;
                    case 59:
                        cout << "Solar_longitude: " << data << ' ';
                        CAMSfile[data0 - 1].push_back(data);
                        break;
                    case 64:
                        cout << "Excentricity: " << data << ' ';
                        CAMSfile[data0 - 1].push_back(data);
                        break;
                    case 66:
                        cout << "Inclination: " << data << ' ';
                        CAMSfile[data0 - 1].push_back(data);
                        break;
                    case 68:
                        cout << "Peri: " << data << ' ';
                        CAMSfile[data0 - 1].push_back(data);
                        break;
                    case 70:
                        cout << "Node: " << data << ' ';
                        CAMSfile[data0 - 1].push_back(data);
                        break;
                    default:
                        break;
                }

                i++;
            }
            cout << '\n';
        }
        csvfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}