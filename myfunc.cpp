#include <iostream>
#include <string>
using namespace std;

bool IsValid (int AB, int H, int b, int c, int HR, int BB) {
   if (AB < 200)
       return false;
   else
       return true;
}


string GetInitials(string name){

    string fName = name.substr(0,1);
    string  lName = name.substr(name.size() -1,1);
    string  result = ""+ fName + lName ;
    return result;

}

string GetLastName(string name){

    int nameC = name.find(',');
    string nameL = name.substr(0 , nameC );
    return nameL;
}

double CalcAVG(int H, int AB) {

    return static_cast<double>(H) / AB;
}

double CalcOBP(int H, int BB, int AB){

    return static_cast <double> (H + BB) / (AB +BB) ;
}

double CalcSLG(int H, int b, int c, int HR, int AB){

    return static_cast <double>  (H + b +  2*c + 3*HR) / AB ;
}
