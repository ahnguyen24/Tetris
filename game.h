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
    int menu();                 // vẽ menu, đồng thời return các mode ở menu
    void inputName();           // vẽ màn hình nhập tên người chơi
    void inGameInstruction();   // vẽ phần hướng dẫn chơi trong game        
    int Play();         // hàm play, sẽ return giá trị res ảnh hưởng đến ending
    void End(int res);          // in ra màn hình ending của game
    void restartGame(int res);  // bắt đầu lại trò chơi
    void viewInstruction();     // mode 2, mở hướng dẫn trò chơi
    void viewScore();           // xem highscore
    int draw_Y_N_board(int x, int y, string c); // vẽ menu chọn Yes/No
    void erase_Y_N_board(int x, int y);         // xoá menu
};

template <class T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void Sort(vector <Player>& aVector);