#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "console.h"
#include "board.h"
#define LV1 0
#define LV2 100
#define LV3 200
#define LV4 350
#define LV5 500
#define LV6 1000
using namespace std;
class Player {
private:
    string name;
    int score;
    int level;
public:
    Player();
    int getLevel();
    int getScore();
    string getName();
    void setName(string s);
    void updateScore(int s);
    void saveInfo();
    void restart();
    void Input(ifstream& FileIn);
    void Output(ofstream& FileOut);
};