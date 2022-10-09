#include <stdio.h>
#include <stdbool.h>
#include "tic-tac-toe.h"

//size of gameboard constants for arrays
const int BOARDSIZE = 30;
const int NUMSPACE = (BOARDSIZE/3) - 1;
const int NUMPLAYER = 2;

int main(int argc, char *argv[])
{
/**************************VARIABLES*************************/
	//Flag for detecting two human players
	bool twoPlayer = false;
	//Human player selected symbols
	char playerSymbol = 0;
	char playerSymbol2 = 0;
	//Flag for detecting if computer will play
	bool comActive = false;
	//Scores
	int score[NUMPLAYER];
	//Game board information
	char board[BOARDSIZE][BOARDSIZE];
	//Human players selected spaces
	bool playerSpaces[NUMSPACE];
	bool playerSpaces2[NUMSPACE];

/************************START******************************/

	gameSetup(&twoPlayer, &playerSymbol, &playerSymbol2,
		&comActive, score, playerSpaces, playerSpaces2,
		board);

	drawBoard(twoPlayer, playerSymbol, playerSymbol2, score,
		playerSpaces, playerSpaces2, board);

	return 0;
}