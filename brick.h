#pragma once
#include <iostream>
#include "console.h"
#define BRICK_ROW 2
#define BRICK_COL 3
using namespace std;
class Brick {
private:
    int matrix[BRICK_ROW][BRICK_COL];
    int value;      // = 0  --> k ton tai gach
                    // != 0 --> ton tai gach
public:
    Brick();        // constructor
    int getValue();
    void setValue(int val);
    void drawBrick(int x, int y, char c);
};