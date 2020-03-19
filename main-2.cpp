#include <iostream>
#include <iomanip>
#include <ios>
//#include <cmath>
using namespace std;

int main() {
    string name;
    double farAmount, time;
    double farMeter, farMile, farFeet;
    cout << "Please enter the name of the planet:" << endl;
    cin >> name;
    cout << "How far - in kilometers - is " << name << " from the Sun?" <<endl ;
    cin >> farAmount;
    cout << endl;
    const int KIL_TO_MET = 1000;
    const double KIL_TO_MILE = 0.621371;
    const double KIL_TO_FEET = 3280.84;
    const double SPEED_LIGHT = 299792.458;
    farMeter = farAmount * KIL_TO_MET;
    farMile = farAmount * KIL_TO_MILE;
    farFeet = farAmount * KIL_TO_FEET;
    time = farAmount / (SPEED_LIGHT * 60);
    cout << "Distance from the Sun" << endl;
    cout << endl;
    cout << setw(16) << left << " Planet";
    cout << setw(15) << left << "Kilometers";
    cout << setw(15) << left << "Meters";
    cout << setw(15) << left << "Miles";
    cout << setw(15) << left << "Feet" << endl;

    cout << setfill('-') << setw(77) << "" << endl;

    cout << " " << setfill(' ') << setw(15) << left << name;
    cout << setw(15) << left << scientific << setprecision(3) << farAmount;
    cout << setw(15) << left << scientific << setprecision(3) << farMeter;
    cout << setw(15) << left << scientific << setprecision(3) << farMile;
    cout << setw(15) << left << scientific << setprecision(3) << farFeet << endl;
    cout << setfill('-') << setw(77) << "" << endl;
    cout << endl;
    cout << "It takes " << fixed << setprecision(1) << time << " minutes for light from the Sun to reach " << name
         << endl;
    return 0;
}