#include <iostream>
#include <fstream>
#include <iomanip>
#include <climits>
using namespace std;
bool IsValid(int, int, int, int, int, int);
string GetInitials(string);
string GetLastName(string);
double CalcAVG(int, int);
double CalcOBP(int, int, int);
double CalcSLG(int, int, int, int, int);


    int main() {
        int max = INT_MIN;
        int max2= INT_MIN;
        string bestName, pos1, teamName1;
        string bestName1, pos2, teamName2;

        ifstream fin;
        string fileName ;
        cout << "Input a file name:" << endl;
        cin >> fileName;
        fin.open(fileName);
        if (!fin.is_open()) {
            cout << "File open error!";
        }

        while (!fin.eof()) {
            string names, teamName, pos;
            int atBats, hit, dble, triple, hr, bb;
            fin >> names >> teamName >> pos >> atBats >> hit >> dble >> triple >> hr >> bb;
            if (fin.fail()) break;
            if (IsValid(atBats, hit, dble, triple, hr, bb)) {
                //Number of ‘at bats’ (AB)
                //Number of hits (H), and more specifically, double (2B), triple (3B), and home run (HR) among hits.
                //Number of walks (BB)
                cout << GetInitials(names) << " ";
                cout << teamName << " ";
                cout << pos << " ";
                cout << fixed << setprecision(3) << CalcAVG(hit, atBats) << " ";
                cout << fixed << setprecision(3) << CalcOBP(hit, bb, atBats) << " ";
                cout << fixed << setprecision(3) << CalcSLG(hit, dble, triple, hr, atBats) << " ";
                double OPS = CalcOBP(hit, bb, atBats) + CalcSLG(hit, dble, triple, hr, atBats);
                cout << fixed << setprecision(3) << OPS << endl;

                    if (hr > max) {
                        max = hr;
                        bestName = names;
                        pos1 = pos;
                        teamName1 = teamName;
                    }

                    if (OPS > max2) {
                        max2 = OPS;
                        bestName1 = names;
                        pos2 = pos;
                        teamName2 = teamName;
                    }
                }

        }
        fin.close();

                if (max < 0) {
                    if (fin.eof()) {
                        cout << "No valid record found." << endl;
                    }
                } else {
                    cout << "Best player (HR): " << GetLastName(bestName) << ", " << teamName1 << ", " << pos1 << endl;
                    cout << "Best player (OPS): " << GetLastName(bestName1) << ", " << teamName2 << ", " << pos2<< endl;
                }

        return 0;

}