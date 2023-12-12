#include "board.h"

void Board::drawBoard() {
    noCursor();
	//char a = 205, b = 186;
	char vert = 219;
	char hor_1 = 223, hor_2 = 220;

	textColor(BLACK);

	// above frame and below frame
	for (int i = LEFT_MARGIN; i <= RIGHT_MARGIN; i++)
	{
		textColor(LIGHTCYAN);
		gotoXY(i, TOP_MARGIN);
		cout << hor_1;
		gotoXY(i, BOT_MARGIN);
		cout << hor_2;
	}


	// draw Info frame
	for (int i = RIGHT_MARGIN; i <= RIGHT_MARGIN + 8 * BRICK_COL; i++)
	{
		textColor(LIGHTCYAN);
		gotoXY(i, TOP_MARGIN);						    // line 1
		cout << hor_1;
		gotoXY(i, TOP_MARGIN + 5 * BRICK_ROW);		    // line 2
		cout << hor_1;
		gotoXY(i, TOP_MARGIN + 10 * BRICK_ROW + 1);		// line 3
		cout << hor_1;
		gotoXY(i, BOT_MARGIN);						    // line 4
		cout << hor_2;
	}

	// draw 3 cols
	for (int i = TOP_MARGIN; i <= BOT_MARGIN; i++)
	{
		textColor(LIGHTCYAN);
		gotoXY(LEFT_MARGIN, i);                     
		cout << vert;
		gotoXY(RIGHT_MARGIN, i);
		cout << vert;
		gotoXY(RIGHT_MARGIN + 1, i);
		cout << vert;
		gotoXY(RIGHT_MARGIN + 8 * BRICK_COL, i);	// info col
		cout << vert;
	}
}
void Board::displayBoard()
	{
		int x = LEFT_MARGIN + 1;

		for (int i = 4; i < BOARD_ROW; i++)		
		{
			for (int j = 0; j < BOARD_COL; j++)
			{
				if (aBoard[i][j].getValue() != 0)
				{
					textColor(aBoard[i][j].getValue());
					aBoard[i][j].drawBrick(x + j * BRICK_COL, i * BRICK_ROW + 1, 35);
				}
				else
				{
					textColor(BLACK);
					aBoard[i][j].drawBrick(x + j * BRICK_COL, i * BRICK_ROW + 1, ' ');
				}
			}
		}
	}


// update board
void Board::update(int row)
{
    for (int i = row; i > 0; i--)
    {
        for (int j = 0; j < BOARD_COL; j++)
        {
            aBoard[i][j].setValue(aBoard[i - 1][j].getValue());
        }
    }
}


// xóa hết dữ liệu trong bảng
void Board::erase()
{
    for (int i = 0; i < BOARD_ROW; i++)
    {
        for (int j = 0; j < BOARD_COL; j++)
        {
            aBoard[i][j].setValue(0);
        }
    }
}

// lấy giá trị viên gạch thứ [row][col] trong bảng
int Board::getValueBrick(int row, int col)
{
    return aBoard[row][col].getValue();
}

// gán value cho viên gạch thứ [row][col] trong bảng
void Board::setValueBrick(int row, int col, int value)
{
    aBoard[row][col].setValue(value);
}

// nhập dữ liệu từ file
void Board::INPUT(ifstream &FileIn)
{
    int temp;
    for (int i = 0; i < BOARD_ROW; i++)
    {
        for (int j = 0; j < BOARD_COL; j++)
        {
            FileIn >> temp;
            aBoard[i][j].setValue(temp);
        }
    }

}