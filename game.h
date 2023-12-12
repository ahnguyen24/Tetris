#pragma once

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <fstream>

#include "console.h"
#include "board.h"
#include "brick.h"
#include "block.h"
#include "console.h"
#include "player.h"

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
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void Sort(vector <Player>& aVector)
{
    for (int i = 0; i < aVector.size() - 1; i++)
    {
        for (int j = i + 1; j < aVector.size(); j++)
        {
            if (aVector.at(i).getScore() < aVector.at(j).getScore())
            {
                swap(aVector.at(i), aVector.at(j));
            }
        }
    }
}