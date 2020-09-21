#include <string>
#include <iostream>
#include "BattleGrid.h"
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;
const char isHIT = 'O';
const char isMiss = 'X';
const int NUM_ROW = 10;
const int NUM_COL = 10;
const char isShip = 'S';

void BattleGrid:: BattlefieldGrid(string fileName, char HPBattle[NUM_ROW][NUM_COL]) {

            int dic, x, y;
            ifstream fin;
            string startType, startPos, direction;
            //check the input name of the file
            fin.open(fileName);
            if (!fin.is_open()) {
                cout << "File open error!" << endl;
            }

            while (!fin.eof()) {

                getline(fin, startType, ',');
                getline(fin, startPos, ',');
                getline(fin, direction, '\n');
                if (fin.fail()) break;

            // The direction of the ship
                if (direction.at(1) == 'D') dic = 0;
                if (direction.at(1) == 'U') dic = 1;
                if (direction.at(1) == 'L') dic = 2;
                if (direction.at(1) == 'R') dic = 3;
            // the column location of the ship
                y = startPos.at(1) - 48;
            // the row location of the ship
                switch (startPos.at(0)) {
                    case 'A':
                        x = 0;
                        break;
                    case 'B':
                        x = 1;
                        break;
                    case 'C':
                        x = 2;
                        break;
                    case 'D':
                        x = 3;
                        break;
                    case 'E':
                        x = 4;
                        break;
                    case 'F':
                        x = 5;
                        break;
                    case 'G':
                        x = 6;
                        break;
                    case 'H':
                        x = 7;
                        break;
                    case 'I':
                        x = 8;
                        break;
                    case 'J':
                        x = 9;
                        break;
                    default:
                        x = 10;

                }

                HPBattle[y][x] = isShip;

                if (startType == "Carrier") {
                    for (int i = 0; i < 5; i++) {
                        if (dic == 0) HPBattle[y + i][x] = isShip;
                        if (dic == 1) HPBattle[y - i][x] = isShip;
                        if (dic == 2) HPBattle[y][x - i] = isShip;
                        if (dic == 3) HPBattle[y][x + i] = isShip;
                    }
                } else if (startType == "Battleship") {
                    for (int i = 0; i < 4; i++) {
                        if (dic == 0) HPBattle[y + i][x] = isShip;
                        if (dic == 1) HPBattle[y - i][x] = isShip;
                        if (dic == 2) HPBattle[y][x - i] = isShip;
                        if (dic == 3) HPBattle[y][x + i] = isShip;
                    }
                } else if (startType == "Cruiser") {
                    for (int i = 0; i < 3; i++) {
                        if (dic == 0) HPBattle[y + i][x] = isShip;
                        if (dic == 1) HPBattle[y - i][x] = isShip;
                        if (dic == 2) HPBattle[y][x - i] = isShip;
                        if (dic == 3) HPBattle[y][x + i] = isShip;
                    }
                } else if (startType == "Submarine") {
                    for (int i = 0; i < 3; i++) {
                        if (dic == 0) HPBattle[y + i][x] = isShip;
                        if (dic == 1) HPBattle[y - i][x] = isShip;
                        if (dic == 2) HPBattle[y][x - i] = isShip;
                        if (dic == 3) HPBattle[y][x + i] = isShip;
                    }
                } else if (startType == "Destroyer") {
                    for (int i = 0; i < 2; i++) {
                        if (dic == 0) HPBattle[y + i][x] = isShip;
                        if (dic == 1) HPBattle[y - i][x] = isShip;
                        if (dic == 2) HPBattle[y][x - i] = isShip;
                        if (dic == 3) HPBattle[y][x + i] = isShip;
                    }
                }
            }
            fin.close();
// showing the Battle grid
            cout << "\033[1;31mPLAYER GAME BOARD\033[0m\n";
            cout << "\033[1;31m-------------------------------\033[0m\n";
            cout << " ";
            char data[] = "ABCDEFGHIJ";
            cout << " ";
            for (int w = 0; w < 10; ++w) {
                cout << "\033[1;32m" << " " << data[w] << " \033[0m";

            }
            cout << "\n";

            for (int i = 0; i < NUM_ROW; i++) {
                cout << "\033[1;32m" << setw(2) << i+1 << " \033[0m";
                for (int j = 0; j < NUM_COL; j++) {
                    if (HPBattle[i+1][j] == isShip) cout << "\033[1;34m"<< HPBattle[i+1][j] << "  \033[0m";
                    else {
                        HPBattle[i+1][j] = 'W';
                        cout << HPBattle[i+1][j] << "  ";
                    }
                }
                cout << endl;
            }

        }


//Comparing the fire location of the human player with that location in the Battle Grid to indicate 'X'(miss) or 'O'(hit)
void BattleGrid:: InputLocation(int x, int y, char (*HPBattle)[NUM_ROW][NUM_COL], char HPGrid[NUM_ROW][NUM_COL]) {
    cout << "The value of column:";
    cin >> x;
    cout << "The value of row:";
    cin >> y;
    cout << endl;
    try {
        if (x < 0 || y >= 10)
            throw runtime_error("Invalid x or y");
        if (y < 0 || x >= 10)
            throw runtime_error("Invalid x or y");
    }
    catch (runtime_error &except) {
        cout << except.what() << endl;
        cout << "Cannot input x less than 0 or grater than 10." << endl;
        cout <<"Nothing change in the grid."<< endl;
    }


    if ( (*HPBattle)[x][y] == isShip) {
        HPGrid[x][y] = isHIT;
    }
    else {
        HPGrid[x][y] = isMiss;
    }
}
//Comparing the fire location of the computer player with that location in the Battle Grid to indicate 'X'(miss) or 'O'(hit)
void BattleGrid:: InputLocationCP(int x, int y, char (*HPBattle)[NUM_ROW][NUM_COL], char HPGrid[NUM_ROW][NUM_COL]) {
        x= rand() % 10 +1;
        y= rand() %10;
    cout << "The value of column:";
    cout <<x;
    cout << endl;
    cout << "The value of row:";
    cout << y;
    cout << endl;
    try {
        if (x < 0 || y >= 10)
            throw runtime_error("Invalid x or y");
        if (y < 0 || x >= 10)
            throw runtime_error("Invalid x or y");
    }
    catch (runtime_error &except) {
        cout << except.what() << endl;
        cout << "Cannot input x less than 0 or grater than 10." << endl;
        cout <<"Nothing change in the grid."<< endl;
    }


    if ( (*HPBattle)[x][y] == isShip) {
        HPGrid[x][y] = isHIT;
    }
    else {
        HPGrid[x][y] = isMiss;
    }
    cout <<"Push enter to continues."<< endl;
}
// showing the Firing grid
void BattleGrid::Draw(char HPGrid[NUM_ROW][NUM_COL]) {

    cout << "\033[1;31mPLAYER GAME BOARD\033[0m\n";
    cout << "\033[1;31m-------------------------------\033[0m\n";
    cout << " ";
    char data[] = "ABCDEFGHIJ";
    cout << " ";
    for (int w = 0; w < 10; ++w) {
        cout << "\033[1;32m" << " " << data[w] << " \033[0m";

    }
    cout << "\n";

    for (int i = 0; i < NUM_ROW; i++) {
        cout << "\033[1;32m" << setw(2) << i + 1 << " \033[0m";
        for (int j = 0; j < NUM_COL; j++) {
            if (HPGrid[i+1][j] == isHIT || HPGrid[i+1][j] == isMiss) {
                cout <<"\033[1;34m"<<  HPGrid[i+1][j] << "  \033[0m";
            } else {
                HPGrid[i+1][j] = 'W';
                cout <<  HPGrid[i+1][j] << "  ";
            }

        }
        cout << endl;

    }
}
// check the game.
bool BattleGrid:: GameOver(bool gameRunning, char HPGrid[NUM_ROW][NUM_COL]){
    int count =0;
    for (int i=0; i<NUM_ROW; i++){
        for (int j = 0; j < NUM_COL; j++) {
            if (HPGrid[i+1][j] == isHIT) count++;
        }
    }
    if (count < 17) gameRunning = false;
    else gameRunning = true;

    return gameRunning;
}

