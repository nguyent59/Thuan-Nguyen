#include <iostream>
#include "BattleGrid.h"

using namespace std;

const int NUM_ROW = 10;
const int NUM_COL = 10;
const int NUM_PLAYER =2;
int main(int argc, const char* argv[]) {
//This is the Battle Grid of Human Player and Computer Player
    BattleGrid HP;
    BattleGrid CP;
    char HPBattle[NUM_ROW][NUM_COL];
    char CPBattle[NUM_ROW][NUM_COL];
    char HPGrid[NUM_ROW][NUM_COL];
    char CPGrid[NUM_ROW][NUM_COL];
    for (int i=0; i <NUM_PLAYER; i++) {
        string fileName;
        cout <<"\033[1;34m         "<< "PLAYER'S BATTLE GRID!" <<"\033[0m"<< endl;
        //Ask for the name of the reading file
        cout << endl;
        cout << "Enter the filename"<< endl;
        cin >> fileName;
        if (i==0) { // Ask for the Battle Grid of HP.
            cout <<"\033[1;35m"<< "This is the Battle Grid of Human Player:" <<"\033[0m"<< endl;
            HP.BattlefieldGrid(fileName,  HPBattle);
        }
        else if (i==1){ // Ask for the Battle Grid of CP.
            cout <<"\033[1;35m"<< "This is the Battle Grid of Computer Player:" <<"\033[0m"<< endl;
            CP.BattlefieldGrid(fileName,  CPBattle);
        }
        cin.ignore();
    }


// The game begin
    int x, y;
    cout << endl<< endl;
    cout <<"\033[1;34m         "<< "NOW THE GAME BEGIN!" <<"\033[0m"<< endl;
    cout << endl;
    bool gameOver = false;
        while(gameOver == false){
        for (int i = 0; i < NUM_PLAYER; i++) {
            //Ask for the name of the reading file
            cout << endl;

            if (i == 0) { // The Firing Grid and Fire attack of Computer player
                cout << "\033[1;32m"<<"      Computer Player turn"<< "\033[0m"<< endl;
                HP.InputLocationCP(x, y, &HPBattle, HPGrid); // auto input and compare to indicate 'X' or 'O'
                cout << "\033[1;35m" << "This is the Firing Grid of Computer Player after attack:" << "\033[0m" << endl;
                HP.Draw(HPGrid);// show the firing grid of CP
                HP.GameOver(gameOver,HPGrid);// check the game CP is win yet
                if (HP.GameOver(gameOver,HPGrid) == true){
                    cout <<"You sunk my battleship!" << endl;
                    cout <<"\033[1;31m"<< "Computer Player win the game!"<< "\033[0m"<< endl;
                    gameOver= true;
                    break;
                }

            } else if (i == 1) { // The Firing Grid and Fire attack of Human player
                cout <<"\033[1;32m" <<"      Human Player turn" << "\033[0m" << endl<<endl;
                cout << "What is the location do you wanna attack:" << endl;
                cout << "For the rows: A-0, B-1, C-2, D-3, E-4, F-5, G-6, H-7, I-8, J-9" << endl;
                cout << endl;
                CP.Draw(CPGrid); // show the firing grid of HP (help the player know where they are)
                CP.InputLocation(x, y, &CPBattle, CPGrid); // ask for input and compare to indicate 'X' or 'O'
                cout << "\033[1;35m" << "This is the Firing Grid of Human Player after attack:" << "\033[0m" << endl;
                CP.Draw(CPGrid); // show the firing grid of HP
                CP.GameOver(gameOver,CPGrid);// check the game HP is win yet
                if (CP.GameOver(gameOver,CPGrid) == true){ // indicate the loop stop yet
                    cout <<"\033[1;31m"<< "Human Player win the game!"<< "\033[0m"<< endl;
                    gameOver= true;
                    break;
                }
            }
            cin.ignore();
        }


    }


    return 0;
}