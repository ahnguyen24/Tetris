#include "brick.h"
Brick::Brick() {
    value = 0;
}
int Brick::getValue() {
    return value;
}
void Brick::setValue(int val) {
    value = val;
}
void Brick::drawBrick(int x, int y, char c) {
    gotoXY(x, y);
    for (int i = 0; i < BRICK_ROW; i++)
    {
        for (int j = 0; j < BRICK_COL; j++)
        {
            cout << c;
        }
        y += 1;
        gotoXY(x, y);
    }
}