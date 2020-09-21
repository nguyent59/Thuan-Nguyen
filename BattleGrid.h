#ifndef FINALPRO_DATA_BATTLEGRID_H
#define FINALPRO_DATA_BATTLEGRID_H
#include <string>
using namespace std;

class BattleGrid {
public:
    void InputLocation(int x, int y, char (*HPBattle)[10][10], char HPGrid[10][10]);
    void InputLocationCP(int x, int y, char (*HPBattle)[10][10], char HPGrid[10][10]);
    void BattlefieldGrid(string filename, char HPBattle[10][10]);
    void Draw(char HPGrid[10][10]);
    bool GameOver(bool gameRunning, char HPGrid[10][10]);
};
#endif
