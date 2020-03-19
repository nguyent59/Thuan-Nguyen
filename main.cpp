#include <iostream>

using namespace std;

void PrintGreetings();
void PrintByeBye();
void PrintMenuError();
void PrintCurrentValue(int);
int MenuChoice();
int InputAnotherValue();
int Add(int, int);
int Subtract(int, int);
int Multiply(int, int);
int Divide(int, int);
int Modulo(int, int);
int Sqrt(int);
void ErrorCheck(int &);

int main() {
    PrintGreetings();
    int num = 0;
    while (true) {
        PrintCurrentValue(num);
        int choices = MenuChoice();
        if (choices == 7) {
            PrintByeBye();
            break;
        }
        if (choices ==6){
            num = Sqrt(num);
            continue;
        }
        int another = InputAnotherValue();
        switch (choices) {
            case 1:
                num = Add(num, another);
                break;
            case 2:
                num = Subtract(num, another);
                break;
            case 3:
                num = Multiply(num, another);
                break;
            case 4:
                num = Divide(num, another);
                break;
            case 5:
                num = Modulo(num, another);
                break;
            default:
                PrintMenuError();
                break;
        }
            ErrorCheck(num);

        }
        return 0;
    }