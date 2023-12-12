#include "game.h"


int main()
{
	int mode, res;
	Game x;
	int label;

	mode = x.menu();
	// view score
	if (mode == 3)
	{
		do
		{
			x.viewScore();
			while (1)
				if (GetAsyncKeyState(VK_ESCAPE))
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
	}
	x.Introduce();
	res = x.Play(mode);
	x.End(res);
	return 0;
}