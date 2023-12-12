#pragma once

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <fstream>

#include "block.h"


using namespace std;

class Game {
protected:
    Board aboard;
    Player aPlayer;
    Gach *currBlock, *nextBlock, *shade;
public:
    int menu();
    void inputName();
    void deleteIntro();
    void Introduce();
    int Play(int mode);
    void End(int res);
    void viewScore();
    int draw_Y_N_board(int x, int y, string c);
    void erase_Y_N_board(int x, int y);
};

template <class T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void Sort(vector <Player>& aVector);