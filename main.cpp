#include "game.h"
#include <Windows.h>

int main()
{
	int mode, res;
	Game x;

	mode = x.menu();
	if (mode == 2)
	{
		x.viewInstruction();
		while (true)
			if (GetAsyncKeyState(VK_SPACE))
			{
				gotoXY(1, 1);
				clrscr();
				mode = x.menu();
				break;
			}
	}
	// view score
	if (mode == 3)
	{
		do
		{
		x.viewScore();
		while (true)
			if (GetAsyncKeyState(VK_SPACE))
			{
				gotoXY(1, 1);
				clrscr();
				mode = x.menu();
				break;
			}
		} while (mode == 3);
	}

	if (mode == 4)		// quit
	{
		return 0;
	}

	if (mode == 1)		// new game
	{
		x.inputName();
		x.inGameInstruction();
		res = x.Play();
		clrscr();
		x.End(res);
		Sleep(1000);
	}
	return 0;
}