#pragma once
#include <windows.h>
#include <iostream>
#define BLACK       0
#define BLUE        1
#define GREEN       2
#define CYAN        3
#define RED         4
#define PURPLE      5
#define GRAY        6
#define WHITE       7
#define LIGHTGRAY   8
#define LIGHTBLUE   9
#define LIGHTGREEN  10
#define LIGHTCYAN   11
#define LIGHTRED    12
#define LIGHTPURPLE 13
#define LIGHTYELLOW 14
#define LIGHTWHITE  15

void gotoXY(int x, int y);
void clrscr();
void textColor(int x);
void noCursor();
void resizeConsole(int width, int height);
