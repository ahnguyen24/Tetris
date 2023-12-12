#pragma once
#include "brick.h"
#include "board.h"
#include "player.h"
#include <vector>
#include <time.h>

using namespace std;

class Gach {
private:
    vector<vector<Brick>> Block;
    int Brow;                       // so hang cua khoi gach
    int Bcol;                       // so cot cua khoi gach
    int xFirstBrick;                // toa do x cua vien dau
    int yFirstBrick;                // toa do y cua vien dau
public:
    int getX_FB();                  // lay toa do x
    void setX_FB(int x);                 // dat toa do x
    int getY_FB();                  // lay toa do y
    void setY_FB(int y);                 // dat toa do y
    Gach();                         // constructor
    ~Gach();                        // destructor
    
    void random();                  // tao ngau nhien gach
    void drawBlock();               // ve gach (tu hang thu 5 tro di)
    void eraseBlock();              // xoa gach
    void drawNext(Board& aboard);   // ve vien gach ke tiep
    void eraseNext(Board& aboard);  // xoa Next

    bool checkInside(int row, int col);     // kiem tra 1 o gach co thuoc bang khong
    
    // kiem tra di chuyen
    bool left(int row, int col, Board& aboard);
    bool right(int row, int col, Board& aboard);
    bool down(int row, int col, Board& aboard);
    
    bool leftMove(Board& aboard);
    bool rightMove(Board& aboard);
    bool downMove(Board& aboard);

    void fall(Board& aboard);
    bool rotate(Board& aboard);

    // kiem tra board va game
    void assignBoardValue(Board& aboard);
    void drawShade(Board& aboard);
    int checkGame(Board& aboard, Player& aplayer);
};