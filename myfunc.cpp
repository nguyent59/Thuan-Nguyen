#include <iostream>
#include <cmath>

using namespace std;

void PrintGreetings(){
cout << "+=========================+" << endl;
cout << "|/\\/\\Falcon Calculator/\\/\\|" << endl;
cout << "+=========================+" << endl;
}
void PrintByeBye(){
cout << "Thank you for using Falcon Calculator!" << endl;
}
void PrintMenuError(){
    cout << "The choice is not valid." << endl;
}
void PrintCurrentValue(int value){

    cout <<"Current value: ";
    cout << value << endl;
}
int InputAnotherValue(int other){
    cout << "Input another value: ";
    cin >> other;
}

int MenuChoice(){
    cout << "1) Add    2) Subtract 3) Multiply\n"
            "4) Divide 5) Modulo   6) Square root\n"
            "7) Exit\n"
            "Choose Functionality:" << endl;
    int choice;
    cin >> choice;
    return choice;

    }

int Add(int a, int b) {
    return a + b;
}

int Subtract(int a, int b){
    return a - b;
}
int Multiply(int a, int b){
    return a * b;
}
int Divide(int a, int b) {
    if (b == 0)
        return -1;
    else
        return a / b;
}
int Modulo(int a, int b){
    if (b == 0)
        return -1;
    else
        return a % b;
}
int Sqrt(int a) {
    return sqrt(a);
}
void ErrorCheck(int &number){
    if (number <0 || number > 99999){
        cout << "Calculation Error, resetting..." << endl;
        number=0;
    }
}