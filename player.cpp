#include "player.h"

Player::Player() {
    name = "No name";
    score = 0;
    level = 1;
}
int Player::getLevel() {
    return level;
}
int Player::getScore() {
    return score;
}
string Player::getName() {
    return name;
}
void Player::setName(string s) {
    name = s;
}
void Player::updateScore(int s) {
    score += s;
    if (score >= LV6) level = 6;
    else if (score >= LV5) level = 5;
    else if (score >= LV4) level = 4;
    else if (score >= LV3) level = 3;
    else if (score >= LV2) level = 2;
    //else if (score >= LV1) level = 1;
}
void Player::saveInfo() {
    textColor(LIGHTGRAY);
    gotoXY(RIGHT_MARGIN + 4, TOP_MARGIN + 6 * BRICK_ROW);
    cout << "PLAYER: ";
    gotoXY(RIGHT_MARGIN + 4, TOP_MARGIN + 6 * BRICK_ROW + 1);
    cout << name;
    gotoXY(RIGHT_MARGIN + 4, TOP_MARGIN + 7 * BRICK_ROW + 1);
    cout << "Score : ";
    gotoXY(RIGHT_MARGIN + 14, TOP_MARGIN + 8 * BRICK_ROW);
    cout << score;
    gotoXY(RIGHT_MARGIN + 4, TOP_MARGIN + 9 * BRICK_ROW);
    cout << "Level : ";
    gotoXY(RIGHT_MARGIN + 14, TOP_MARGIN + 9 * BRICK_ROW + 1);
    cout << level;
}

void Player::restart() {
    score = 0;
    level = 1;
}

void Player::Input(ifstream& FileIn) {
    FileIn >> level;
    FileIn >> score;
    getline(FileIn, name);
}

void Player::Output(ofstream& FileOut) {
    FileOut << level << " " << score << " " << name << "\n";
}