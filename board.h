#pragma once
#include "brick.h"
#include "console.h"

#include <fstream>

#define BOARD_ROW       25
#define BOARD_COL       15
#define LEFT_MARGIN     5 * BRICK_COL
#define RIGHT_MARGIN    LEFT_MARGIN + BOARD_COL * BRICK_COL + 1
#define TOP_MARGIN      4 * BRICK_ROW
#define BOT_MARGIN      BOARD_ROW * BRICK_ROW + 1

using namespace std;

class Board {
private:
    Brick aBoard[BOARD_ROW][BOARD_COL];
public:
    void drawBoard();       // ve khung
    void displayBoard();    // in khung
    void update(int row);          // cap nhat lai bang khi co 1+ hang day gach
    void erase();
    int getValueBrick(int row, int col);                // lay value cua vien gach tai vi tri [row][col]
    void setValueBrick(int row, int col, int value);    // set value ...
};