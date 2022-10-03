#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

//Info needed for each space of board
struct space
{
	int spaceNum;
	char spaceSymbol;
};

//Sets up the game initial values
void gameSetup(bool twoPlayer, char symbol, char symbol2, bool comPlayer,
	int spaces[], int spaces2[], struct space *board, const int SIZE,
	const int TOTALSPACES);

#endif