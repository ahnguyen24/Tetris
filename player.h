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
    int getLevel();                     // lay level hien tai
    int getScore();                     // lay score hien tai
    string getName();                   // lay ten nguoi choi
    void setName(string s);             // ham dat ten nguoi choi  
    void updateScore(int s);            // ham update lai diem so sau khi co 1(+) hang
    void saveInfo();                    // bang luu thong tin nguoi choi
    void restart();
    void Input(ifstream& FileIn);
    void Output(ofstream& FileOut);
};