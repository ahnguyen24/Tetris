#include "block.h"
int Gach::getX_FB() {
    return xFirstBrick;
}
int Gach::getY_FB() {
    return yFirstBrick;
}
void Gach::setX_FB(int x) {
    xFirstBrick = x;
}
void Gach::setY_FB(int y) {
    yFirstBrick = y;
}
Gach::Gach() {
    Brow = Bcol = 2;
    yFirstBrick = 2;
    xFirstBrick = 5;

    Block.resize(Brow);
    for (int i = 0; i < Brow; ++i)
        Block.at(i).resize(Bcol);
    Block.at(0).at(0).setValue(14);
    Block.at(0).at(1).setValue(6);
    Block.at(1).at(0).setValue(14);
    Block.at(1).at(1).setValue(6);
}
Gach::~Gach() {

}
void Gach::random() {
    int type;
    srand(time(NULL));
    type = 1 + rand() % 7;
    switch (type) {
        case 7: // I brick
            Brow = 4;
            Bcol = 1;
            xFirstBrick = 5;
            yFirstBrick = 0;
            break;
        case 6: // O brick
            Brow = Bcol = 2;
            xFirstBrick = 5;
            yFirstBrick = 2;
            break;
        default:
            Brow = 2;
            Bcol = 3;
            xFirstBrick = 5;
            yFirstBrick = 2;
            break;
    }
    Block.resize(Brow);
    for (int i = 0; i < Brow; ++i)
	Block.at(i).resize(Bcol);
    switch (type) 
    {
        case 1:		// Z Brick
            Block.at(0).at(0).setValue(type); 
            Block.at(0).at(1).setValue(type);
            Block.at(1).at(1).setValue(type); 
            Block.at(1).at(2).setValue(type);
            Block.at(0).at(2).setValue(0); 
            Block.at(1).at(0).setValue(0);
            break;
        case 2:	    // S Brick
            Block.at(0).at(1).setValue(type); 
            Block.at(0).at(2).setValue(type);
            Block.at(1).at(0).setValue(type); 
            Block.at(1).at(1).setValue(type); 
            Block.at(0).at(0).setValue(0); 
            Block.at(1).at(2).setValue(0);
            break;
        case 3:	    // L Brick
            Block.at(0).at(0).setValue(type); 
            Block.at(0).at(1).setValue(type);
            Block.at(0).at(2).setValue(type); 
            Block.at(1).at(0).setValue(type);
            Block.at(1).at(1).setValue(0); 
            Block.at(1).at(2).setValue(0);
            break;    
        case 4:     // J Brick
            Block.at(0).at(0).setValue(type);
            Block.at(0).at(1).setValue(type);
            Block.at(0).at(2).setValue(type);
            Block.at(1).at(2).setValue(type);
            Block.at(1).at(0).setValue(0);
            Block.at(1).at(1).setValue(0);
            break;
        case 5:	    // T Brick
            Block.at(0).at(0).setValue(type); 
            Block.at(0).at(1).setValue(type); 
            Block.at(0).at(2).setValue(type); 
            Block.at(1).at(1).setValue(type);
            Block.at(1).at(0).setValue(0);
            Block.at(1).at(2).setValue(0);
            break;
        case 6:	    // O Brick
            Block.at(0).at(0).setValue(type);
            Block.at(0).at(1).setValue(type);
            Block.at(1).at(0).setValue(type);
            Block.at(1).at(1).setValue(type);
            break;
        case 7:     // I Brick
            Block.at(0).at(0).setValue(type);
            Block.at(1).at(0).setValue(type);
            Block.at(2).at(0).setValue(type);
            Block.at(3).at(0).setValue(type);
            break;
    }
}
void Gach::drawBlock()
{
	int x = LEFT_MARGIN + 1 + xFirstBrick*BRICK_COL;
	int y = yFirstBrick * BRICK_ROW + 1;
	for (int i = 0; i < Brow; i++)
	{
		for (int j = 0; j < Bcol; j++)
		{
			if (Block.at(i).at(j).getValue() != 0 && (yFirstBrick + i) >= 4)
			{
				textColor(Block.at(i).at(j).getValue());
				Block.at(i).at(j).drawBrick(x + j * BRICK_COL, y + i *BRICK_ROW, 35);
			}
		}
	}
}
void Gach::eraseBlock() {
    int x = LEFT_MARGIN + 1 + xFirstBrick * BRICK_COL;
    int y = yFirstBrick * BRICK_ROW + 1;
    for (int i = 0; i < Brow; i++)
    {
        for (int j = 0; j < Bcol; j++)
        {
            if (Block.at(i).at(j).getValue() != 0 && (yFirstBrick + i) >= 4)
            {
                textColor(BLACK);
                Block.at(i).at(j).drawBrick(x + j * BRICK_COL, y + i *BRICK_ROW, ' ');
            }
        }
    }
}
void Gach::drawNext(Board& aboard) {
    textColor(LIGHTBLUE);
    gotoXY(RIGHT_MARGIN + 1 * BRICK_COL, TOP_MARGIN + 1 * BRICK_ROW);
    cout << "NEXT BLOCK : ";
    if (Block[0][0].getValue() == 15) 
        this->rotate(aboard);
    for (int i = 0; i < Brow; i++)
        for (int j = 0; j < Bcol; j++)
            if (Block.at(i).at(j).getValue() != 0) 
            {
                textColor(Block.at(i).at(j).getValue());
                Block.at(i).at(j).drawBrick(RIGHT_MARGIN + (3 + j) * BRICK_COL, TOP_MARGIN + (2 + i) * BRICK_ROW, 35);
            }
    if (Block[0][0].getValue() == 7) this->rotate(aboard);
}
void Gach::eraseNext(Board& aboard) {
    if (Block[0][0].getValue() == 7) 
        this->rotate(aboard);
    textColor(BLACK);
    for (int i = 0; i < Brow; i++)
        for (int j = 0; j < Bcol; j++)
            Block.at(i).at(j).drawBrick(RIGHT_MARGIN + (3 + j) * BRICK_COL, TOP_MARGIN + (2 + i) * BRICK_ROW, ' ');
}
bool Gach::checkInside(int row, int col) {
    return (row >= 0 && row < BOARD_ROW && col >= 0 && col < BOARD_COL);
}
bool Gach::left(int row, int col, Board& aboard) {
    if (checkInside(row, col) && col > 0 && aboard.getValueBrick(row, col - 1) == 0)
	    return true;
    return false;
}
bool Gach::right(int row, int col, Board& aboard) {
	if (checkInside(row, col) && col < BOARD_COL - 1 && aboard.getValueBrick(row, col + 1) == 0)
		return true;
	return false;
}
bool Gach::down(int row, int col, Board& aboard) {
    if (checkInside(row, col) && row < BOARD_ROW - 1 && aboard.getValueBrick(row + 1, col) == 0)
	    return true;
    return false;
}
bool Gach::leftMove(Board& aboard) {
    for (int i = 0; i < Brow; i++)
    {
        for (int j = 0; j < Bcol; j++)
        {
            if (Block[i][j].getValue() != 0)
            {
                if (left(yFirstBrick + i, xFirstBrick + j, aboard) == false)
                    return false;
            }
        }
    }
    xFirstBrick -= 1;
    return true;
}
bool Gach::rightMove(Board& aboard) {
    for (int i = 0; i < Brow; i++)
    {
        for (int j = 0; j < Bcol; j++)
        {
            if (Block[i][j].getValue() != 0)
            {
                if (right(yFirstBrick + i, xFirstBrick + j, aboard) == false)
                    return false;
            }
        }
    }
    xFirstBrick += 1;
    return true;
}
bool Gach::downMove(Board& aboard) {
    for (int i = 0; i < Brow; i++)
    {
        for (int j = 0; j < Bcol; j++)
        {
            if (Block[i][j].getValue() != 0)
            {
                if (down(yFirstBrick + i, xFirstBrick + j, aboard) == false)
                    return false;
            }
        }
    }
    yFirstBrick += 1;
    return true;
}
void Gach::fall(Board& aboard) {
    while (this->downMove(aboard) != false);
}
bool Gach::rotate(Board& aboard) {
    if (Block.at(0).at(0).getValue() == 14)		// no rotation for O brick
        return false;
    int tempRow = Bcol;
    int tempCol = Brow;

    // Check whether the brick can rotate?
    for (int i = 0; i < tempRow; i++)
    {
        for (int j = 0; j < tempCol; j++)
        {
            if (!checkInside(yFirstBrick + i, xFirstBrick + j) ||
                aboard.getValueBrick(yFirstBrick + i, xFirstBrick + j) != 0)
                return false;
        }
    }

    // rotate
    vector<vector<Brick>> temp(this->Block); // copy data from Block to temp

    // update Size
    Bcol = tempCol;
    Brow = tempRow;
    Block.resize(Brow);
    for (int i = 0; i < Brow; i++)
    {
        this->Block.at(i).resize(Bcol);
    }

    // write the data when rotate
    for (int i = 0; i < Bcol; i++)
    {
        for (int j = 0; j < Brow; j++)
        {
            Block[j][Bcol - 1 - i].setValue(temp[i][j].getValue());
        }
    }
    return true;

}

// assign value to board, when the brick can't fall down anymore
void Gach::assignBoardValue(Board& aboard)
{
    for (int i = 0; i < Brow; i++)
    {
        for (int j = 0; j < Bcol; j++)
        {
            if (Block[i][j].getValue() != 0)
            {
                aboard.setValueBrick(yFirstBrick + i, xFirstBrick + j, Block[i][j].getValue());
            }
        }
    }
}

void Gach::drawShade(Board& aboard)
{
    this->fall(aboard);
    textColor(119);

    int x = LEFT_MARGIN + 1 + yFirstBrick*BRICK_COL;
    int y = yFirstBrick * BRICK_ROW + 1;

    for (int i = 0; i < Brow; i++)
    {
        for (int j = 0; j < Bcol; j++)
        {
            if (Block.at(i).at(j).getValue() != 0 && (yFirstBrick + i) >= 4)
            {
                Block.at(i).at(j).drawBrick(x + j * BRICK_COL, y + i * BRICK_ROW, ' ');
            }
        }
    }
}

int Gach::checkGame(Board& aboard, Player& aplayer)
{
    int i, j, count;
    i = Brow - 1;

    if (yFirstBrick < 4)
        return -1;	//Gameover
    if (aplayer.getLevel() >= 8)
        return 1; // win game

    int fullRow = 0;
    do
    {
        count = 0;
        for (j = 0; j < BOARD_COL; j++)
        {
            if (aboard.getValueBrick(yFirstBrick + i,j) != 0)
                count++;
        }

        if (count == BOARD_COL)
        {
            aboard.update(yFirstBrick + i);
            fullRow++;
        }
        else
        {
            i = i - 1;
        }
    } while (i >= 0);
    if (fullRow >= 1)
    {
        Sleep(300);
        aboard.displayBoard();
        aplayer.updateScore(10 * fullRow * fullRow);
    }
    return 2;	//continue
}