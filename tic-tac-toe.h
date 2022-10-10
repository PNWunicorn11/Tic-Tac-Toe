#ifndef _TICTACTOE_H_
#define _TICTACTOE_H_

//size of game board
extern const int BOARDSIZE;
extern const int NUMSPACE;
extern const int NUMPLAYER;

/*
//Info needed for each space of board
typedef struct
{
	int spaceNum;
	char spaceSymbol;
} space;*/

//Sets up the game initial values
void gameSetup(bool *twoPlayer, char *symbol, char *symbol2, int score_num[], 
	bool spaces[], bool spaces2[], char setBoard[][BOARDSIZE]);
//Gets each player (or computer) move
void playerMove(bool twoPlayer, bool spaces[], bool spaces2[]);
//Prints player scores and game board
void drawBoard(bool twoPlayer, char symbol, char symbol2, int score_num[], 
	bool spaces[], bool spaces2[], char printBoard[][BOARDSIZE]);
//Gets input from stdin
int get_answer(void);

#endif