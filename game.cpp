#include "game.h"
#include <stdlib.h>

int Game::menu() {
    textColor(LIGHTCYAN);
    cout << "#########################################################" << endl;
    cout << "#                                                       #" << endl;
    cout << "#   TTTTTTTT  EEEEEEE  TTTTTTTT  RRRRR    II   SSSS     #" << endl;
    cout << "#      TT     EE          TT     RR   R   II  SS        #" << endl;
    cout << "#      TT     EEEEEEE     TT     RRRRR    II   SSSS     #" << endl;
    cout << "#      TT     EE          TT     RR  RR   II      SS    #" << endl;
    cout << "#      TT     EEEEEEE     TT     RR   RR  II   SSSS     #" << endl;
    cout << "#                                                       #" << endl;
    cout << "#########################################################" << endl;
    gotoXY(20, 10); cout << "Group 10 22CLC10";

    textColor(LIGHTGRAY);
    int type = 1;
    char c = 175;
    gotoXY(20, 13); cout << "NEW GAME";
    gotoXY(20, 15); cout << "RESUME";
    gotoXY(20, 17); cout << "HIGH SCORE";
    gotoXY(20, 19); cout << "QUIT";
    gotoXY(20, 21); cout << "Press W and S to move.";
    gotoXY(20, 23); cout << "Press Enter to select.";

    noCursor();
    while(1) 
    {
        textColor(LIGHTYELLOW);
        if (GetAsyncKeyState(VK_RETURN))
        {
        	return type;
        }
        if (type == 1)
        {
            gotoXY(15, 13);
            cout << c;
            gotoXY(15, 15);
            cout << ' ';
            gotoXY(15, 17);
            cout << ' ';
            gotoXY(15, 19);
            cout << ' ';
        }
        else if (type == 2)
        {
            gotoXY(15, 13);
            cout << ' ';
            gotoXY(15, 15);
            cout << c;
            gotoXY(15, 17);
            cout << ' ';
            gotoXY(15, 19);
            cout << ' ';
        }
        else if (type == 3)
        {
            gotoXY(15, 13);
            cout << ' ';
            gotoXY(15, 15);
            cout << ' ';
            gotoXY(15, 17);
            cout << c;
            gotoXY(15, 19);
            cout << ' ';
        }
        else if (type == 4)
        {
            gotoXY(15, 13);
            cout << ' ';
            gotoXY(15, 15);
            cout << ' ';
            gotoXY(15, 17);
            cout << ' ';
            gotoXY(15, 19);
            cout << c;
        }
        char d;
        if (_kbhit())
        {
            d = _getch();
            if ((d == 'W' || d == 'w') && type > 1)
            {
                type--;
            }

            else if ((d == 'S' || d == 's') && type < 4)
            {
                type++;
            }

            else if (d == 13)
            {
                return type;
            }
        }
    }
}

void Game::inputName() {
    string name;
    do {
        clrscr();
        char c = 175;
        textColor(LIGHTYELLOW);
        gotoXY(50, 20);
        cout << "Your name : ";
        gotoXY(40, 22);
        cout << c;
        textColor(LIGHTWHITE);
        gotoXY(44, 22);
        fflush(stdin);
        getline(cin, name);
        aPlayer.setName(name);
    }   while (name.size() == 0);
}

void Game::deleteIntro() {
    int y = TOP_MARGIN + 11 * BRICK_ROW;
    for (int i = 0; i < 15; i++)
    {
        gotoXY(RIGHT_MARGIN + 2, y + i);
        cout << "			";
    }
}

void Game::Introduce() {
    clrscr();
    aboard.drawBoard();
    aPlayer.saveInfo();
    textColor(LIGHTRED);
    gotoXY(RIGHT_MARGIN + 1 * BRICK_COL, TOP_MARGIN + 1 * BRICK_ROW);
    cout << "NEXT BLOCK : ";

    textColor(LIGHTGREEN);
    int x = RIGHT_MARGIN + 9;
    int y = TOP_MARGIN + 12 * BRICK_ROW;

    x = RIGHT_MARGIN + 3;
    y = TOP_MARGIN + 11 * BRICK_ROW;

    textColor(LIGHTGREEN);
    gotoXY(x, y);
    cout << "  A   : Move Left";
    gotoXY(x, y + 2);
    cout << "  S   : Move Down";
    gotoXY(x, y + 4);
    cout << "  D   : Move Right";
    gotoXY(x, y + 6);
    cout << "  W   : Rotate";
    gotoXY(x, y + 8);
    cout << "Space : Free fall";
    gotoXY(x, y + 10);
    cout << "  R   : Restart";
    gotoXY(x, y + 12);
    cout << "  P   : Pause/Resume";
    gotoXY(x, y + 14);
    cout << " Esc  : Quit";
}

int Game::Play(int mode) {
    resizeConsole(1200, 700);

    int res;	// final result
    // resume mode
    if (mode == 2)
    {
        ifstream FileIn;
        FileIn.open("Resume.txt");
        aboard.INPUT(FileIn);
        aPlayer.Input(FileIn);
        FileIn.close();
        aboard.displayBoard();

    }

    clock_t Start, End;
    char c;

    srand(time(0));
    currBlock = new Gach;
    nextBlock = new Gach;

    currBlock->random();
    shade = new Gach(*currBlock);

    nextBlock->random();
    nextBlock->drawNext(aboard);

    do {
        aPlayer.saveInfo();
        if (currBlock->getX_FB() >= 4)
        {
            shade->drawShade(aboard);
            currBlock->drawBlock();
        }
        Start = clock();
        do
        {
            if (_kbhit())
            {
                c = toupper(_getch());
                currBlock->eraseBlock();
                shade->eraseBlock();
                shade->setY_FB(currBlock->getY_FB());
                shade->setX_FB(currBlock->getX_FB());
                switch (c)
                {
                case 'W':
                case 'w':
                    if (currBlock->rotate(aboard))
                        shade->rotate(aboard);
                    break;
                case 'A':
                case 'a':
                    currBlock->leftMove(aboard);
                    break;
                case 'D':
                case 'd':
                    currBlock->rightMove(aboard);
                    break;
                case 'S':
                case 's':
                    currBlock->downMove(aboard);
                    break;
                case ' ':
                    currBlock->fall(aboard);
                    break;
                case 'R':
                case 'r':
                    if (this->draw_Y_N_board(LEFT_MARGIN + 6, TOP_MARGIN + 5, " Restart ? "))
                    {
                        aboard.erase();
                        aboard.displayBoard();
                        delete currBlock;
                        currBlock = new Gach;
                        currBlock->random();
                        delete shade;
                        shade = new Gach(*currBlock);
                        aPlayer.restart();
                    }
                    else
                    {
                        this->erase_Y_N_board(LEFT_MARGIN + 6, TOP_MARGIN + 5);
                    }
                    break;
                case 'P':
                    shade->drawShade(aboard);
                    currBlock->drawBlock();
                    while (1)
                    {
                        if (_kbhit())
                        {
                            c = toupper(_getch());
                            if (c == 'P')
                                break;
                        }
                    }
                    break;
                case 27:  // Esc
                    if (this->draw_Y_N_board(LEFT_MARGIN + 6, TOP_MARGIN + 5, "Quit game ? "))
                    {
                        this->erase_Y_N_board(LEFT_MARGIN + 6, TOP_MARGIN + 5);
                        if (this->draw_Y_N_board(LEFT_MARGIN + 6, TOP_MARGIN + 5, "Save game ? "))
                        {
                            ofstream FileSave;
                            FileSave.open("Resume.txt");
                            for (int i = 0; i < BOARD_ROW; i++)
                            {
                                for (int j = 0; j < BOARD_COL; j++)
                                {
                                    FileSave << aboard.getValueBrick(i, j) << " ";
                                }
                            }
                            FileSave << "\n";
                            FileSave << aPlayer.getScore() << " " << aPlayer.getLevel() << " " << aPlayer.getName();
                            FileSave.close();
                            res = 0;
                        }
                        else
                        {
                            res = 0;  // thoát k lưu game
                        }
                        return res;
                    }
                    else
                    {
                        this->erase_Y_N_board(LEFT_MARGIN + 6, TOP_MARGIN + 5);
                    }
                    break;
                }

                shade->setY_FB(currBlock->getY_FB());
                shade->setX_FB(currBlock->getX_FB());

                shade->drawShade(aboard);
                currBlock->drawBlock();
            }
            End = clock();
        } while (float(End - Start) / CLOCKS_PER_SEC < 0.15 + 0.15 / aPlayer.getLevel());


        if (currBlock->downMove(aboard) == false) //ko di chuyen xuong dc
        {
            currBlock->assignBoardValue(aboard);
            aboard.displayBoard();
            res = currBlock->checkGame(aboard, aPlayer);
            if (res == -1 || res == 1)
                break;
            delete currBlock;
            currBlock = nextBlock;
            nextBlock->eraseNext(aboard);
            nextBlock = new Gach;
            nextBlock->random();
            nextBlock->drawNext(aboard);
            delete shade;
            shade = new Gach(*currBlock);
        }
        else
        {
            currBlock->setX_FB(currBlock->getX_FB() - 1);
            currBlock->eraseBlock();
            currBlock->setX_FB(currBlock->getX_FB() + 1);
            currBlock->drawBlock();
        }

    } while (1);

    // input file
    ifstream File;
    File.open("highscore.txt");
    Player temp;
    vector<Player> score;
    while (!File.eof())	
    {
        temp.Input(File);
        score.push_back(temp);
    }
    score.push_back(aPlayer);
    File.close();

    // sort the rank
    Sort(score);

    // output file 
    ofstream FileOutput;
    FileOutput.open("highscore.txt");
    for (int i = 0; i < score.size(); i++)
    {
        score.at(i).Output(FileOutput);
    }
    FileOutput.close();
    return res;
}

void Game::End(int res)
{
	this->deleteIntro();
	textColor(LIGHTYELLOW);
	gotoXY(RIGHT_MARGIN + 9 - 3, TOP_MARGIN + 12 * BRICK_ROW + 3);
	if (res == -1)
		cout << "Game over !!!!!";
	else if (res == 0)
		cout << "See you again !!!!";
	else if (res == 1)
		cout << "You win !!!!";
	Sleep(1000);
}

void Game::viewScore()
{
	clrscr();
	int Score;
	int Level;
	string Name;
	ifstream FileIn;
	FileIn.open("highscore.txt");
	textColor(LIGHTYELLOW);
	clrscr();
	gotoXY(50, 5);
	cout << "HIGHSCORE";
	int i = 0;
	while (!FileIn.eof())
	{
		if ((FileIn >> Score))
		{
			FileIn >> Level;
			getline(FileIn, Name);
			gotoXY(30, 10 + i * 2);
			cout << i + 1 << ".Score : " << Score;
			gotoXY(60, 10 + i * 2);
			cout << "Name : " << Name;
			i++;
			if (i == 10)
				break;
		}
	}
	FileIn.close();
	gotoXY(40, 40);
	cout << "Bam Esc de tro ve menu ";
}

int Game::draw_Y_N_board(int x, int y, string c)
{

	textColor(LIGHTWHITE);
	gotoXY(x + 8, y + 2);
	cout << c;
	char vert = 219;
	char a = 205, b = 186;
	char hor_1 = 223, hor_2 = 220;
	for (int i = 0; i < 24; i++)
	{
		gotoXY(x + i, y);
		cout << hor_1;
		gotoXY(x + i, y + 6);
		cout << hor_2;
	}

	for (int i = 0; i <= 6; i++)
	{
		gotoXY(x, y + i);
		cout << vert;
		gotoXY(x + 24, y + i);
		cout << vert;
	}

	noCursor();
	int check = 1;
	char s;
	while (1)
	{
		if (_kbhit())
		{
			s = _getch();
			if (s == 13)
				return check;
		}
		if (check == 1)
		{
			textColor(LIGHTYELLOW);
			gotoXY(x + 6, y + 4);
			cout << "YES";
			textColor(LIGHTWHITE);
			gotoXY(x + 16, y + 4);
			cout << "NO";
		}
		else
		{
			textColor(LIGHTWHITE);
			gotoXY(x + 6, y + 4);
			cout << "YES";
			textColor(LIGHTYELLOW);
			gotoXY(x + 16, y + 4);
			cout << "NO";
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			check = 0;
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			check = 1;
		}
	}
}
void Game::erase_Y_N_board(int x, int y)
{
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 0; j <= 24; j++)
        {
            gotoXY(x + j, y + i);
            cout << " ";
        }
    }
}

void Sort(vector<Player>& aVector) {
    for (int i = 0; i < aVector.size() - 1; i++)
    {
        for (int j = i + 1; j < aVector.size(); j++)
        {
            if (aVector.at(i).getScore() < aVector.at(j).getScore())
            {
                Swap(aVector.at(i), aVector.at(j));
            }
        }
    }
}
