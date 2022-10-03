#include <stdio.h>
#include <stdbool.h>
#include "tic-tac-toe.h"


//size of game board
const int BOARDSIZE = 90;
const int NUMSPACES = BOARDSIZE/10;

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
	//Game board information
	struct space board[BOARDSIZE][BOARDSIZE];
	//Human players selected spaces
	int playerSpaces[NUMSPACES];
	int playerSpaces2[NUMSPACES];

/************************START******************************/

	gameSetup(twoPlayer, playerSymbol, playerSymbol2,
		comActive, playerSpaces, playerSpaces2,
		board, BOARDSIZE, NUMSPACES);

	printf("Hello World!");

	return 0;
}