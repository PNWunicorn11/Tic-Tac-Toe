#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

//size of game board
extern const int BOARDSIZE;
extern const int NUMSPACE;

//Info needed for each space of board
typedef struct
{
	int spaceNum;
	char spaceSymbol;
} space;

//Sets up the game initial values
void gameSetup(bool twoPlayer, char symbol, char symbol2, bool comPlayer,
	int spaces[], int spaces2[], space board[][BOARDSIZE]);

#endif